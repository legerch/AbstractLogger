#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>

namespace gen{

class ILogger
{

public:
    enum Level
    {
        LOG_LVL_FATAL = 0,
        LOG_LVL_ERROR,
        LOG_LVL_WARNING,
        LOG_LVL_INFO,
        LOG_LVL_DEBUG
    };

public:
    virtual void log(Level level, const std::string &msg) = 0;
};

} // Namespace gen

#endif // ILOGGER_H
