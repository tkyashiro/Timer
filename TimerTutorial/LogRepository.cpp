#include "LogRepository.h"

LogCollection::LogCollection()
{
}

void LogCollection::append(const Log &log)
{
    logs_.push_back(log);
}

