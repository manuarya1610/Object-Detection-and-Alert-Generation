/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *coco_lineEdit;
    QLineEdit *onnx_lineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QPushButton *_secDialog_close_button;
    QPushButton *COCO;
    QPushButton *ONNX;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(528, 252);
        coco_lineEdit = new QLineEdit(Dialog);
        coco_lineEdit->setObjectName(QString::fromUtf8("coco_lineEdit"));
        coco_lineEdit->setGeometry(QRect(200, 80, 271, 24));
        onnx_lineEdit = new QLineEdit(Dialog);
        onnx_lineEdit->setObjectName(QString::fromUtf8("onnx_lineEdit"));
        onnx_lineEdit->setGeometry(QRect(200, 140, 271, 24));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 80, 201, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 140, 141, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(440, 220, 80, 24));
        QFont font2;
        font2.setFamily(QString::fromUtf8("BEYNO"));
        font2.setPointSize(11);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("background: rgba( 255, 255, 255, 0.3 );\n"
"box-shadow: 0 8px 32px 0 rgba( 31, 38, 135, 0.37 );\n"
"backdrop-filter: blur( 7.5px );\n"
"-webkit-backdrop-filter: blur( 7.5px );\n"
"border: 1px solid rgba( 255, 255, 255, 0.18 );"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(-120, -40, 761, 311));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/Background/Background/Second_Dialog.jpg);"));
        _secDialog_close_button = new QPushButton(Dialog);
        _secDialog_close_button->setObjectName(QString::fromUtf8("_secDialog_close_button"));
        _secDialog_close_button->setEnabled(true);
        _secDialog_close_button->setGeometry(QRect(480, 0, 51, 31));
        _secDialog_close_button->setFocusPolicy(Qt::StrongFocus);
        _secDialog_close_button->setAcceptDrops(false);
        _secDialog_close_button->setAutoFillBackground(false);
        _secDialog_close_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/Icons/cancel (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        _secDialog_close_button->setIcon(icon);
        _secDialog_close_button->setAutoRepeat(false);
        _secDialog_close_button->setAutoRepeatDelay(300);
        _secDialog_close_button->setAutoRepeatInterval(300);
        _secDialog_close_button->setAutoDefault(true);
        _secDialog_close_button->setFlat(true);
        COCO = new QPushButton(Dialog);
        COCO->setObjectName(QString::fromUtf8("COCO"));
        COCO->setGeometry(QRect(480, 80, 21, 24));
        COCO->setStyleSheet(QString::fromUtf8("background: rgba( 255, 255, 255, 0.3 );\n"
"image: url(:/Icons/Icons/open-file-button.png);\n"
"box-shadow: 0 8px 32px 0 rgba( 31, 38, 135, 0.37 );\n"
"backdrop-filter: blur( 7.5px );\n"
"-webkit-backdrop-filter: blur( 7.5px );\n"
"border-radius: 5px;\n"
"border: 1px solid rgba( 255, 255, 255, 0.18 );"));
        ONNX = new QPushButton(Dialog);
        ONNX->setObjectName(QString::fromUtf8("ONNX"));
        ONNX->setGeometry(QRect(480, 140, 21, 24));
        ONNX->setStyleSheet(QString::fromUtf8("background: rgba( 255, 255, 255, 0.3 );\n"
"image: url(:/Icons/Icons/open-file-button.png);\n"
"box-shadow: 0 8px 32px 0 rgba( 31, 38, 135, 0.37 );\n"
"backdrop-filter: blur( 7.5px );\n"
"-webkit-backdrop-filter: blur( 7.5px );\n"
"border-radius: 5px;\n"
"border: 1px solid rgba( 255, 255, 255, 0.18 );"));
        label_3->raise();
        coco_lineEdit->raise();
        onnx_lineEdit->raise();
        label->raise();
        label_2->raise();
        pushButton->raise();
        _secDialog_close_button->raise();
        COCO->raise();
        ONNX->raise();

        retranslateUi(Dialog);
        QObject::connect(_secDialog_close_button, SIGNAL(clicked()), Dialog, SLOT(close()));

        _secDialog_close_button->setDefault(true);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Enter COCO Dataset File:", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Enter ONNX File:", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Ok", nullptr));
        label_3->setText(QString());
        _secDialog_close_button->setText(QString());
#if QT_CONFIG(shortcut)
        _secDialog_close_button->setShortcut(QCoreApplication::translate("Dialog", "P", nullptr));
#endif // QT_CONFIG(shortcut)
        COCO->setText(QString());
        ONNX->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
