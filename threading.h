#ifndef THREADING_H
#define THREADING_H

#include <QtCore>
#include "parser.h"


class Threading : public QThread
{
public:
    Threading();
    void run();
    QStringList rezultat;

private:

};

#endif // THREADING_H
