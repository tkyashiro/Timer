#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>

class TaskWidget : public QWidget
{
    Q_OBJECT
public:
    TaskWidget(QWidget* parent = nullptr) : QWidget(parent) {}
};

#endif
