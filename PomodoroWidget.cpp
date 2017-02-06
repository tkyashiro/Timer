#include "PomodoroWidget.h"
#include "Pomodoro.h"
#include "ui_PomodoroWidget.h"
#include "LogRepository.h"
#include <QDebug>

PomodoroWidget::PomodoroWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PomodoroWidget),
    pomodoro_(std::make_shared<Pomodoro<QTimer>>(0)),
    repository_(std::make_shared<LogCollection>())
{
    ui->setupUi(this);
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
        ui->btnStartStop->setText("Start");
    }else{
        pomodoro_->start();
        ui->btnStartStop->setText("Stop");
    }
}
