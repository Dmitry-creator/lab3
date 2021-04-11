#include "mainwindow.h"
#include <QTranslator>
#include <QApplication>
#include <QAction>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        QTranslator t;
        t.load(":/lab3_ru_RU.qm");
        a.installTranslator(&t);
    MainWindow w;
    w.show();
    return a.exec();
}
