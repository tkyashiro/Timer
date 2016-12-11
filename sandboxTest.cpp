#include <QTest>

class SandBoxTest : public QObject
{
    Q_OBJECT
private:

private slots:
    void sandboxTestVerify();
    void sandboxTestCompare();

    void sandboxTestData_data();
    void sandboxTestData();
};


void SandBoxTest::sandboxTestVerify()
{
    QVERIFY2(false, "Failed, since this is test");
}

void SandBoxTest::sandboxTestCompare()
{
    QCOMPARE(1.00001f, 1.0);
}

void SandBoxTest::sandboxTestData_data()
{
    QTest::addColumn<int>("input");
    QTest::addColumn<int>("output");

    QTest::newRow("1^2") << 1 << 1;
    QTest::newRow("2^2") << 2 << 4;
}

void SandBoxTest::sandboxTestData()
{
    QFETCH(int, input);

    QTEST( static_cast<int>(std::pow(input,2)), "output" );
}


QTEST_APPLESS_MAIN(SandBoxTest)

#include "sandbox_test.moc"
