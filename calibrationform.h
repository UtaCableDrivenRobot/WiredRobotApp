#ifndef CALIBRATIONFORM_H
#define CALIBRATIONFORM_H
#include "teensyapi.h"
#include <QDialog>

namespace Ui {
class CalibrationForm;
}

class CalibrationForm : public QDialog
{
    Q_OBJECT

public:
    explicit CalibrationForm(QWidget *parent = 0);
    void setTeensy(TeensyAPI *newTeensy);
    ~CalibrationForm();

private slots:
    void on_motor1Plus_clicked();

    void on_motor2Minus_clicked();

    void on_motor2Plus_clicked();

    void on_motor2Minus_2_clicked();

    void on_motor3Plus_clicked();

    void on_motor3Minus_clicked();

    void on_motor4Plus_clicked();

    void on_motor4Minus_clicked();

    void on_motor5Plus_clicked();

    void on_motor5Minus_clicked();

    void on_motor6Plus_clicked();

    void on_motor6Minus_clicked();

    void on_motor7Plus_clicked();

    void on_motor7Minus_clicked();

    void on_motor8Plus_clicked();

    void on_motor8Minus_clicked();

private:
    Ui::CalibrationForm *ui;
    TeensyAPI *teensy;
};

#endif // CALIBRATIONFORM_H
