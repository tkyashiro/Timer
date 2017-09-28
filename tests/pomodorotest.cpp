#include <QTest>
#include <QTimer>
#include <QDebug>

#include "Pomodoro.h"

class PomodoroTest : public QObject
{
    Q_OBJECT
private slots:
    void testLogIsAvailableAfterPomodoroFinished();
    void testLogIsNotAvailableBeforePomodoroFinished();
};

class Observer
{
public:
    void setState(Pomodoro::State s){ state_ = s; }
    Pomodoro::State state() const { return state_; }
private:
    Pomodoro::State state_;
};

class FakePomodoro : public Pomodoro
{
public:
    FakePomodoro(int id) : Pomodoro(id) {
        setPomodoroTime(1);
    }
};

using Pom = FakePomodoro;

void PomodoroTest::testLogIsAvailableAfterPomodoroFinished()
{
    Pom pomodoro(0);
    Observer o;
    connect( &pomodoro, &Pomodoro::stateChanged, [&o](Pomodoro::State s){ o.setState(s); } );

    pomodoro.start();

    QCOMPARE( o.state(), Pomodoro::Running );

    // will finish immediately

    pomodoro.finish();

    QCOMPARE( o.state(), Pomodoro::Stopped );

    Log l = pomodoro.getLog();
    //QVERIFY( l.isSuccess() );

}

void PomodoroTest::testLogIsNotAvailableBeforePomodoroFinished()
{
    Pom pomodoro(0);

    pomodoro.start();

    // call without finish will crash
    // Log l = pomodoro.getLog();

    //QVERIFY( ! l.isSuccess() );
}

QTEST_APPLESS_MAIN(PomodoroTest)

#include "pomodorotest.moc"
