#ifndef LOG_H
#define LOG_H

#include <QDateTime>

class Log
{
public:
    Log(int taskId, const QDateTime &start, const QDateTime &end);
    Log(int taskId, QDateTime start );

    bool operator == ( const Log &rhs ) const;

private:
    const int taskId_;
    const QDateTime start_;
    const QDateTime end_;
};

#endif // LOG_H
