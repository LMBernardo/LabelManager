#include "labelserver.h"

labelServer::labelServer(QObject *parent) : QObject(parent)
{
    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen(QHostAddress::Any, 9754)) {
        QString netError = "Failed to listen on port!" + tcpServer->errorString();
        qInfo() << netError;
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
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(clientReadyRead(clientConnection)));
}

void labelServer::clientReadyRead(QTcpSocket *client){

    qInfo() << client->readAll();

    QByteArray reply;
    QDataStream out(&reply, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);
    out << "Success";
    client->write(reply);
}
