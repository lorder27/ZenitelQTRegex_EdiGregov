#include <QCoreApplication>
//#include<QRegularExpression>
//#include <qtextstream.h>
//#include <QIODevice>
//#include <QFile>
#include <QDebug>
#include <QtCore>
#include <QThread>
#include <iostream>

//#include "parser.h"
#include "threading.h"

using namespace Qt;

int main(int argc, char** argv)
{
    QCoreApplication a(argc, argv);

    Threading threadSecondary;

    threadSecondary.start();
    threadSecondary.wait();

    if (!threadSecondary.rezultat.empty())
    {
    for (QList<QString>::iterator Itt = threadSecondary.rezultat.begin(); Itt != threadSecondary.rezultat.end(); Itt++)
                  {
                        qDebug() << " " << *Itt;  /* and it would display the contents in a terminal if any were found. */
                  }
    }
    else
    {
        qDebug() << "No valid matches or missing file.";
    }
    return a.exec();
}

