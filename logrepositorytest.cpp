#include <QTest>
#include <QDebug>

#include "LogRepository.h"

class LogRepositoryTest : public QObject
{
    Q_OBJECT
private slots:
    //void initTest(){ qDebug() << "init test"; }
    //void initTestCase() { qDebug() << "initTestCase"; }
    //void cleanupTestCase(){ qDebug() << "cleanup test case"; }
    //void cleanup(){ qDebug() << "cleanup"; }

    void addTest();
};

void LogRepositoryTest::addTest()
{
    LogRepository rep;

    Log l(1, QDateTime(), QDateTime());

    rep.append( l );

    Log actual = rep.get();

    QCOMPARE( actual, l );
}

QTEST_APPLESS_MAIN(LogRepositoryTest)

#include "LogRepositoryTest.moc"
