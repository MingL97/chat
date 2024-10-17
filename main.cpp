#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <qdebug.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/style/stylesheet.qss");
    if(qss.open(QFile::ReadOnly))
    {
        qDebug("open success");
        QString style = QLatin1String(qss.readAll());
        qDebug()<<"style:"<<style;
        a.setStyleSheet(style);
        qss.close();
    }
    else
    {
        qDebug("open false");

    }


    MainWindow w;
    w.show();
    return a.exec();
}
