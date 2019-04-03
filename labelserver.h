#ifndef LABELSERVER_H
#define LABELSERVER_H

#include <QObject>
#include <QDebug>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QHostAddress>
#include <QMessageBox>

class labelServer : public QObject
{
    Q_OBJECT
public:
    explicit labelServer(QObject *parent = nullptr);

private:
    QTcpServer *tcpServer = nullptr;

signals:

public slots:
    void clientConnected();
    void clientReadyRead(QTcpSocket *client);
};

#endif // LABELSERVER_H
