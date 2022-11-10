#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QNetworkAccessManager>
#include "opencv2/opencv.hpp"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QNetworkReply>
#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QTcpSocket>
#include <QPixmap>
#include <QString>
#include <QDebug>
#include <QImage>
#include <QFile>
#include <iostream>
#include <QMouseEvent>
#include <QPoint>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Connect();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_selectFileButton_clicked();         // Slot for calling the file selection dialog
    void on_uploadButton_clicked();             // Upload slot
    void uploadFinished(QNetworkReply *reply);  // Upload finish slot
    void uploadProgress(qint64 bytesSent, qint64 bytesTotal);  // Upload progress slot
    void on_screenshot_clicked();
    void on_start_button_pressed();
    void on_source_comboBox_activated(int index);
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;

    QTcpSocket *socket;
    QGraphicsPixmapItem pixmap;
    cv::VideoCapture video;
    QNetworkAccessManager *m_manager;
    QString m_fileName;
    // You must save the file on the heap
    // If you create a file object on the stack, the program will crash.
    QFile *m_file;

};

#endif // MAINWINDOW_H
