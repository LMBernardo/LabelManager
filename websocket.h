#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <QObject>
#include <QtWebSockets/QtWebSockets>

class webSocket : public QObject
{
    Q_OBJECT
public:
    explicit webSocket(QObject *parent = nullptr, quint16 port = 9458);
    ~webSocket();

private:
    QWebSocketServer *webSocketServer;
    QList<QWebSocket*> ws_clients;

signals:
    void wsMessageReceived(const QString message);
    void closed();

private slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void processBinaryMessage(QByteArray message);
    void socketDisconnected();
};

#endif // WEBSOCKET_H
