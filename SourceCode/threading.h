#ifndef THREADING_H
#define THREADING_H
#include <QtCore>

class Threading : public QThread
{
public:
    //Threading();
    void run();
    QStringList rezultat;
    QString paths;

private:

};

#endif // THREADING_H
