#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include "ilogger.h"

/*****************************/
/* Macro definitions         */
/*****************************/

/* Use to retrieve context informations */
#define _LIBRA_LOG_CTX_FILE   static_cast<const char *>(LIBRA_FILE)
#define _LIBRA_LOG_CTX_LINE   LIBRA_LINE
#define _LIBRA_LOG_CTX_FCT    static_cast<const char *>(LIBRA_FCTNAME)

/* Create macros for easier log usage */
#define _LIBRA_LOG_GENERIC(level, msg)    libra::LogManager::registerLog(level, _LIBRA_LOG_CTX_FILE, _LIBRA_LOG_CTX_LINE, _LIBRA_LOG_CTX_FCT, msg)

#define LIBRA_LOG_FATAL(msg)  _LIBRA_LOG_GENERIC(libra::ILogger::LOG_LVL_FATAL, msg)
#define LIBRA_LOG_ERROR(msg)  _LIBRA_LOG_GENERIC(libra::ILogger::LOG_LVL_ERROR, msg)
#define LIBRA_LOG_WARN(msg)   _LIBRA_LOG_GENERIC(libra::ILogger::LOG_LVL_WARNING, msg)
#define LIBRA_LOG_INFO(msg)   _LIBRA_LOG_GENERIC(libra::ILogger::LOG_LVL_INFO, msg)
#define LIBRA_LOG_DEBUG(msg)  _LIBRA_LOG_GENERIC(libra::ILogger::LOG_LVL_DEBUG, msg)

/*****************************/
/* Namespace definitions     */
/*****************************/
namespace libra{

/*****************************/
/* Class definitions         */
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

#endif // LOGMANAGER_H
