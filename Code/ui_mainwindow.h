/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPlay;
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit;
    QPushButton *start_button;
    QLabel *background;
    QPushButton *screenshot;
    QPushButton *close_button;
    QPushButton *minimize_button;
    QLabel *label;
    QCheckBox *filter_truck;
    QLabel *label_filter;
    QCheckBox *filter_car;
    QCheckBox *filter_motorbike;
    QCheckBox *filter_boat;
    QCheckBox *filter_person;
    QPushButton *selectFileButton;
    QLineEdit *uploadUrlLineEdit;
    QLineEdit *fileNameLineEdit;
    QPushButton *uploadButton;
    QProgressBar *progressBar;
    QComboBox *comboBox;
    QLabel *label_2;
    QCheckBox *screenShot_checkBox;
    QComboBox *source_comboBox;
    QPushButton *pushButton_2;
    QCheckBox *TCP_checkBox;
    QCheckBox *FTP_checkBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(918, 659);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Background/Background/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/Icons/3d-cube.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 100, 921, 391));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Century Gothic"));
        graphicsView->setFont(font);
        graphicsView->setStyleSheet(QString::fromUtf8("background: rgba( 14, 13, 13, 0.55 );\n"
"box-shadow: 0 8px 32px 0 rgba( 31, 38, 135, 0.37 );\n"
"backdrop-filter: blur( 20px );\n"
"-webkit-backdrop-filter: blur( 20px );\n"
"border: 1px solid rgba( 255, 255, 255, 0.18 );\n"
"border: opacity(0%);"));
        graphicsView->setFrameShape(QFrame::StyledPanel);
        graphicsView->setFrameShadow(QFrame::Raised);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 50, 581, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft JhengHei Light"));
        font1.setPointSize(9);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("background: rgba( 76, 76, 76, 0.55 );\n"
"color: white;\n"
"box-shadow: 0 8px 32px 0 rgba( 31, 38, 135, 0.37 );\n"
"backdrop-filter: blur( 20px );\n"
"-webkit-backdrop-filter: blur( 20px );\n"
"border: opacity(0%);\n"
""));
        lineEdit->setFrame(false);
        lineEdit->setClearButtonEnabled(true);
        start_button = new QPushButton(centralwidget);
        start_button->setObjectName(QString::fromUtf8("start_button"));
        start_button->setGeometry(QRect(-10, 50, 111, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Gill Sans MT"));
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setUnderline(false);
        start_button->setFont(font2);
        start_button->setMouseTracking(true);
        start_button->setStyleSheet(QString::fromUtf8("background: rgba( 76, 76, 76, 0.55 );\n"
"color: white;\n"
"box-shadow: 0 8px 32px 0 rgba( 31, 38, 135, 0.37 );\n"
"backdrop-filter: blur( 20px );\n"
"-webkit-backdrop-filter: blur( 20px );\n"
"border: 1px solid rgba( 255, 255, 255, 0.18 );\n"
"border: opacity(0%);"));
        start_button->setAutoRepeatDelay(100);
        start_button->setAutoDefault(true);
        start_button->setFlat(true);
        background = new QLabel(centralwidget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(-260, -20, 1341, 781));
        background->setStyleSheet(QString::fromUtf8("image: url(:/Background/Background/Background.png);"));
        screenshot = new QPushButton(centralwidget);
        screenshot->setObjectName(QString::fromUtf8("screenshot"));
        screenshot->setEnabled(true);
        screenshot->setGeometry(QRect(10, 500, 51, 31));
        screenshot->setFont(font);
        screenshot->setStyleSheet(QString::fromUtf8("background: rgba( 76, 76, 76, 0.55 );\n"
"box-shadow: 0 8px 32px 0 rgba( 31, 38, 135, 0.37 );\n"
"backdrop-filter: blur( 20px );\n"
"-webkit-backdrop-filter: blur( 20px );\n"
"border: 1px solid rgba( 255, 255, 255, 0.18 );\n"
"border: opacity(0%);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/Icons/landscapev1.png"), QSize(), QIcon::Normal, QIcon::Off);
        screenshot->setIcon(icon2);
        screenshot->setAutoDefault(true);
        screenshot->setFlat(false);
        close_button = new QPushButton(centralwidget);
        close_button->setObjectName(QString::fromUtf8("close_button"));
        close_button->setEnabled(true);
        close_button->setGeometry(QRect(880, 0, 41, 31));
        close_button->setFocusPolicy(Qt::StrongFocus);
        close_button->setAcceptDrops(false);
        close_button->setAutoFillBackground(false);
        close_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/Icons/cancel (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        close_button->setIcon(icon3);
        close_button->setAutoRepeat(false);
        close_button->setAutoRepeatDelay(300);
        close_button->setAutoRepeatInterval(300);
        close_button->setAutoDefault(true);
        close_button->setFlat(true);
        minimize_button = new QPushButton(centralwidget);
        minimize_button->setObjectName(QString::fromUtf8("minimize_button"));
        minimize_button->setEnabled(true);
        minimize_button->setGeometry(QRect(840, 0, 41, 31));
        minimize_button->setFocusPolicy(Qt::StrongFocus);
        minimize_button->setAcceptDrops(false);
        minimize_button->setAutoFillBackground(false);
        minimize_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/Icons/minimize-sign.png"), QSize(), QIcon::Normal, QIcon::Off);
        minimize_button->setIcon(icon4);
        minimize_button->setAutoRepeat(false);
        minimize_button->setAutoRepeatDelay(300);
        minimize_button->setAutoRepeatInterval(300);
        minimize_button->setAutoDefault(true);
        minimize_button->setFlat(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 220, 211, 131));
        label->setStyleSheet(QString::fromUtf8("image: url(:/Background/Background/logo.png);"));
        filter_truck = new QCheckBox(centralwidget);
        filter_truck->setObjectName(QString::fromUtf8("filter_truck"));
        filter_truck->setGeometry(QRect(610, 500, 61, 22));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Exan"));
        font3.setPointSize(10);
        filter_truck->setFont(font3);
        filter_truck->setStyleSheet(QString::fromUtf8("QCheckBox {color: white;}"));
        filter_truck->setTristate(false);
        label_filter = new QLabel(centralwidget);
        label_filter->setObjectName(QString::fromUtf8("label_filter"));
        label_filter->setGeometry(QRect(330, 500, 191, 20));
        label_filter->setFont(font3);
        label_filter->setStyleSheet(QString::fromUtf8("QLabel {color: white;}"));
        filter_car = new QCheckBox(centralwidget);
        filter_car->setObjectName(QString::fromUtf8("filter_car"));
        filter_car->setGeometry(QRect(690, 500, 51, 22));
        filter_car->setFont(font3);
        filter_car->setStyleSheet(QString::fromUtf8("QCheckBox {color: white;}"));
        filter_car->setTristate(false);
        filter_motorbike = new QCheckBox(centralwidget);
        filter_motorbike->setObjectName(QString::fromUtf8("filter_motorbike"));
        filter_motorbike->setGeometry(QRect(750, 500, 91, 22));
        filter_motorbike->setFont(font3);
        filter_motorbike->setStyleSheet(QString::fromUtf8("QCheckBox {color: white;}"));
        filter_motorbike->setTristate(false);
        filter_boat = new QCheckBox(centralwidget);
        filter_boat->setObjectName(QString::fromUtf8("filter_boat"));
        filter_boat->setGeometry(QRect(850, 500, 61, 22));
        filter_boat->setFont(font3);
        filter_boat->setStyleSheet(QString::fromUtf8("QCheckBox {color: white;}"));
        filter_boat->setTristate(false);
        filter_person = new QCheckBox(centralwidget);
        filter_person->setObjectName(QString::fromUtf8("filter_person"));
        filter_person->setGeometry(QRect(530, 500, 71, 22));
        filter_person->setFont(font3);
        filter_person->setStyleSheet(QString::fromUtf8("QCheckBox {color: white;}"));
        filter_person->setTristate(false);
        selectFileButton = new QPushButton(centralwidget);
        selectFileButton->setObjectName(QString::fromUtf8("selectFileButton"));
        selectFileButton->setGeometry(QRect(0, 560, 125, 24));
        selectFileButton->setStyleSheet(QString::fromUtf8("background: rgba( 76, 76, 76, 0.55 );\n"
"color: white;\n"
"box-shadow: 0 8px 32px 0 rgba( 31, 38, 135, 0.37 );\n"
"backdrop-filter: blur( 20px );\n"
"-webkit-backdrop-filter: blur( 20px );\n"
"border: 1px solid rgba( 255, 255, 255, 0.18 );\n"
"border: opacity(0%);"));
        uploadUrlLineEdit = new QLineEdit(centralwidget);
        uploadUrlLineEdit->setObjectName(QString::fromUtf8("uploadUrlLineEdit"));
        uploadUrlLineEdit->setGeometry(QRect(150, 600, 251, 24));
        uploadUrlLineEdit->setStyleSheet(QString::fromUtf8("background: rgba( 76, 76, 76, 0.55 );\n"
"color: white;\n"
"box-shadow: 0 8px 32px 0 rgba( 31, 38, 135, 0.37 );\n"
"backdrop-filter: blur( 20px );\n"
"-webkit-backdrop-filter: blur( 20px );\n"
"border: 1px solid rgba( 255, 255, 255, 0.18 );\n"
"border: opacity(0%);"));
        fileNameLineEdit = new QLineEdit(centralwidget);
        fileNameLineEdit->setObjectName(QString::fromUtf8("fileNameLineEdit"));
        fileNameLineEdit->setGeometry(QRect(150, 560, 251, 24));
        fileNameLineEdit->setStyleSheet(QString::fromUtf8("background: rgba( 76, 76, 76, 0.55 );\n"
"color: white;\n"
"box-shadow: 0 8px 32px 0 rgba( 31, 38, 135, 0.37 );\n"
"backdrop-filter: blur( 20px );\n"
"-webkit-backdrop-filter: blur( 20px );\n"
"border: 1px solid rgba( 255, 255, 255, 0.18 );\n"
"border: opacity(0%);"));
        fileNameLineEdit->setReadOnly(true);
        uploadButton = new QPushButton(centralwidget);
        uploadButton->setObjectName(QString::fromUtf8("uploadButton"));
        uploadButton->setEnabled(false);
        uploadButton->setGeometry(QRect(790, 630, 125, 24));
        uploadButton->setStyleSheet(QString::fromUtf8("background-color: rgba(10, 0, 0, 0);"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(840, 630, 21, 16));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Centauri"));
        progressBar->setFont(font4);
        progressBar->setStyleSheet(QString::fromUtf8("background-color: dark grey;\n"
"color: white;\n"
"border: opacity(0%);\n"
""));
        progressBar->setValue(0);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(830, 50, 81, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Exan"));
        font5.setPointSize(10);
        font5.setBold(false);
        comboBox->setFont(font5);
        comboBox->setStyleSheet(QString::fromUtf8("background: rgba( 76, 76, 76, 0.55 );\n"
"color: white;\n"
"box-shadow: 0 8px 32px 0 rgba( 31, 38, 135, 0.37 );\n"
"backdrop-filter: blur( 20px );\n"
"-webkit-backdrop-filter: blur( 20px );\n"
"border: 1px solid rgba( 255, 255, 255, 0.18 );\n"
"border: opacity(0%);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 600, 91, 21));
        label_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"border: opacity(0%);\n"
""));
        screenShot_checkBox = new QCheckBox(centralwidget);
        screenShot_checkBox->setObjectName(QString::fromUtf8("screenShot_checkBox"));
        screenShot_checkBox->setEnabled(true);
        screenShot_checkBox->setGeometry(QRect(740, 550, 171, 22));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Verdana"));
        font6.setPointSize(9);
        screenShot_checkBox->setFont(font6);
        screenShot_checkBox->setStyleSheet(QString::fromUtf8("color: white;\n"
""));
        screenShot_checkBox->setChecked(false);
        source_comboBox = new QComboBox(centralwidget);
        source_comboBox->addItem(QString());
        source_comboBox->addItem(QString());
        source_comboBox->addItem(QString());
        source_comboBox->addItem(QString());
        source_comboBox->setObjectName(QString::fromUtf8("source_comboBox"));
        source_comboBox->setGeometry(QRect(740, 50, 81, 31));
        source_comboBox->setFont(font3);
        source_comboBox->setStyleSheet(QString::fromUtf8("background: rgba( 76, 76, 76, 0.55 );\n"
"color: white;\n"
"box-shadow: 0 8px 32px 0 rgba( 31, 38, 135, 0.37 );\n"
"backdrop-filter: blur( 20px );\n"
"-webkit-backdrop-filter: blur( 20px );\n"
"border: 1px solid rgba( 255, 255, 255, 0.18 );\n"
"border: opacity(0%);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 50, 101, 31));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Gill Sans MT"));
        font7.setPointSize(11);
        font7.setBold(false);
        pushButton_2->setFont(font7);
        pushButton_2->setStyleSheet(QString::fromUtf8("background: rgba( 76, 76, 76, 0.55 );\n"
"color: white;\n"
"box-shadow: 0 8px 32px 0 rgba( 31, 38, 135, 0.37 );\n"
"backdrop-filter: blur( 20px );\n"
"-webkit-backdrop-filter: blur( 20px );\n"
"border: 1px solid rgba( 255, 255, 255, 0.18 );\n"
"border: opacity(0%);"));
        TCP_checkBox = new QCheckBox(centralwidget);
        TCP_checkBox->setObjectName(QString::fromUtf8("TCP_checkBox"));
        TCP_checkBox->setGeometry(QRect(740, 570, 131, 22));
        TCP_checkBox->setFont(font6);
        TCP_checkBox->setStyleSheet(QString::fromUtf8("color: white;\n"
"border: opacity(0%);"));
        FTP_checkBox = new QCheckBox(centralwidget);
        FTP_checkBox->setObjectName(QString::fromUtf8("FTP_checkBox"));
        FTP_checkBox->setGeometry(QRect(740, 590, 141, 22));
        FTP_checkBox->setFont(font6);
        FTP_checkBox->setStyleSheet(QString::fromUtf8("color: white;\n"
"border: opacity(0%);\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        progressBar->raise();
        background->raise();
        lineEdit->raise();
        start_button->raise();
        screenshot->raise();
        close_button->raise();
        minimize_button->raise();
        filter_truck->raise();
        label_filter->raise();
        filter_car->raise();
        filter_motorbike->raise();
        filter_boat->raise();
        filter_person->raise();
        selectFileButton->raise();
        uploadUrlLineEdit->raise();
        fileNameLineEdit->raise();
        uploadButton->raise();
        comboBox->raise();
        label_2->raise();
        screenShot_checkBox->raise();
        source_comboBox->raise();
        pushButton_2->raise();
        TCP_checkBox->raise();
        FTP_checkBox->raise();
        label->raise();
        graphicsView->raise();

        retranslateUi(MainWindow);
        QObject::connect(close_button, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(minimize_button, SIGNAL(clicked()), MainWindow, SLOT(showMinimized()));
        QObject::connect(lineEdit, SIGNAL(returnPressed()), start_button, SLOT(click()));

        start_button->setDefault(true);
        screenshot->setDefault(true);
        close_button->setDefault(true);
        minimize_button->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Object Detection", nullptr));
        actionPlay->setText(QCoreApplication::translate("MainWindow", "Player", nullptr));
        actionPlay->setIconText(QCoreApplication::translate("MainWindow", "Player", nullptr));
#if QT_CONFIG(tooltip)
        actionPlay->setToolTip(QCoreApplication::translate("MainWindow", "Player", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter RTSP URL", nullptr));
        start_button->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        background->setText(QString());
        screenshot->setText(QString());
#if QT_CONFIG(shortcut)
        screenshot->setShortcut(QCoreApplication::translate("MainWindow", "S", nullptr));
#endif // QT_CONFIG(shortcut)
        close_button->setText(QString());
#if QT_CONFIG(shortcut)
        close_button->setShortcut(QCoreApplication::translate("MainWindow", "P", nullptr));
#endif // QT_CONFIG(shortcut)
        minimize_button->setText(QString());
#if QT_CONFIG(shortcut)
        minimize_button->setShortcut(QCoreApplication::translate("MainWindow", "P", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QString());
        filter_truck->setText(QCoreApplication::translate("MainWindow", "Truck", nullptr));
        label_filter->setText(QCoreApplication::translate("MainWindow", "Object Detection Filter |", nullptr));
        filter_car->setText(QCoreApplication::translate("MainWindow", "Car", nullptr));
        filter_motorbike->setText(QCoreApplication::translate("MainWindow", "Motorbike", nullptr));
        filter_boat->setText(QCoreApplication::translate("MainWindow", "Boat", nullptr));
        filter_person->setText(QCoreApplication::translate("MainWindow", "Person", nullptr));
        selectFileButton->setText(QCoreApplication::translate("MainWindow", "Set File Path", nullptr));
        uploadUrlLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", " Enter upload url", nullptr));
        fileNameLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "File Path", nullptr));
        uploadButton->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "CPU", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "GPU", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Enter FTP Url :", nullptr));
        screenShot_checkBox->setText(QCoreApplication::translate("MainWindow", "Take Screenshot", nullptr));
        source_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "RTSP", nullptr));
        source_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Video", nullptr));
        source_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Image", nullptr));
        source_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Camera", nullptr));

        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Choose File", nullptr));
        TCP_checkBox->setText(QCoreApplication::translate("MainWindow", "Alert to TCP", nullptr));
        FTP_checkBox->setText(QCoreApplication::translate("MainWindow", "Alert to FTP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
