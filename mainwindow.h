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

private:
    Ui::MainWindow *ui;
    Model myModel;
    void updateComboBox(Model model);
};

#endif // MAINWINDOW_H
