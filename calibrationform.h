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

private:
    Ui::CalibrationForm *ui;
    TeensyAPI *teensy;
};

#endif // CALIBRATIONFORM_H
