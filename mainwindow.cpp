#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <QtDebug>
#include "QMessageBox"
#include <QDialog>
#include<QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Wired Robot A");
    updateComboBox();
    ui->glWidget->setModel(&myModel);
    ui->xSlider->setValue(50);
    ui->ySlider->setValue(50);
    if(!teensy.foundPort())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Warning","No Teensy was found durring boot up.\nIn order to run the robotbot, plug in the teensy and restart.");
        messageBox.setFixedSize(500,200);
    }
    calibraiton.setTeensy(&teensy);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateComboBox()
{
    QStringList stringList;
    int position = myModel.getSelectedIndex();
    ui->comboBox->clear();
    int itemNum = myModel.getDataAmount();
    for(int i=0;i<itemNum;i++)
    {
        QString s = QString::number(i);
        QString newItem(s);
        stringList.append(s);
    }
    ui->comboBox->addItems(stringList);
    ui->comboBox->setCurrentIndex(position);
}

void MainWindow::on_insertNextBtn_clicked()
{
    coordinate* formData = getCoordinateField();
    if(formData)
    {
        if(!myModel.insertNewPoint(
                    formData->x,
                    formData->y,
                    formData->z,
                    formData->yaw,
                    formData->pitch,
                    formData->roll,
                    formData->time))
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","New coordinate is out of bounds!");
            messageBox.setFixedSize(500,200);
        }

        updateComboBox();
        delete formData;
    }else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Missing or Incorrect Data!");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::pushNewPointToModel(double x,double y, double z, double yaw,double pitch, double roll, double time)
{
    if(!myModel.pushNewPoint(x,y,z,yaw,pitch,roll,time))
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","New coordinate is out of bounds!");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::on_pushToEndBtn_clicked()
{
    coordinate* formData = getCoordinateField();
    if(formData)
    {
        pushNewPointToModel(
                    formData->x,
                    formData->y,
                    formData->z,
                    formData->yaw,
                    formData->pitch,
                    formData->roll,
                    formData->time);
        updateComboBox();
        delete formData;
    }else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Missing or Incorrect Data!");
        messageBox.setFixedSize(500,200);
    }
}


// Changes the UI to have the correct data at the bottom, and on the image at the right
void MainWindow::updateBottomData()
{
    // Update bottom data
    coordinate selectedCoordinate = myModel.getSelectedCoordinate();
    ui->currentX->setText("X: " + QString::number(selectedCoordinate.x));
    ui->currentY->setText("Y: " + QString::number(selectedCoordinate.y));
    ui->currentZ->setText("Z: " + QString::number(selectedCoordinate.z));
    ui->currentYaw->setText("Yaw: " + QString::number(selectedCoordinate.yaw));
    ui->currentPitch->setText("Pitch: " + QString::number(selectedCoordinate.pitch));
    ui->currentRoll->setText("Roll: " + QString::number(selectedCoordinate.roll));
    ui->currentTime->setText("Time: " + QString::number(selectedCoordinate.time));
}

// Called on all changes to combo box. Make sure when the index is changed it is reflected in all the data
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index==-1)return;
    myModel.setCurrentPoint(index);
    updateBottomData();
}

void MainWindow::on_deletePointBtn_clicked()
{
    if(!myModel.deleteCurrentIdex())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Cannot Delete Starting Point!");
        messageBox.setFixedSize(500,200);
    }
    updateComboBox();
}

coordinate* MainWindow::getCoordinateField()
{
    coordinate* newPoint = new coordinate();
    bool xOk(false), yOk(false), zOk(false), yawOk(false), pitchOk(false), rollOk(false), timeOk(false);
    newPoint->x = ui->xLineEdit->text().toDouble(&xOk);
    newPoint->y = ui->yLineEdit->text().toDouble(&yOk);
    newPoint->z = ui->zLineEdit->text().toDouble(&zOk);
    newPoint->yaw = ui->yawLineEdit->text().toDouble(&yawOk);
    newPoint->pitch = ui->pitchLineEdit->text().toDouble(&pitchOk);
    newPoint->roll = ui->rollLineEdit->text().toDouble(&rollOk);
    newPoint->time = ui->timeSecondsLineEdit->text().toDouble(&timeOk);
    if(!(xOk && yOk && zOk && yawOk && pitchOk && rollOk && timeOk))
    {
        delete newPoint;
        return NULL;
    }
    return newPoint;
}


void MainWindow::on_actionNew_triggered()
{
    //clear working data
    myModel.emptyWorkingPoints();
    updateBottomData();
    updateComboBox();

}
void MainWindow::on_actionOpen_triggered()
{
    int temp=0,count,len,pointCount=0;;
    float a, b,c,yaw,pitch,roll,t=0;
    //get file directory/name
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Trajectory"), "/home", tr("XML Files (*.XML)"));
    myModel.emptyWorkingPoints();
    QFile inputFile(fileName);
    if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text)){ //get number of line in file, store in temp
       QTextStream in(&inputFile);
       while (!in.atEnd()){
          temp++;
          QString line = in.readLine();
       }
       inputFile.close();
    }
    if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text)){
    QTextStream in(&inputFile);
    for(count=0; count<temp-4; count++){
       QString line = in.readLine();
       if(count>5){
           if((count-7)%5==4){ //line that holds time ex: <point time= "3.0">
               line.remove(0,17); //remove tabs and brackets
               len=line.size();
               line.remove(len-2,len-1);//remove tailing brackets
               t=line.toDouble();//save time value
           }
           else if((count-7)%5==0){//line that holds <q> values
               line.remove(0,8); // remove tabs and brackets
               QStringList list = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
               len=list[5].size(); //remove tailing brackets fom time value
               list[5].remove(len-4,len-1);
               a=1000*list[0].toFloat();// convert meters to mm
               b=1000*list[1].toFloat();
               c=1000*list[2].toFloat();
               yaw=list[3].toFloat();
               pitch=list[4].toFloat();
               roll=list[5].toFloat();
               if(pointCount!=0){
                   myModel.pushNewPoint(a,b,c,yaw,pitch,roll, t);
               }
               pointCount++;
           }
       }
    }
    myModel.setCurrentPoint(0);
    inputFile.close();
    //update GUI with values
    updateBottomData();
    updateComboBox();
    return;
}



}

void MainWindow::on_actionSave_triggered()
{
    //empty function for now
}


void MainWindow::on_actionSave_As_triggered()
{
    //get file dir/name
    QString fileName = QFileDialog::getSaveFileName(this,
                tr("Save Trajectory"), "/home", tr("XML Files (*.XML);; Text files (*.txt)"));
    myModel.writeToFile(fileName);
    return;

}

void MainWindow::on_playBtn_clicked()
{
    myModel.setPlay();
}

void MainWindow::on_stopBtn_clicked()
{
    myModel.setStop();
}

void MainWindow::on_actionExport_to_Teensy_triggered()
{
    teensy.sendTeensyCoordinates(myModel.getAllWireLengths());
}


void MainWindow::on_xSlider_valueChanged(int value)
{
    myModel.setEyeRotationX(value);
}

void MainWindow::on_ySlider_valueChanged(int value)
{
    myModel.setEyeRotationY(value);
}

void MainWindow::on_actionCalibrate_Form_triggered()
{
    calibraiton.show();
}

void MainWindow::on_actionImport_CSV_triggered()
{
    myModel.emptyWorkingPoints();
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","File not opened.");
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString newLine = in.readLine();
        QStringList itemList = newLine.split(',');
        qDebug()<< itemList.length();
        if(itemList.length()==7)
        {
            bool xOk(false), yOk(false), zOk(false), yawOk(false), pitchOk(false), rollOk(false), timeOk(false);
            double x = QString(itemList[0]).toDouble(&xOk);
            double y = QString(itemList[1]).toDouble(&yOk);
            double z = QString(itemList[2]).toDouble(&zOk);
            double yaw = QString(itemList[3]).toDouble(&yawOk);
            double pitch = QString(itemList[4]).toDouble(&pitchOk);
            double roll = QString(itemList[5]).toDouble(&rollOk);
            double time = QString(itemList[6]).toDouble(&timeOk);
            if(xOk && yOk && zOk && yawOk && pitchOk && rollOk && timeOk)
            {
                qDebug()<< "pushing new point";
                pushNewPointToModel(x,y,z,yaw,pitch,roll,time);
            }
        }

    }
    updateBottomData();
    updateComboBox();
}
