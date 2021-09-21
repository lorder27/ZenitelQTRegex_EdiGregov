#include "threading.h"
#include <QtCore>
#include <QtDebug>

#include "parser.h"

Threading::Threading()
{

}



void Threading::run()
{

    QMutex mutex;
    mutex.lock();
    QString filename="test.txt";
        QFile file(filename);
        if(!file.exists()){
            qDebug() << "File does not exist (Put a 'test.txt' file in the same fodler as the Executable"<<filename;
        }else{
            qDebug() <<"Processing..." << filename;
        }
        QString line;

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream stream(&file);
            while (!stream.atEnd()){
                line = stream.readLine();
                    Parser parser(line);
                    rezultat.append(parser.rezultat2);

            }
        }
        file.close();


    mutex.unlock();
    exit();
}








