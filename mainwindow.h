#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <iostream>
#include "model.h"

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
    void on_actionLoad_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionNew_triggered();



private:
    Ui::MainWindow *ui;
    Model myModel;
    void saveFile(const QString &fileName);
    void loadFile(const QString &fileName);
    void updateComboBox();

};

#endif // MAINWINDOW_H
