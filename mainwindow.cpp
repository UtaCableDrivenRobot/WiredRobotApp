#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QtDebug>

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
    // TODO pull the real data. Add logic for could not add warning message.
    myModel.insertNewPoint(30,30,30,30,30,30,30);
    updateComboBox();
}

void MainWindow::on_pushToEndBtn_clicked()
{
     // TODO pull the real data. Add logic for could not add warning message.
    myModel.pushNewPoint(30,30,30,30,30,30,30);
    updateComboBox();
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
    myModel.deleteCurrentIdex();
    updateComboBox();
}
//TODO what are we going to do for new?
void MainWindow::on_actionNew_triggered()
{

}

void MainWindow::on_actionLoad_triggered()
{
    const QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        loadFile(fileName);

}

void MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, tr("Program"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
    }

}
// TODO
void MainWindow::on_actionSave_triggered()
{

}
//
void MainWindow::on_actionSave_As_triggered()
{

    QDir::currentPath();
    //QString fileName = QFileDialog::getSaveFileName(this, tr("save as"), curFile);
}

void MainWindow::saveFile(const QString &fileName)
{

}


