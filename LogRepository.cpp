#include "LogRepository.h"

LogRepository::LogRepository()
{
}

void LogRepository::append(const Log &log)
{
}

Log LogRepository::get() const
{
    return Log(1, QDateTime(), QDateTime());
}
