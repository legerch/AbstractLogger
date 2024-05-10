#ifndef LOGCONTEXT_H
#define LOGCONTEXT_H

namespace gen{

class LogContext
{
public: /* Disable class copy */
    LogContext(const LogContext &) = delete;\
    LogContext &operator=(const LogContext &) = delete;

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
