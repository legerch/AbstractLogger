#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include "ilogger.h"

/*****************************/
/* Macro definitions         */
/*****************************/

/* Use to retrieve context informations */
#define _LOG_CTX_FILE   static_cast<const char *>(__FILE__)
#define _LOG_CTX_LINE   __LINE__
#define _LOG_CTX_FCT    static_cast<const char *>(LIBRARYNAME_FCTNAME)

/* Create macros for easier log usage */
#define _LOG_GENERIC(level, msg)    LogManager::registerLog(level, _LOG_CTX_FILE, _LOG_CTX_LINE, _LOG_CTX_FCT, msg)

#define LOG_FATAL(msg)  _LOG_GENERIC(ILogger::LOG_LVL_FATAL, msg)
#define LOG_ERROR(msg)  _LOG_GENERIC(ILogger::LOG_LVL_ERROR, msg)
#define LOG_WARN(msg)   _LOG_GENERIC(ILogger::LOG_LVL_WARNING, msg)
#define LOG_INFO(msg)   _LOG_GENERIC(ILogger::LOG_LVL_INFO, msg)
#define LOG_DEBUG(msg)  _LOG_GENERIC(ILogger::LOG_LVL_DEBUG, msg)

/*****************************/
/* Namespace definitions     */
/*****************************/
namespace gen{

/*****************************/
/* Class definitions         */
/*****************************/

class LogManager
{

public:
    static void setLogger(ILogger *logger);

public:
    static void registerLog(ILogger::Level level, const char *filename, int lineNumber, const char *fctName, const std::string &msg);

private:
    static ILogger *m_refLogger;
};

} // Namespace gen

#endif // LOGMANAGER_H
