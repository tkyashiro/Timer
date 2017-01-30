#include "PomodoroWidget.h"
#include "ui_PomodoroWidget.h"

PomodoroWidget::PomodoroWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PomodoroWidget),
    pomodoro_(),
    repository_(std::make_shared<LogRepository>())
{
    ui->setupUi(this);
}

PomodoroWidget::~PomodoroWidget()
{
    delete ui;
}
