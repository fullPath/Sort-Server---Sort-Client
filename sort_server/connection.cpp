#include <iostream>

#include "connection.h"
#include "sorttask.h"

Connection::Connection(QObject* parent, QTcpSocket* socket)
:QObject(parent),m_socket(socket),m_host("")
{
    connect(m_socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(getTask()));


