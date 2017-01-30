#ifndef POMODOROWIDGET_H
#define POMODOROWIDGET_H

#include <QWidget>

#include <memory>

namespace Ui {
class PomodoroWidget;
}

class Pomodoro;
class LogRepository;

class PomodoroController : public QObject
{
    Q_OBJECT
public:
    PomodoroController(std::shared_ptr<Pomodoro> p, std::shared_ptr<LogRepository> r)
        : pomodoro_(p), repository_(r)
    {
    }

    //Q_SIGNAL void started();
    //Q_SIGNAL void stopped();

private:
    std::shared_ptr<Pomodoro> pomodoro_;
    std::shared_ptr<LogRepository> repository_;
};

class PomodoroWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PomodoroWidget(QWidget *parent = 0);
    ~PomodoroWidget();

private:
    Ui::PomodoroWidget *ui;

    // Models
    std::shared_ptr<Pomodoro> pomodoro_;
    std::shared_ptr<LogRepository> repository_;

    // Controller
    std::unique_ptr<PomodoroController> app_;
};

#endif // POMODOROWIDGET_H
