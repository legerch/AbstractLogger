#ifndef LIBRA_GLOBAL_H
#define LIBRA_GLOBAL_H

#include "config.h"

/**********************************
 * Library management
 *********************************/
#ifdef __GNUC__
#   if defined(LIBRA_LIBRARY_BUILD)
#       define LIBRA_EXPORT __attribute__((visibility("default")))
#   else
#       define LIBRA_EXPORT
#   endif
#else
#   if defined(LIBRA_LIBRARY_BUILD)
#       define LIBRA_EXPORT __declspec(dllexport)
#   else
#       define LIBRA_EXPORT __declspec(dllimport)
#   endif
#endif

/**********************************
 * Deprecations warnings
 *********************************/
#define LIBRA_DEPREC              [[deprecated]]            /**< Use to mark a method as deprecated. \n\code{.cpp}LIBRA_DEPREC void myOldFct(); \endcode */
#define LIBRA_DEPREC_X(reason)    [[deprecated(reason)]] 	/**< Use to mark a method as deprecated and specify a reason. \n\code{.cpp}LIBRA_DEPREC_X("Use myNewFct() instead") void myOldFunc(); \endcode */

/**********************************
 * Custom macros used to detect custom
 * built-in functions
 * Sources:
 * - MSVC: No equivalent
 * - GCC: https://gcc.gnu.org/onlinedocs/gcc-13.2.0/cpp/_005f_005fhas_005fbuiltin.html
 * - Clang: https://clang.llvm.org/docs/LanguageExtensions.html#has-builtin
 *********************************/
#if defined(__GNUC__) || defined(__clang__)
#   define LIBRA_BUILTIN(x)  __has_builtin(x)
#else
#   define LIBRA_BUILTIN(x)  0
#endif

/**********************************
 * Custom macros in order to
 * not trigger warning on expected
 * behaviour
 *********************************/
#define LIBRA_FALLTHROUGH     [[fallthrough]]    /**< Indicates that the fall through from the previous case label is intentional and should not be diagnosed by a compiler that warns on fallthrough */

/**********************************
 * Functions informations
 *********************************/
#define LIBRA_FCTNAME         __func__

#if defined(_MSC_VER)
#define LIBRA_FCTSIG          __FUNCSIG__
#else
#define LIBRA_FCTSIG          __PRETTY_FUNCTION__
#endif

/**********************************
 * Classes behaviours
 *********************************/
#define LIBRA_DISABLE_COPY(Class) \
    Class(const Class &) = delete;\
    Class &operator=(const Class &) = delete;

#define LIBRA_DISABLE_MOVE(Class) \
    Class(Class &&) = delete; \
    Class &operator=(Class &&) = delete;

#define LIBRA_DISABLE_COPY_MOVE(Class) \
    LIBRA_DISABLE_COPY(Class) \
    LIBRA_DISABLE_MOVE(Class)

#endif // LIBRA_GLOBAL_H
