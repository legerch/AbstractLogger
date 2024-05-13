#ifndef LOGGERQT_H
#define LOGGERQT_H

#include "logs/logmanager.h"

class LoggerQt : public libra::ILogger
{

public:
    virtual void log(Level level, const libra::LogContext &context, const std::string &msg) override;
};

#endif // LOGGERQT_H
