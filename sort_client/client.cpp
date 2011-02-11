#include <iostream>

#include "client.h"
#include "sorttask.h"

Client::Client(QObject *parent)
:QObject(parent),m_socket(new QxtRPCPeer(this)),m_tasks(5)
{
    connect(m_socket, SIGNAL(connectedToServer()), this, SLOT(sendTask()));
    connect(m_socket, SIGNAL(serverError(QAbstractSocket::SocketError)), this, SLOT(gotError(QAbstractSocket::SocketError)));

    connect(this, SIGNAL(nextTask()), this, SLOT(sendTask()));

    connectServer();

    qRegisterMetaType<SortTask>("SortTask");
    qRegisterMetaTypeStreamOperators<SortTask>("SortTask");

    m_socket->attachSignal(this, SIGNAL(sendSortTask(SortTask)), "NEWTASK");
    m_socket->attachSlot("RESULT",this,SLOT(getResult(SortTask)));
}

void Client::connectServer()
{
    m_socket->connect(QHostAddress::LocalHost,9999);
}

void Client::sendTask()
{
    SortTask task;
    task.generateTask(QHostInfo::localHostName());

    std::cout << "Aufgabe (" << task.timestamp().toString("yyyy-MM-dd hh:mm:ss").toStdString() << "): ";
    foreach(quint32 const& i, task.values())
        std::cout << i << " ";
    std::cout << std::endl;

    m_socket->call("NEWTASK",QVariant(QMetaType::type("SortTask"),&task));
}

void Client::getResult(SortTask task)
{
    std::cout << "Ergebnis zur Aufgabe (" << task.timestamp().toString("yyyy-MM-dd hh:mm:ss").toStdString() << "): ";
    foreach(quint32 const& i, task.values())
        std::cout << i << " ";
    std::cout << std::endl;

    if(--m_tasks)
        emit nextTask();
    else
    {
        m_socket->disconnect();
        QCoreApplication::exit();
    }
}

void Client::gotError(QAbstractSocket::SocketError error)
{
    std::cerr << "Es ist ein Fehler aufgetreten: " << static_cast<quint32>(error) << std::endl;
    QCoreApplication::exit(1);
}
