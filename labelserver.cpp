#include "labelserver.h"

labelServer::labelServer(QObject *parent, unsigned short port) : QObject(parent)
{
    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen(QHostAddress::Any, port)) {
        qCritical() << "Failed to listen on port" << port << ":" << tcpServer->errorString();
        tcpServer->close();
        return;
    }

//    QString ipAddress;
//    QList<QHostAddress> addrList = QNetworkInterface::allAddresses();
//    // use the first non-localhost IPv4 address
//    for (int i = 0; i < addrList.size(); ++i) {
//        if (addrList.at(i) != QHostAddress::LocalHost &&
//            addrList.at(i).toIPv4Address()) {
//            ipAddress = addrList.at(i).toString();
//            break;
//        }
//    }

    connect(tcpServer, &QTcpServer::newConnection, this, &labelServer::clientConnected);
}

void labelServer::clientConnected(){
    qInfo() << "New client connected.";
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, SIGNAL(disconnected()), clientConnection, SLOT(deleteLater()));
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(clientReadyRead()));
}

void labelServer::clientReadyRead(){

    QTcpSocket *client = static_cast<QTcpSocket*>(QObject::sender());
    qInfo() << client->readAll();

//    QByteArray reply;
//    QDataStream out(&reply, QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_5_12);
//    out << "Success";
    client->write("Success!");
}
