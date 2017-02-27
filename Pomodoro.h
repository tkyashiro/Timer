#ifndef POMODORO_H
#define POMODORO_H

#include "Log.h"
#include <memory>
#include <QTimer>
#include <QThread>

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
    Pomodoro(int task) : task_(task)
    {
        connect(&updatingTimer_, &QTimer::timeout, this, &Pomodoro::update);
    }

    Q_SIGNAL void stateChanged(State s);

    Q_SIGNAL void elapsed(int second);

    void start()
    {
        elapsedTime = 0;

        start_ = QDateTime::currentDateTime();
        pomodoroTimer_.setInterval( pomodoroTime * 60 * 1000 );
        pomodoroTimer_.start();
        updatingTimer_.setInterval(1000);
        updatingTimer_.start();
        emit stateChanged(Running);
        emit elapsed(0);
    }

    void update()
    {
        //QThread::sleep(5);
        emit elapsed(++elapsedTime);
    }

    void finish()
    {
        Q_ASSERT( isRunning() );

        end_ = QDateTime::currentDateTime();
        pomodoroTimer_.stop();
        updatingTimer_.stop();
        log_ = std::make_shared<Log>(task_, start_, end_);
        emit stateChanged(Stopped);
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

    bool isRunning() const { return pomodoroTimer_.isActive(); }
private:
    int task_;
    QDateTime start_, end_;
    QTimer pomodoroTimer_;
    QTimer updatingTimer_;
    std::shared_ptr<Log> log_;
    const int pomodoroTime = 20;
    int elapsedTime;
};

#endif // POMODORO_H
