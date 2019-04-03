#ifndef LABELCLIENT_H
#define LABELCLIENT_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QDataStream>

class labelClient : public QObject
{
    Q_OBJECT
public:
    explicit labelClient(QObject *parent = nullptr);

private:
    QTcpSocket *tcpSocket;
    QDataStream in;

    void sendData();

signals:

public slots:
    void connectionOpened();
    void connectError(QAbstractSocket::SocketError error);
    void readReply();
};

#endif // LABELCLIENT_H
