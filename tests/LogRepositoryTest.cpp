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
    void addMultipleTest();
};

void LogRepositoryTest::addTest()
{
    LogCollection c;

    Log l(2, QDateTime(), QDateTime());

    c.append( l );

    QCOMPARE( 1, c.size() );

    Log actual = c.get(0);

    QCOMPARE( actual, l );
}

void LogRepositoryTest::addMultipleTest()
{
    LogCollection c;

    Log l1(1, QDateTime::currentDateTime(), QDateTime::currentDateTime());
    Log l2(2, QDateTime::currentDateTime(), QDateTime::currentDateTime());
    Log l3(3, QDateTime::currentDateTime(), QDateTime::currentDateTime());

    c.append( l1 );
    c.append( l2 );
    c.append( l3 );

    QCOMPARE( 3, c.size() );

    Log actual = c.get(0);
    QCOMPARE( actual, l1 );

    Log actual2 = c.get(1);
    QCOMPARE( actual2, l2 );

    Log actual3 = c.get(2);
    QCOMPARE( actual3, l3 );
}

QTEST_APPLESS_MAIN(LogRepositoryTest)

#include "LogRepositoryTest.moc"
