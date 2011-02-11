#include <iostream>

#include "server.h"

Server::Server(QObject *parent)
:QObject(parent),m_socket(new QxtRPCPeer(this))
{
    qRegisterMetaType<SortTask>("SortTask");
    qRegisterMetaTypeStreamOperators<SortTask>("SortTask");

    connect(m_socket, SIGNAL(clientDisconnected(quint64)),this, SLOT(disconnected(quint64)));

    m_socket->attachSignal(this, SIGNAL(sendTask(SortTask)), "RESULT");
    m_socket->attachSlot("NEWTASK", this, SLOT(getTask(quint64,SortTask)));

    if(!m_socket->listen(QHostAddress::Any,9999))
    {
        std::cerr << "Ein Fehler ist aufgetreten!" << std::endl;
        QCoreApplication::exit(1);
    }  
}

void Server::getTask(quint64 client, SortTask task)
{
    std::cout << "Neue Aufgabe (" << task.timestamp().toString("yyyy-MM-dd hh:mm:ss").toStdString() << ") von Client <<" << task.host().toStdString() << ">>" << std::endl;

    qSort(task.values());
    m_socket->call(client,"RESULT",QVariant(QMetaType::type("SortTask"),&task));
}

void Server::disconnected(quint64 client)
{
    std::cout << "Client <<" << client << ">> hat die Verbindung geschlossen..." << std::endl;
}
