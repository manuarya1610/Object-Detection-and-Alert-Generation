#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QIcon(":/Background/Background/logo.png");
    QSplashScreen *splash = new QSplashScreen;
    splash -> setPixmap(QPixmap(":/Background/Background/Splash_Screen.png"));
    splash -> show();
    MainWindow w;
    QTimer::singleShot(3000,splash,SLOT(close()));
    QTimer::singleShot(2000, &w, SLOT(show()));
    MainWindow cTest;
    cTest.Connect();
    return a.exec();
}
