#include "Log.h"

Log::Log(int taskId, const QDateTime &start, const QDateTime &end)
    : taskId_(taskId), start_(start), end_(end)
{
}

bool Log::operator == (const Log &rhs) const
{
    if (taskId_ != rhs.taskId_){ return false; }
    if (start_ != rhs.start_){ return false; }
    if (end_ != rhs.end_){ return false; }

    return true;
}
