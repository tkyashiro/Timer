#ifndef TASKRECORDER_H
#define TASKRECORDER_H

#include <QObject>

#include "Task.h"
#include "TaskLog.h"

class TaskRecorder : public QObject
{
    Q_OBJECT
public:
    TaskRecorder(const Task task) : task_(task) {}

    Q_SLOT void start();
    Q_SLOT void stop();

    TaskLog Log() const;

private:
    Task task_;
    QDateTime start_;
    QDateTime end_;
};

#endif
