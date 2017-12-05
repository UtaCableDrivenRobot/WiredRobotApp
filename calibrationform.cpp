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
