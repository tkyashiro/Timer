#ifndef TASKWINDOW_H
#define TASKWINDOW_H

#include <QMainWindow>

class TaskWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit TaskWindow(QWidget* parent = nullptr);
};

#endif
