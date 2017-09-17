#include <QCoreApplication>
#include "tcpsocket.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tcpSocket test;
    test.test();

    return a.exec();
}
