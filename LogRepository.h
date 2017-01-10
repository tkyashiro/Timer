#ifndef LOGREPOSITORY_H
#define LOGREPOSITORY_H

#include "Log.h"

#include <vector>

/**
 * @brief The LogCollection class which is responsible to
 * - ログを保持する
 * - 全部返す
 */
class LogCollection
{
public:
    LogCollection();

    void append( const Log &log );

    // 2)
    int size() const{ return logs_.size(); }
    const Log& get(int i) const { return logs_[i]; }

private:
    std::vector<Log> logs_;
};

#endif // LOGREPOSITORY_H
