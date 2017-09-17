#include "socket.h"
#include <QDebug>
Socket::Socket(QObject *parent) : QObject(parent)
{

}

void Socket::Connect()
{
    //connected
    client = new QTcpSocket(this);
    client->connectToHost("192.168.1.34",90);

    if(client->waitForConnected(3000))
    {
        qDebug() <<"Connected!";
        client->write("Emre");

        client->waitForBytesWritten(100);

        //send
        client->waitForReadyRead(3000);

        qDebug() << "Reading:" << client->bytesAvailable();

        qDebug() << client->readAll();


        //close
        client->close();


    }
     else
    {
       qDebug() <<"Not Connected";
    }

}
