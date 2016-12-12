#ifndef LOGREPOSITORY_H
#define LOGREPOSITORY_H

#include "Log.h"

#include <list>

class LogRepository
{
public:
    LogRepository();

    void append( const Log &log );
    Log get() const;

private:
    //Log log_;
    QList<Log> logs_;
};

#endif // LOGREPOSITORY_H
