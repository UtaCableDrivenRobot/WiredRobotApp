#include "teensyapi.h"
#include <math.h>
#define STEP_SIZE 0.475 // This is MM/Step?
#include <QtSerialPort/QSerialPort>
#include <QDataStream>
#include <QDebug>
#include <thread>
#include <chrono>
#include <QSerialPortInfo>
#include <QMessageBox>

TeensyAPI::TeensyAPI()
{
    // Assume the first port is for the teensy. Maybe make a selector later.
    QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
    if(portList.size()>0)
    {
        qDebug() << "port name:";
        qDebug() << portList[0].portName();
        portName = portList[0].portName();
    }
    else
    {
        qDebug() << "WARNING NO PORT FOUND!!";
        portName = "";
    }
}

bool TeensyAPI::foundPort()
{
    return portName=="" ? false:true;
}


void TeensyAPI::sendTeensyCoordinates(std::vector<std::vector<float>> wireLengthMMList)
{
    //__________________________________________________
    //If we only send one coordinate don't do anything
    //___________________________________________________
    if(wireLengthMMList.size()==1) return;


    //________________________________________________________________________________________
    // Need to convert all the length in mm of the wires to step distances.
    //________________________________________________________________________________________

    std::vector<std::vector<float>> wireLengthsStepList;
    for(std::vector<float> singleWireLengthPosition: wireLengthMMList)
    {
        std::vector<float> singleWireLengthSteps;
        for(float singleLengthMM : singleWireLengthPosition)
        {
            singleWireLengthSteps.push_back(singleLengthMM/STEP_SIZE);
        }
        wireLengthsStepList.push_back(singleWireLengthSteps);
    }

    //________________________________________________________________________________________
    // Convert these steps difference between steps. IE number of steps from 1-2 then from 2-3
    // Need to be careful about the number of steps taken. Don't lose anything in conversion from float to int
    //________________________________________________________________________________________

    std::vector<std::vector<int>> stepDifferences;
    std::vector<float> currentMotorPositions;
    // Starting motor positions based on starting point
    for(int i=0;i<8;i++)
    {
        currentMotorPositions.push_back(wireLengthsStepList[0][i]);
    }
    for(unsigned int listPosition=1;listPosition<wireLengthsStepList.size();listPosition++)
    {
        std::vector<int> singleStepDifference;
        for(int motorNumber=0;motorNumber<8;motorNumber++)
        {
            singleStepDifference.push_back(floor(wireLengthsStepList[listPosition][motorNumber]-currentMotorPositions[motorNumber]));
            currentMotorPositions[motorNumber]+=singleStepDifference[motorNumber];
        }
        stepDifferences.push_back(singleStepDifference);
    }

    QSerialPort port;
    QByteArray exit;
    QDataStream e(&exit, QIODevice::WriteOnly | QIODevice::Append);
    QByteArray packet;
    quint8 header=170,exitCode=180,len,operation,motor,checksum;
    qint32 accel=200, velo=20000, steps;
    e.setByteOrder(QDataStream::BigEndian);
    e<<exitCode;
    port.setPortName(portName);
    port.setBaudRate(QSerialPort::Baud115200);
    port.setParity(QSerialPort::NoParity);
    port.setStopBits(QSerialPort::OneStop);
    port.setFlowControl(QSerialPort::NoFlowControl);

    std::vector <QByteArray> packetSet;
    std::vector<std::vector<QByteArray>> packetMatrix;
    for(unsigned int count=0; count<stepDifferences.size(); count++){
        for(int motorC=0; motorC<8; motorC++){
            QDataStream out(&packet, QIODevice::WriteOnly | QIODevice::Append);
            out.setByteOrder(QDataStream::BigEndian);
            len=17;
            operation=11;
            motor=motorC;
            checksum=0;
            steps=stepDifferences.at(count).at(motorC);
            // quick debug on the last motor.
            qDebug() << stepDifferences.at(count).at(7);
            out << header<<len<<operation<<motor<<accel<<velo<<steps;
            for(int i=0; i<packet.size(); i++){
                checksum=checksum^packet[i];
            }
            out<<checksum;
            packetSet.push_back(packet);
            packet.clear();
        }
        QDataStream out(&packet, QIODevice::WriteOnly | QIODevice::Append);
        out.setByteOrder(QDataStream::BigEndian);
        len=4;
        operation=12;
        checksum=0;
        out << header<<len<<operation;
        for(int i=0; i<packet.size(); i++){
            checksum=checksum^packet[i];
        }
        out<<checksum;
        packetSet.push_back(packet);
        packetMatrix.push_back(packetSet);
        qDebug() << packetSet;
        packet.clear();
        packetSet.clear();
    }
    if(!port.open(QIODevice::ReadWrite)){
        qDebug() << port.errorString();
        qDebug()  << port.portName();
        return;
    }
    for(unsigned int count=0; count<stepDifferences.size(); count++){
        for(int motorC=0; motorC<8; motorC++){
            port.write(packetMatrix.at(count).at(motorC).constData(), 17);
            port.flush();
            while(!port.waitForReadyRead(-1)){
                std::this_thread::sleep_for(std::chrono::milliseconds(5));
            }
            QByteArray ret=port.readAll();
            qDebug()<<ret.toHex().toUpper();
        }

        port.write(packetMatrix.at(count).at(8).constData(), 4);
        port.flush();
        while(!port.waitForReadyRead(-1)){
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        QByteArray ret=port.readAll();
        qDebug()<<ret.toHex().toUpper();
    }
    port.write(exit.constData(), 1);
    port.flush();
    port.close();
    return;
}
