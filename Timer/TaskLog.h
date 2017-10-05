#ifndef LOG_H
#define LOG_H

#include <QDateTime>

#include "Task.h"
#include "Category.h"

class TaskLog
{
public:
    TaskLog(Task task, const QDateTime &start, const QDateTime &end);
    TaskLog(int taskId, QDateTime start );

    bool operator == ( const TaskLog &rhs ) const;

private:
    Task task_;

    const QDateTime start_;
    const QDateTime end_;
};

#endif // LOG_H
