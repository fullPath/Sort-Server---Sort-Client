#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtNetwork>

class Connection : public QObject
{
    Q_OBJECT
public:
    Connection(QObject* parent, QTcpSocket* socket);

protected slots:
    void getTask();
    void disconnected();

private:
    QTcpSocket* m_socket;
    QString m_host;
};

#endif // CONNECTION_H
