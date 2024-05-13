#include "config.h"
#include "mainwindow.h"

#include <QApplication>

#include "qlogger/qloghandler.h"
#include "sinks/loggerqt.h"

/*****************************/
/* Macro definitions         */
/*****************************/
#define APP_LOG_FILE            "logs/log.txt"
#define APP_LOG_NB_FILES        3
#define APP_LOG_SIZE            (1024 * 1024 * 5) // Equals 5 megabytes (Mb)
#define APP_LOG_ENABLE_CONSOLE  true

/*****************************/
/* Main method               */
/*****************************/
int main(int argc, char *argv[])
{
    /* Set logs */
    // Library dependencies
    LoggerQt libLogger;
    libra::LogManager::setLogger(&libLogger);

    // Application
    QLogger::QLogHandler::instance().init(APP_LOG_FILE, APP_LOG_NB_FILES, APP_LOG_SIZE, APP_LOG_ENABLE_CONSOLE);

    /* Manage application properties */
    QApplication app(argc, argv);
    app.setApplicationName(PROJECT_NAME);
    app.setApplicationVersion(PROJECT_VERSION);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
