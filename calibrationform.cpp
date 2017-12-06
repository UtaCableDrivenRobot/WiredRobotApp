#include "calibrationform.h"
#include "ui_calibrationform.h"

CalibrationForm::CalibrationForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalibrationForm)
{
    ui->setupUi(this);
    setWindowTitle("Calibration Dialog");
}

CalibrationForm::~CalibrationForm()
{
    delete ui;
}

void CalibrationForm::setTeensy(TeensyAPI *newTeensy)
{
    teensy = newTeensy;
}

void CalibrationForm::on_motor1Plus_clicked()
{
    quint8 motor=1;
    qint32 steps=10;
    teensy->sendCalibration(motor,steps);


}

void CalibrationForm::on_motor2Minus_clicked()
{
    quint8 motor=1;
    qint32 steps=-10;
    teensy->sendCalibration(motor,steps);

}

void CalibrationForm::on_motor2Plus_clicked()
{
    quint8 motor=2;
    qint32 steps=10;
    teensy->sendCalibration(motor,steps);

}

void CalibrationForm::on_motor2Minus_2_clicked()
{
    quint8 motor=2;
    qint32 steps=-10;
    teensy->sendCalibration(motor,steps);

}

void CalibrationForm::on_motor3Plus_clicked()
{

    quint8 motor=3;
    qint32 steps=10;
    teensy->sendCalibration(motor,steps);
}

void CalibrationForm::on_motor3Minus_clicked()
{
    quint8 motor=3;
    qint32 steps=-10;
    teensy->sendCalibration(motor,steps);

}

void CalibrationForm::on_motor4Plus_clicked()
{
    quint8 motor=4;
    qint32 steps=10;
    teensy->sendCalibration(motor,steps);

}

void CalibrationForm::on_motor4Minus_clicked()
{
    quint8 motor=4;
    qint32 steps=-10;
    teensy->sendCalibration(motor,steps);

}

void CalibrationForm::on_motor5Plus_clicked()
{
    quint8 motor=5;
    qint32 steps=10;
    teensy->sendCalibration(motor,steps);

}

void CalibrationForm::on_motor5Minus_clicked()
{
    quint8 motor=5;
    qint32 steps=-10;
    teensy->sendCalibration(motor,steps);

}

void CalibrationForm::on_motor6Plus_clicked()
{
    quint8 motor=6;
    qint32 steps=10;
    teensy->sendCalibration(motor,steps);

}

void CalibrationForm::on_motor6Minus_clicked()
{
    quint8 motor=6;
    qint32 steps=-10;
    teensy->sendCalibration(motor,steps);

}

void CalibrationForm::on_motor7Plus_clicked()
{
    quint8 motor=7;
    qint32 steps=10;
    teensy->sendCalibration(motor,steps);

}

void CalibrationForm::on_motor7Minus_clicked()
{
    quint8 motor=7;
    qint32 steps=-10;
    teensy->sendCalibration(motor,steps);

}

void CalibrationForm::on_motor8Plus_clicked()
{
    quint8 motor=8;
    qint32 steps=10;
    teensy->sendCalibration(motor,steps);

}

void CalibrationForm::on_motor8Minus_clicked()
{
    quint8 motor=8;
    qint32 steps=-10;
    teensy->sendCalibration(motor,steps);

}
