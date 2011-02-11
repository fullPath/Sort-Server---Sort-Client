#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork>
#include "sorttask.h"

#include <QxtRPCPeer>

class Server : public QObject
{
    Q_OBJECT
public:
    Server(QObject* parent = 0);

protected slots:
    void getTask(quint64 client, SortTask task);
    void disconnected(quint64 client);

signals:
    void sendTask(SortTask);

private:
    QxtRPCPeer* m_socket;
};

#endif // SERVER_H
