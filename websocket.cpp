#include "websocket.h"
#include "mainwindow.h"

webSocket::webSocket(QObject *parent, quint16 port) : QObject(parent)
{
    webSocketServer = new QWebSocketServer("LabelManWSS", QWebSocketServer::NonSecureMode, this);
    if (webSocketServer->listen(QHostAddress::Any, port)){
        qInfo() << "LabelManWSS listening on port" << port;
        connect(webSocketServer, &QWebSocketServer::newConnection, this, &webSocket::onNewConnection);
        connect(webSocketServer, &QWebSocketServer::closed, this, &webSocket::closed);
    } else {
    qCritical() << "Failed to listen on port" << port << ":" << webSocketServer->errorString();
}
}

webSocket::~webSocket(){
    webSocketServer->close();
    qDeleteAll(ws_clients.begin(), ws_clients.end());
}

void webSocket::onNewConnection()
{
    QWebSocket *pSocket = webSocketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::textMessageReceived, this, &webSocket::processTextMessage);
    connect(pSocket, &QWebSocket::binaryMessageReceived, this, &webSocket::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &webSocket::socketDisconnected);

    ws_clients << pSocket;
}

void webSocket::processTextMessage(QString message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
        qDebug() << "Message received:" << message;

        emit wsMessageReceived(message);

    if (pClient) {
        QJsonObject response;
        response.insert("title", "Received");
        response.insert("Message", "Success");
        QJsonDocument responseDoc(response);
        QString responseString = QString::fromUtf8(responseDoc.toJson(QJsonDocument::Compact));
        pClient->sendTextMessage(responseString);
    }
}

void webSocket::processBinaryMessage(QByteArray message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
        qDebug() << "Binary Message received:" << message;
    if (pClient) {
        pClient->sendBinaryMessage(message);
    }
}

void webSocket::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
        qDebug() << "socketDisconnected:" << pClient;
    if (pClient) {
        ws_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}
