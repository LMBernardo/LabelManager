#ifndef LABELCLIENT_H
#define LABELCLIENT_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>
#include <QDataStream>

class labelClient : public QObject
{
    Q_OBJECT
public:
    explicit labelClient(QObject *parent = nullptr);
    void sendData(std::string data);

private:
    QTcpSocket *tcpSocket = nullptr;
    QDataStream *in = nullptr;

signals:

public slots:
    void connectionOpened();
    void connectError(QAbstractSocket::SocketError error);
    void readReply();
};

#endif // LABELCLIENT_H
