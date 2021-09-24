#include "threading.h"
#include <QCoreApplication>
//#include <QDebug>
#include <QtCore>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    QCoreApplication a(argc, argv);


//Setting the filepath for the file that needs to be read.
    cout << "Input filepath (or filename if in the same folder as the excutable: " << endl;
    QTextStream s(stdin);
    QString path = s.readLine();
    QString resultStr;
//The file path is passed to the Threading class and a separate thread is started.
    Threading threadSecondary;
    threadSecondary.paths = path;
    threadSecondary.start();
//The main thread will wait for the "processing" thread to finish before continuing.
    threadSecondary.wait();

//If there is a regex match in the provided file the values will be stored in the resulStr variable, else an error message will pop up.
    if (!threadSecondary.rezultat.empty()){
        for (QList<QString>::iterator Itt = threadSecondary.rezultat.begin(); Itt != threadSecondary.rezultat.end(); Itt++){
                        resultStr += *Itt + "\n";
    }}
    else{
        cout << "No valid matches or missing file." << endl;
    }
//Dispalys the matched regex values
    if (!threadSecondary.rezultat.empty()){
    cout << endl << "Valid matches: " << endl << endl << resultStr.toStdString();
    }
    return a.exec();
}

