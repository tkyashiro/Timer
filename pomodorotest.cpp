#include <QTest>
#include <QTimer>
#include <QDebug>

#include "Pomodoro.h"

class PomodoroTest : public QObject
{
    Q_OBJECT
private slots:
    void someTest();
    void someTest2();
};

typedef Pomodoro Pom;

void PomodoroTest::someTest()
{
    Pom pomodoro(0);

    pomodoro.start();

    // 25 min passed

    pomodoro.finish();

    Log l = pomodoro.getLog();
    //QVERIFY( l.isSuccess() );
}

void PomodoroTest::someTest2()
{
    Pom pomodoro(0);

    pomodoro.start();

    // call without finish will crash
    // Log l = pomodoro.getLog();

    //QVERIFY( ! l.isSuccess() );
}

QTEST_APPLESS_MAIN(PomodoroTest)

#include "pomodorotest.moc"
