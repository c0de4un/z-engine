# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# CMake Version
include( "cmake/constants.cmake" )
cmake_minimum_required(VERSION ${PROJECT_CMAKE_VERSION})

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

project( ${ZERO_PROJECT_NAME} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# GLOBALS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include( "${ZERO_DIR}/cmake/globals.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# MODULES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Core
include( "${ZERO_SRC_DIR}/core/module.cmake" )

# Windows
if ( PLATFORM STREQUAL "windows" )
    include( "${ZERO_SRC_DIR}/windows/module.cmake" )
endif ( PLATFORM STREQUAL "windows" )

# Linux
if ( PLATFORM STREQUAL "linux" )
    include( "${ZERO_SRC_DIR}/linux/module.cmake" )
endif ( PLATFORM STREQUAL "linux" )

# Android
if ( PLATFORM STREQUAL "android" )
    include( "${ZERO_SRC_DIR}/android/module.cmake" )
endif ( PLATFORM STREQUAL "android" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Build STATIC Library
add_library( zengine ${ZERO_HEADERS} ${ZERO_SOURCES} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# LINKING
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Core
target_include_directories( zengine PUBLIC "${ZERO_CORE_DIR}/public" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =