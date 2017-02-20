#ifndef POMODORO_H
#define POMODORO_H

#include "Log.h"
#include <memory>
#include <QTimer>
#if 0
class Timer
{
public:
    virtual void setInterval(int64_t sec) = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
private:
    Timer(){}
    virtual ~Timer(){}
};

class TimerWithQTimer : public Timer
{
public:
    // ...
};
#endif

///
/// \brief The Pomodoro class
/// \note controller class which does
/// - measure time (25min usually)
/// - create a log of that pomodoro
///
/// - stop automatically when 25min has passed
/// - notify observers when it's finished

//template <typename Timer>
class Pomodoro : public QObject
{
    Q_OBJECT
public:
    enum State{ Running, Stopped };
public:
    Pomodoro(int task) : task_(task) {}

    Q_SIGNAL void stateChanged(State s);

    Q_SIGNAL void elapsed(int minute);

    void start()
    {
        start_ = QDateTime::currentDateTime();
        timer_.setInterval( 25 * 60 * 1000 );
        timer_.start();

        emit stateChanged(Running);
        emit elapsed(0);
    }

    void finish()
    {
        Q_ASSERT( isRunning() );

        end_ = QDateTime::currentDateTime();
        timer_.stop();
        log_ = std::make_shared<Log>(task_, start_, end_);

        emit stateChanged(Stopped);
        emit elapsed(20);
    }

    Log getLog() const
    {
        Q_ASSERT( !isRunning() );
        //Q_ASSERT( log );

        return *log_;
    }

    int getPomodoroTime()
    {
        return pomodoroTime;
    }

    bool isRunning() const { return timer_.isActive(); }
private:
    int task_;
    QDateTime start_, end_;
    QTimer timer_;
    std::shared_ptr<Log> log_;
    const int pomodoroTime = 20;
};

#endif // POMODORO_H
