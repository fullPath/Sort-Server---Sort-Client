#include <QtAlgorithms>

#include "sorttask.h"

SortTask::SortTask()
:m_host(""),m_timestamp(QDateTime::currentDateTime())
{
}

SortTask::~SortTask()
{
}

void SortTask::generateTask(QString const& host)
{
    m_host = host;
    for(int i=0;i<20;++i)
        m_values << qrand()%1000;
}


QList<quint32>& SortTask::values()
{
    return m_values;
}

QString SortTask::host() const
{
    return m_host;
}

QDateTime SortTask::timestamp() const
{
    return m_timestamp;
}

QDataStream& operator<<(QDataStream& out, const SortTask& task)
{
    out << task.m_host;
    out << task.m_values;
    out << task.m_timestamp;
    return out;
}

QDataStream& operator>>(QDataStream& in, SortTask& task)
{
    in >> task.m_host;
    in >> task.m_values;
    in >> task.m_timestamp;
    return in;
}
