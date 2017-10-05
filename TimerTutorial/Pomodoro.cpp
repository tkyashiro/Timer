#include "Pomodoro.h"

namespace  {
const int defaultPomodoroTime = 25;
}

Pomodoro::Pomodoro(int task) : task_(task),
    pomodoroTime_min(defaultPomodoroTime)
{
    connect(&updatingTimer_, &QTimer::timeout, this, &Pomodoro::update);
}
