#ifndef LIBRA_LOGS_ABSTRACTLOGGER_H
#define LIBRA_LOGS_ABSTRACTLOGGER_H

#include "libraglobal.h"

#include <string>

/*****************************/
/* Macro definitions         */
/*****************************/

/* Use to retrieve context informations */
#define _LIBRA_LOG_CTX_FILE   static_cast<const char *>(LIBRA_FILE)
#define _LIBRA_LOG_CTX_LINE   LIBRA_LINE
#define _LIBRA_LOG_CTX_FCT    static_cast<const char *>(LIBRA_FCTNAME)

/* Create macros for easier log usage */
#define _LIBRA_LOG_GENERIC(level, msg)    LIBRA::LogManager::registerLog(level, _LIBRA_LOG_CTX_FILE, _LIBRA_LOG_CTX_LINE, _LIBRA_LOG_CTX_FCT, msg)

#define LIBRA_LOG_FATAL(msg)  _LIBRA_LOG_GENERIC(LIBRA::ILogger::LOG_LVL_FATAL, msg)
#define LIBRA_LOG_ERROR(msg)  _LIBRA_LOG_GENERIC(LIBRA::ILogger::LOG_LVL_ERROR, msg)
#define LIBRA_LOG_WARN(msg)   _LIBRA_LOG_GENERIC(LIBRA::ILogger::LOG_LVL_WARNING, msg)
#define LIBRA_LOG_INFO(msg)   _LIBRA_LOG_GENERIC(LIBRA::ILogger::LOG_LVL_INFO, msg)
#define LIBRA_LOG_DEBUG(msg)  _LIBRA_LOG_GENERIC(LIBRA::ILogger::LOG_LVL_DEBUG, msg)

/*****************************/
/* Start namespace           */
/*****************************/
namespace libra{

/*****************************/
/*     Class definitions     */
/*        LogContext         */
/*****************************/
class LIBRA_EXPORT LogContext
{
    LIBRA_DISABLE_COPY(LogContext)

public:
    constexpr LogContext(const char *filename, int lineNumber, const char *fctName) :
        line(lineNumber), file(filename), function(fctName){};

public:
    int line = 0;
    const char *file = nullptr;
    const char *function = nullptr;
};

/*****************************/
/*     Class definitions     */
/*        ILogger            */
/*****************************/
class LIBRA_EXPORT ILogger
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
    virtual void log(Level level, const LogContext &context, const std::string &msg) = 0;
};

/*****************************/
/*     Class definitions     */
/*        LogManager         */
/*****************************/
class LIBRA_EXPORT LogManager
{
public:
    static void setLogger(ILogger *logger);

public:
    static void registerLog(ILogger::Level level, const char *filename, int lineNumber, const char *fctName, const std::string &msg);

private:
    static ILogger *m_refLogger;
};

} // namespace libra

#endif // LIBRA_LOGS_ABSTRACTLOGGER_H
