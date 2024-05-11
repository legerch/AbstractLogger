#include "loggerqt.h"

#include <QMessageLogger>

void LoggerQt::log(Level level, const libra::LogContext &context, const std::string &msg)
{
    /* Format message to Qt logging system */
    const QMessageLogger msgLogger(context.file, context.line, context.function);

    /* Call appropriate level */
    switch(level)
    {
        case LOG_LVL_FATAL:     msgLogger.fatal("%s", msg.c_str()); break;
        case LOG_LVL_ERROR:     msgLogger.critical("%s", msg.c_str()); break;
        case LOG_LVL_WARNING:   msgLogger.warning("%s", msg.c_str()); break;
        case LOG_LVL_INFO:      msgLogger.info("%s", msg.c_str()); break;
        case LOG_LVL_DEBUG:     msgLogger.debug("%s", msg.c_str()); break;

        default:                msgLogger.debug("%s", msg.c_str()); break;
    }
}
