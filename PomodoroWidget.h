#ifndef POMODOROWIDGET_H
#define POMODOROWIDGET_H
#include "Pomodoro.h"
#include <QWidget>

#include <memory>

namespace Ui {
class PomodoroWidget;
}

//template <typename> class Pomodoro;
//template <> class Pomodoro<QTimer>;
class LogCollection;

class PomodoroController : public QObject
{
    Q_OBJECT
public:
    PomodoroController(std::shared_ptr<Pomodoro<QTimer>> p, std::shared_ptr<LogCollection> r)
        : pomodoro_(p), repository_(r)
    {
    }

    //Q_SIGNAL void started();
    //Q_SIGNAL void stopped();

private:
    std::shared_ptr<Pomodoro<QTimer>> pomodoro_;
    std::shared_ptr<LogCollection> repository_;
};

class PomodoroWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PomodoroWidget(QWidget *parent = 0);
    ~PomodoroWidget();

private slots:
    void on_btnStartStop_clicked();

private:
    Ui::PomodoroWidget *ui;

    // Models
    std::shared_ptr<Pomodoro<QTimer>> pomodoro_;
    std::shared_ptr<LogCollection> repository_;

    // Controller
    std::unique_ptr<PomodoroController> app_;
};

#endif // POMODOROWIDGET_H
