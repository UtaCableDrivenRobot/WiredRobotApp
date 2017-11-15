/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *top_Area;
    QVBoxLayout *modelAdder;
    QHBoxLayout *dataEdit;
    QFormLayout *formLayout;
    QLabel *xLabel;
    QLineEdit *xLineEdit;
    QLabel *yLabel;
    QLineEdit *yLineEdit;
    QLabel *zLabel;
    QLineEdit *zLineEdit;
    QFormLayout *formLayout_2;
    QLabel *yawLabel;
    QLineEdit *yawLineEdit;
    QLabel *rollLabel;
    QLineEdit *rollLineEdit;
    QLabel *pitchLabel;
    QLineEdit *pitchLineEdit;
    QLabel *timeSecondsLabel;
    QLineEdit *timeSecondsLineEdit;
    QHBoxLayout *modelButtons;
    QSpacerItem *horizontalSpacer;
    QPushButton *insertNextBtn;
    QPushButton *pushToEndBtn;
    QSpacerItem *verticalSpacer;
    QOpenGLWidget *openGLVideo;
    QHBoxLayout *bottom_Area;
    QComboBox *comboBox;
    QLabel *currentX;
    QLabel *currentY;
    QLabel *currentZ;
    QLabel *currentYaw;
    QLabel *currentPitch;
    QLabel *currentRoll;
    QLabel *currentTime;
    QPushButton *deletePointBtn;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(946, 404);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        top_Area = new QHBoxLayout();
        top_Area->setSpacing(6);
        top_Area->setObjectName(QStringLiteral("top_Area"));
        top_Area->setSizeConstraint(QLayout::SetDefaultConstraint);
        modelAdder = new QVBoxLayout();
        modelAdder->setSpacing(6);
        modelAdder->setObjectName(QStringLiteral("modelAdder"));
        modelAdder->setSizeConstraint(QLayout::SetDefaultConstraint);
        dataEdit = new QHBoxLayout();
        dataEdit->setSpacing(6);
        dataEdit->setObjectName(QStringLiteral("dataEdit"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        xLabel = new QLabel(centralWidget);
        xLabel->setObjectName(QStringLiteral("xLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, xLabel);

        xLineEdit = new QLineEdit(centralWidget);
        xLineEdit->setObjectName(QStringLiteral("xLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, xLineEdit);

        yLabel = new QLabel(centralWidget);
        yLabel->setObjectName(QStringLiteral("yLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, yLabel);

        yLineEdit = new QLineEdit(centralWidget);
        yLineEdit->setObjectName(QStringLiteral("yLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, yLineEdit);

        zLabel = new QLabel(centralWidget);
        zLabel->setObjectName(QStringLiteral("zLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, zLabel);

        zLineEdit = new QLineEdit(centralWidget);
        zLineEdit->setObjectName(QStringLiteral("zLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, zLineEdit);


        dataEdit->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        yawLabel = new QLabel(centralWidget);
        yawLabel->setObjectName(QStringLiteral("yawLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, yawLabel);

        yawLineEdit = new QLineEdit(centralWidget);
        yawLineEdit->setObjectName(QStringLiteral("yawLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, yawLineEdit);

        rollLabel = new QLabel(centralWidget);
        rollLabel->setObjectName(QStringLiteral("rollLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, rollLabel);

        rollLineEdit = new QLineEdit(centralWidget);
        rollLineEdit->setObjectName(QStringLiteral("rollLineEdit"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, rollLineEdit);

        pitchLabel = new QLabel(centralWidget);
        pitchLabel->setObjectName(QStringLiteral("pitchLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, pitchLabel);

        pitchLineEdit = new QLineEdit(centralWidget);
        pitchLineEdit->setObjectName(QStringLiteral("pitchLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, pitchLineEdit);

        timeSecondsLabel = new QLabel(centralWidget);
        timeSecondsLabel->setObjectName(QStringLiteral("timeSecondsLabel"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, timeSecondsLabel);

        timeSecondsLineEdit = new QLineEdit(centralWidget);
        timeSecondsLineEdit->setObjectName(QStringLiteral("timeSecondsLineEdit"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, timeSecondsLineEdit);


        dataEdit->addLayout(formLayout_2);


        modelAdder->addLayout(dataEdit);

        modelButtons = new QHBoxLayout();
        modelButtons->setSpacing(6);
        modelButtons->setObjectName(QStringLiteral("modelButtons"));
        horizontalSpacer = new QSpacerItem(100, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        modelButtons->addItem(horizontalSpacer);

        insertNextBtn = new QPushButton(centralWidget);
        insertNextBtn->setObjectName(QStringLiteral("insertNextBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(insertNextBtn->sizePolicy().hasHeightForWidth());
        insertNextBtn->setSizePolicy(sizePolicy);

        modelButtons->addWidget(insertNextBtn);

        pushToEndBtn = new QPushButton(centralWidget);
        pushToEndBtn->setObjectName(QStringLiteral("pushToEndBtn"));
        pushToEndBtn->setEnabled(true);
        sizePolicy.setHeightForWidth(pushToEndBtn->sizePolicy().hasHeightForWidth());
        pushToEndBtn->setSizePolicy(sizePolicy);

        modelButtons->addWidget(pushToEndBtn);


        modelAdder->addLayout(modelButtons);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        modelAdder->addItem(verticalSpacer);


        top_Area->addLayout(modelAdder);

        openGLVideo = new QOpenGLWidget(centralWidget);
        openGLVideo->setObjectName(QStringLiteral("openGLVideo"));
        openGLVideo->setMinimumSize(QSize(400, 300));
        openGLVideo->setMaximumSize(QSize(400, 300));

        top_Area->addWidget(openGLVideo);


        verticalLayout->addLayout(top_Area);

        bottom_Area = new QHBoxLayout();
        bottom_Area->setSpacing(6);
        bottom_Area->setObjectName(QStringLiteral("bottom_Area"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        bottom_Area->addWidget(comboBox);

        currentX = new QLabel(centralWidget);
        currentX->setObjectName(QStringLiteral("currentX"));

        bottom_Area->addWidget(currentX);

        currentY = new QLabel(centralWidget);
        currentY->setObjectName(QStringLiteral("currentY"));

        bottom_Area->addWidget(currentY);

        currentZ = new QLabel(centralWidget);
        currentZ->setObjectName(QStringLiteral("currentZ"));

        bottom_Area->addWidget(currentZ);

        currentYaw = new QLabel(centralWidget);
        currentYaw->setObjectName(QStringLiteral("currentYaw"));

        bottom_Area->addWidget(currentYaw);

        currentPitch = new QLabel(centralWidget);
        currentPitch->setObjectName(QStringLiteral("currentPitch"));

        bottom_Area->addWidget(currentPitch);

        currentRoll = new QLabel(centralWidget);
        currentRoll->setObjectName(QStringLiteral("currentRoll"));

        bottom_Area->addWidget(currentRoll);

        currentTime = new QLabel(centralWidget);
        currentTime->setObjectName(QStringLiteral("currentTime"));

        bottom_Area->addWidget(currentTime);

        deletePointBtn = new QPushButton(centralWidget);
        deletePointBtn->setObjectName(QStringLiteral("deletePointBtn"));

        bottom_Area->addWidget(deletePointBtn);


        verticalLayout->addLayout(bottom_Area);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 946, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(xLineEdit, yLineEdit);
        QWidget::setTabOrder(yLineEdit, zLineEdit);
        QWidget::setTabOrder(zLineEdit, yawLineEdit);
        QWidget::setTabOrder(yawLineEdit, pitchLineEdit);
        QWidget::setTabOrder(pitchLineEdit, rollLineEdit);
        QWidget::setTabOrder(rollLineEdit, timeSecondsLineEdit);
        QWidget::setTabOrder(timeSecondsLineEdit, insertNextBtn);
        QWidget::setTabOrder(insertNextBtn, pushToEndBtn);
        QWidget::setTabOrder(pushToEndBtn, comboBox);
        QWidget::setTabOrder(comboBox, deletePointBtn);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MainWindow", "New", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", Q_NULLPTR));
        xLabel->setText(QApplication::translate("MainWindow", "X:", Q_NULLPTR));
        yLabel->setText(QApplication::translate("MainWindow", "Y:", Q_NULLPTR));
        zLabel->setText(QApplication::translate("MainWindow", "Z:", Q_NULLPTR));
        yawLabel->setText(QApplication::translate("MainWindow", "Yaw:", Q_NULLPTR));
        rollLabel->setText(QApplication::translate("MainWindow", "Roll:", Q_NULLPTR));
        pitchLabel->setText(QApplication::translate("MainWindow", "Pitch:", Q_NULLPTR));
        timeSecondsLabel->setText(QApplication::translate("MainWindow", "Time(Seconds)", Q_NULLPTR));
        insertNextBtn->setText(QApplication::translate("MainWindow", "Insert Next", Q_NULLPTR));
        pushToEndBtn->setText(QApplication::translate("MainWindow", "Push To End", Q_NULLPTR));
        currentX->setText(QApplication::translate("MainWindow", "X: {current.x}", Q_NULLPTR));
        currentY->setText(QApplication::translate("MainWindow", "y: {current.y}", Q_NULLPTR));
        currentZ->setText(QApplication::translate("MainWindow", "z: {current.z}", Q_NULLPTR));
        currentYaw->setText(QApplication::translate("MainWindow", "yaw: {current.yaw}", Q_NULLPTR));
        currentPitch->setText(QApplication::translate("MainWindow", "pitch: {current.pitch}", Q_NULLPTR));
        currentRoll->setText(QApplication::translate("MainWindow", "roll: {current.roll}", Q_NULLPTR));
        currentTime->setText(QApplication::translate("MainWindow", "time: time", Q_NULLPTR));
        deletePointBtn->setText(QApplication::translate("MainWindow", "Delete Point", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
