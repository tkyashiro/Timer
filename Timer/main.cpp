#include <QApplication>

#include "TaskWindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("tkyashiro");
    QCoreApplication::setApplicationName("Timer");

    QApplication a(argc, argv);

    TaskWindow w;
    w.show();

    return a.exec();
}
