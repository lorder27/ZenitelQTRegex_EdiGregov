#include "parser.h"
#include "threading.h"
#include <QDebug>
#include<QRegularExpression>

using namespace Qt;

Parser::Parser(QString input){
    Threading results;
    QRegularExpression re("^((31[\\.](0[13578]|1[02])[\\.](18|19|20)[0-9]{2})|((29|30)[\\.](01|0[3-9]|1[1-2])[\\.](18|19|20)[0-9]{2})|((0[1-9]|1[0-9]|2[0-8])[\\.](0[1-9]|1[0-2])[\\.](18|19|20)[0-9]{2})|(29[\\.](02)[\\.](((18|19|20)(04|08|[2468][048]|[13579][26]))|2000))) ((([A-Z][A-Za-z]+(?!\\.*-$)){1,2}([-\\ ])?){1,2})((([A-Z][A-Za-z]+(?!\\.*-\\ $)){1,2}([-\\ ])?){1,2})$");

//Checks entries in provided file with the regex criteria
    QRegularExpressionMatch match = re.match(input);
    if (match.hasMatch()) {
        rezultat2.append(input);
    }
    else if (!match.hasMatch()){
        //Uncomment to display non valid entries.
        //qDebug() << "No Match"<< input;
    }
}


