#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include <QObject>
#include <QxtRPCPeer>

#include "sorttask.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);

protected slots:
    void connectServer();
    void sendTask();
    void getResult(SortTask task);
    void gotError(QAbstractSocket::SocketError error);

signals:
    void nextTask();
    void sendSortTask(SortTask);

private:
    QxtRPCPeer* m_socket;
    quint8 m_tasks;
};

#endif // CLIENT_H
