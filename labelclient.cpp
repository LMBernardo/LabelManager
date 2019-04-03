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
    tcpSocket->connectToHost("localhost", 9754);

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);
    out << "Test data";
    tcpSocket->write(data);
}

void labelClient::connectError(QAbstractSocket::SocketError error){
    qWarning() << "Socket error:" << error;
}

void labelClient::readReply(){
    qInfo() << in;
}

void labelClient::connectionOpened(){
    qInfo() << "Connected to server.";
    sendData();
}
