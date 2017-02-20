#include "PomodoroWidget.h"
#include "Pomodoro.h"
#include "ui_PomodoroWidget.h"
#include "LogRepository.h"
#include <QDebug>

PomodoroWidget::PomodoroWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PomodoroWidget),
    pomodoro_(std::make_shared<Pomodoro>(0)),
    repository_(std::make_shared<LogCollection>()),
    pomodoroTime(pomodoro_->getPomodoroTime())
{
    ui->setupUi(this);
    connect(pomodoro_.get(), &Pomodoro::stateChanged,
            this, &PomodoroWidget::onStateChanged);
    connect(pomodoro_.get(), &Pomodoro::elapsed ,
            this, &PomodoroWidget::onElapsed);
    //connect(ui->btnStartStop, &QPushButton::clicked, this, &PomodoroWidget::on_btnStartStop_clicked);
}

PomodoroWidget::~PomodoroWidget()
{
    delete ui;
}

void PomodoroWidget::on_btnStartStop_clicked()
{

    qDebug() << "Button Pressed !" ;
    if(pomodoro_->isRunning()){
        pomodoro_->finish();
    }else{
        pomodoro_->start();
    }
}

void PomodoroWidget::onStateChanged(Pomodoro::State s)
{
    if(s == Pomodoro::Running ){
        ui->btnStartStop->setText("Stop"); 
    }else{
        ui->btnStartStop->setText("Start");
    }
}

void PomodoroWidget::onElapsed(int minute)
{

    ui->lcdNumber->display(minute);
}
