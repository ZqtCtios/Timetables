#include "mainwindow.h"
#include <QApplication>
#include <about.h>
#include <addclass.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    About about;
    AddClass add;
    w.show();
    QObject::connect(&w,SIGNAL(openAbout()),&about,SLOT(openAbout()));
    QObject::connect(&w,SIGNAL(openAddClassWighet()),&add,SLOT(open()));
    QObject::connect(&add,SIGNAL(back(QClassMsg)),&w,SLOT(getMsg(QClassMsg)));
    return a.exec();
}
