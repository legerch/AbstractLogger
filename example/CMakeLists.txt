cmake_minimum_required(VERSION 3.19)

# Set project properties
set(PROJECT_NAME AppExample)
set(PROJECT_VERSION_SEMANTIC 0.0.1)
set(PROJECT_VERSION_CPP_MIN 11)

# Set project options
# Options availables for external project start with "EXT_OPT_APPEXAMPLE_", those options can be use in top CMakeFiles.
# All options are disabled by default.
# List of available options :
# - Currently no options available

# Set project configuration
project(${PROJECT_NAME} LANGUAGES CXX)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION_SEMANTIC})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set C++ standard to use
if(DEFINED CMAKE_CXX_STANDARD)
    if(${CMAKE_CXX_STANDARD} LESS ${PROJECT_VERSION_CPP_MIN})
        message(FATAL_ERROR "Project ${PROJECT_NAME} require at least C++ standard ${PROJECT_VERSION_CPP_MIN}")
    endif()
else()
    set(CMAKE_CXX_STANDARD ${PROJECT_VERSION_CPP_MIN})
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "Project \"${PROJECT_NAME}\" compiled with C++ standard ${CMAKE_CXX_STANDARD}")

# Configure file project - File containing macro that can be used in project
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/config.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/config.h")

# Find Qt packages
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# Manage app files
set(PROJECT_HEADERS
    mainwindow.h

    sinks/loggerqt.h
)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp

    sinks/loggerqt.cpp
)

set(PROJECT_UI
    mainwindow.ui
)

set(PROJECT_RSC

)

set(PROJECT_FILES ${PROJECT_RSC} ${PROJECT_UI} ${PROJECT_HEADERS} ${PROJECT_SOURCES})

# Platform dependant stuff
# Windows (for both x86/x64)
if(WIN32)
    SET(PROJECT_BUILD_ARGS WIN32)
endif()

# MacOS (for both x86/x64)
if(UNIX AND APPLE)
    SET(PROJECT_BUILD_ARGS "")
endif()

# Linux, BSD, Solaris, Minix (for both x86/x64)
if(UNIX AND NOT APPLE)
    SET(PROJECT_BUILD_ARGS "")
endif()

# Add files to the application
add_executable(${PROJECT_NAME} ${PROJECT_BUILD_ARGS} ${PROJECT_FILES})

# Set version of executable
set_target_properties(${PROJECT_NAME} PROPERTIES
                        VERSION ${PROJECT_VERSION}
                        SOVERSION ${PROJECT_VERSION_MAJOR})

# Link needed libraries
# Qt Library
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Logger library
target_link_libraries(${PROJECT_NAME} PRIVATE qlogger)
target_compile_definitions(${PROJECT_NAME} PRIVATE QT_MESSAGELOGCONTEXT)

# Libra library
target_link_libraries(${PROJECT_NAME} PUBLIC libra)

# Compile needed definitions
# No custom definitions needed

# Definition which depends on options
# Ex :
# if(EXT_OPT_APPEXAMPLE_XYZ)
#   target_compile_definitions(${PROJECT_NAME} PRIVATE APPQTBENCHM_XYZ)
# endif()

