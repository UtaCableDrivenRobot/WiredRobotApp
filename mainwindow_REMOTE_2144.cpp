#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QtDebug>
#include "QMessageBox"
#include <QDialog>
#include<QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateComboBox();
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

void MainWindow::on_pushToEndBtn_clicked()
{
    coordinate* formData = getCoordinateField();
    if(formData)
    {
        if(!myModel.pushNewPoint(
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
    qDebug() << index;
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
        qDebug() << "didn't clear ok logic";
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

}

void MainWindow::on_actionSave_triggered()
{

}


void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                tr("Save Trajectory"), "/home/untitled.txt", tr("XML Files (*.XML);; Text files (*.txt)"));
    qDebug()<<"testS";
    myModel.writeToFile(fileName);
    return;

}






