#ifndef LOGCONTEXT_H
#define LOGCONTEXT_H

#include "libraryglobal.h"

namespace gen{

class LogContext
{
    LIBRARYNAME_DISABLE_COPY(LogContext)

public:
    constexpr LogContext(const char *filename, int lineNumber, const char *fctName) :
        line(lineNumber), file(filename), function(fctName){};

public:
    int line = 0;
    const char *file = nullptr;
    const char *function = nullptr;
};

} // Namespace gen

#endif // LOGCONTEXT_H
