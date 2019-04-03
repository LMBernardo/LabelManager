#include "labelclient.h"

labelClient::labelClient(QObject *parent) : QObject(parent)
{
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_5_12);

    connect(tcpSocket, &QIODevice::readyRead, this, &labelClient::readReply);
    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &labelClient::connectError);
}

void labelClient::sendData(){
    tcpSocket->abort();
    tcpSocket->connectToHost("leach.site1", 9754);
}

void labelClient::connectError(QAbstractSocket::SocketError error){
    qInfo() << "Socket error:" << error;
}

void labelClient::readReply(){
    qInfo() << in;
}
