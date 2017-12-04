#include "calibrationform.h"
#include "ui_calibrationform.h"

CalibrationForm::CalibrationForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalibrationForm)
{
    ui->setupUi(this);
}

CalibrationForm::~CalibrationForm()
{
    delete ui;
}
