#include "threading.h"
#include "parser.h"
#include <QtCore>
#include <iostream>

void Threading::run()
{
//Mutex in this case is not needed but in multithreading will protect the variable
//from being overwriten by another method if run at the same time while mutex is locked.
    QMutex mutex;
    mutex.lock();
    //QString filename="test.txt";
    QString filename=paths;
    QFile file(filename);
    if(!file.exists()){
        std::cout << "File does not exist. Please input a valid path or filename if it's in the folder as the executable: "<<filename.toStdString();
    }else{
        std::cout <<"Processing..." << filename.toStdString() << std::endl;
    }


    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        QString line;
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








