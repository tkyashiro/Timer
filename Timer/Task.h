#ifndef TAKS_H
#define TAKS_H

#include "Category.h"

#include <QString>

class Task
{
public:
    Task(){}

private:
    Category category1_;
    Category category2_;
    Category category3_;
    const QString description_;
};

#endif

