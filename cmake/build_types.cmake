# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

if ( NOT DEFINED ZERO_BUILD_TYPES )
    if ( ${CMAKE_BUILD_TYPE} STREQUAL "Debug" )
        message ( STATUS "${PROJECT_NAME} - DEBUG-Mode enabled" )

        set ( ZERO_BUILD_TYPE "debug" )
        set ( ZERO_DEBUG ON )
        add_definitions ( -DZERO_DEBUG=1 )
    else ( ${CMAKE_BUILD_TYPE} STREQUAL "Debug" )
        message ( STATUS "${PROJECT_NAME} - DEBUG-Mode disabled" )

        set ( ZERO_BUILD_TYPE "release" )
        set ( ZERO_DEBUG OFF )
        add_definitions ( -DZERO_DEBUG=0 )
    endif ( ${CMAKE_BUILD_TYPE} STREQUAL "Debug" )

    set( NOT DEFINED ZERO_BUILD_TYPES TRUE )
endif ( NOT DEFINED ZERO_BUILD_TYPES )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
