cmake_minimum_required(VERSION 3.19)

# Set project properties
set(PROJECT_NAME libra)
set(PROJECT_VERSION_SEMANTIC 0.0.1)
set(PROJECT_VERSION_CPP_MIN 11)

# Set project options
# Options availables for external project start with "EXT_OPT_LIBRA_", those options can be use in top CMakeFiles.
# All options are disabled by default.
# List of available options :
# - No available options

# Set project configuration
project(${PROJECT_NAME} LANGUAGES CXX)
project(${PROJECT_NAME} VERSION "${PROJECT_VERSION_SEMANTIC}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

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

# Set needed packages
## Example: find_package(nlohmann_json 3.11.3 REQUIRED)

# Configure file project - File containing macro that can be used in project
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/libraglobal.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/libraglobal.h")

# Manage library files
set(PROJECT_HEADERS
    config.h
    libraglobal.h

    mock/person.h

    logs_details/ilogger.h
    logs_details/logcontext.h
    logs_details/logmanager.h
)

set(PROJECT_SOURCES
    mock/person.cpp

    logs_details/logmanager.cpp
)

set(PROJECT_RSC

)

set(PROJECT_FILES ${PROJECT_HEADERS} ${PROJECT_SOURCES} ${PROJECT_RSC})

# Platform dependant stuff
# Windows (for both x86/x64)
if(WIN32)

endif()

# MacOS (for both x86/x64)
if(UNIX AND APPLE)

endif()

# Linux, BSD, Solaris, Minix (for both x86/x64)
if(UNIX AND NOT APPLE)

endif()

# Add files to the library
add_library(${PROJECT_NAME} SHARED ${PROJECT_FILES})

# Set version of library
set_target_properties(${PROJECT_NAME} PROPERTIES
                        VERSION ${PROJECT_VERSION}
                        SOVERSION ${PROJECT_VERSION_MAJOR})

# Link needed libraries
## No libraries needed

# Compile needed definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE LIBRA_LIBRARY_BUILD)

# Definition which depends on options
# Ex :
# if(EXT_OPT_LIBRA_XYZ)
#   target_compile_definitions(${PROJECT_NAME} PRIVATE LIBRA_ENABLE_XYZ)
# endif()

# Directories to includes
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
