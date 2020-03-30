/*
 * Created: 12/28/09-09:38:47
 * Author: Sascha
 */
#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("STM Software");
    QCoreApplication::setApplicationName("Countdown Timer");
    MainWindow w;
    w.show();
    return a.exec();
}
