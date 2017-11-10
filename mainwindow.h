#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private:
    Ui::MainWindow *ui;
    Model myModel;
    void updateComboBox();
};

#endif // MAINWINDOW_H
