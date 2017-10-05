#include "TaskWindow.h"

#include <QTabWidget>

#include "TaskWidget.h"

class StartupPage : public QWidget
{
public:
    explicit StartupPage(QWidget *parent = nullptr) : QWidget(parent) {}
};

TaskWindow::TaskWindow(QWidget* parent ) : QMainWindow(parent)
{
    auto tab = new QTabWidget(this);

    auto startupPage = new StartupPage(tab);
    tab->addTab(startupPage, tr("Startup"));

    auto taskPage = new TaskWidget(tab);
    tab->addTab(taskPage, tr("Startup"));

    this->setCentralWidget(tab);
}
