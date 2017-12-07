#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"
#include "calibrationform.h"
#include "teensyapi.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushToEndBtn_clicked();
    void on_insertNextBtn_clicked();
    void updateBottomData();

    void on_comboBox_currentIndexChanged(int index);

    void on_deletePointBtn_clicked();

    void on_actionSave_As_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_playBtn_clicked();

    void on_stopBtn_clicked();

    void on_actionExport_to_Teensy_triggered();

    void on_xSlider_valueChanged(int value);

    void on_ySlider_valueChanged(int value);

    void on_actionCalibrate_Form_triggered();

    void on_actionImport_CSV_triggered();



private:
    Ui::MainWindow *ui;
    Model myModel;
    void updateComboBox();
    void pushNewPointToModel(double x, double y, double z, double yaw, double pitch, double roll, double time);
    coordinate *getCoordinateField();
    CalibrationForm calibraiton;
    TeensyAPI teensy;
};

#endif // MAINWINDOW_H
