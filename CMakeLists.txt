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

project( ${ZENGINE_PROJECT_NAME} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# GLOBALS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include( "${ZENGINE_DIR}/cmake/globals.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# MODULES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Core
include( "${ZENGINE_CORE_DIR}/core.cmake" )

# Windows

# Android

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Build STATIC Library
add_library( zengine ${ZENGINE_HEADERS} ${ZENGINE_SOURCES} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# LINKING
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Core
target_include_directories( zengine PUBLIC "${ZENGINE_CORE_DIR}/public" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =