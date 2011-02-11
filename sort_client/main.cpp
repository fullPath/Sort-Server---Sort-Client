#include <QtCore/QCoreApplication>
#include <QTime>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    Client client;

    return a.exec();
}
