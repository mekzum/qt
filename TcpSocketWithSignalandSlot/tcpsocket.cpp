#include "tcpsocket.h"

tcpSocket::tcpSocket(QObject *parent) : QObject(parent)
{

}

void  tcpSocket::test()
{
   socket = new QTcpSocket(this);

   connect(socket,SIGNAL(connected()),this,SLOT(connected()));
   connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
   connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
   connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWritten(qint64)));

   qDebug() << "connecting... ";

   socket->connectToHost("192.168.1.34",90);

   if(!socket->waitForConnected(1000))
   {
       qDebug() << "Error" << socket->errorString();

   }

}

void  tcpSocket::connected()
{
 qDebug() << "connected!";

}
void  tcpSocket::disconnected()
{
 qDebug() << "disconnected!";

}
void  tcpSocket::bytesWritten(qint64 bytes)
{
 qDebug() << "we wrote" << bytes;

}
void  tcpSocket::readyRead()
{
 qDebug() << "Reading...";
 qDebug () << socket->readAll();
 socket->write("merhaba");

}
