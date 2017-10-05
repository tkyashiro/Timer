#include "TaskLog.h"

TaskLog::TaskLog(Task task, const QDateTime &start, const QDateTime &end)
    : task_(task), start_(start), end_(end)
{
}

bool TaskLog::operator == (const TaskLog &rhs) const
{
    //if (taskId_ != rhs.taskId_){ return false; }
    if (start_ != rhs.start_){ return false; }
    if (end_ != rhs.end_){ return false; }

    return true;
}
