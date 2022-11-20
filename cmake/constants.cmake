# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMake
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZENGINE_PROJECT_NAME "zEngine" )

if ( NOT DEFINED PROJECT_CMAKE_VERSION )
    set( PROJECT_CMAKE_VERSION 3.22.1 )
endif ( NOT DEFINED PROJECT_CMAKE_VERSION )

set( ZENGINE_DIR ${CMAKE_CURRENT_SOURCE_DIR} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
