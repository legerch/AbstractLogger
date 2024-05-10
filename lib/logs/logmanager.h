#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include "ilogger.h"

/*****************************/
/* Macro definitions         */
/*****************************/

/* Use to retrieve context informations */
#define _GEN_LOG_CTX_FILE   static_cast<const char *>(__FILE__)
#define _GEN_LOG_CTX_LINE   __LINE__
#define _GEN_LOG_CTX_FCT    static_cast<const char *>(LIBRARYNAME_FCTNAME)

/* Create macros for easier log usage */
#define _GEN_LOG_GENERIC(level, msg)    gen::LogManager::registerLog(level, _GEN_LOG_CTX_FILE, _GEN_LOG_CTX_LINE, _GEN_LOG_CTX_FCT, msg)

#define GEN_LOG_FATAL(msg)  _GEN_LOG_GENERIC(gen::ILogger::LOG_LVL_FATAL, msg)
#define GEN_LOG_ERROR(msg)  _GEN_LOG_GENERIC(gen::ILogger::LOG_LVL_ERROR, msg)
#define GEN_LOG_WARN(msg)   _GEN_LOG_GENERIC(gen::ILogger::LOG_LVL_WARNING, msg)
#define GEN_LOG_INFO(msg)   _GEN_LOG_GENERIC(gen::ILogger::LOG_LVL_INFO, msg)
#define GEN_LOG_DEBUG(msg)  _GEN_LOG_GENERIC(gen::ILogger::LOG_LVL_DEBUG, msg)

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
