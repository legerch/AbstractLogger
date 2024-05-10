#ifndef LOGGERQT_H
#define LOGGERQT_H

#include "logs/logmanager.h"

class LoggerQt : public gen::ILogger
{

public:
    virtual void log(Level level, const gen::LogContext &context, const std::string &msg) override;
};

#endif // LOGGERQT_H
