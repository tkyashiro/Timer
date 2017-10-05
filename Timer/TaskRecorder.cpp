#include "TaskRecorder.h"

void TaskRecorder::start()
{
    Q_ASSERT(!start_.isValid());
    Q_ASSERT(!end_.isValid());
    start_ = QDateTime::currentDateTime();
}

void TaskRecorder::stop()
{
    Q_ASSERT(start_.isValid());
    end_ = QDateTime::currentDateTime();
}

TaskLog TaskRecorder::Log() const
{
    Q_ASSERT(start_.isValid());
    Q_ASSERT(end_.isValid());
    return TaskLog(task_, start_, end_);
}
