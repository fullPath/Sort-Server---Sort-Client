#ifndef SORTTASK_H
#define SORTTASK_H

#include <QtGlobal>
#include <QString>
#include <QDateTime>
#include <QList>
#include <QMetaType>

class SortTask
{
    friend QDataStream& operator<<(QDataStream& out, const SortTask& task);
    friend QDataStream& operator>>(QDataStream& in, SortTask& task);

public:
    SortTask();
    ~SortTask();

    void generateTask(QString const& host);
    QList<quint32>& values();

    QString host() const;
    QDateTime timestamp() const;

private:
    QString m_host;
    QList<quint32> m_values;
    QDateTime m_timestamp;
};

Q_DECLARE_METATYPE(SortTask)

#endif // SORTTASK_H
