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
include( "${ZERO_CORE_DIR}/core.cmake" )

# Windows

# Android

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