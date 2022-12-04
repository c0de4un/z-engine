# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

if ( NOT DEFINED ZERO_PLATFORM_DETECTED )

    if ( WIN32 OR WIN64 OR MINGW OR MING32 OR MINGW64 OR CYGWIN OR CYGWIN64 OR MSYS OR CMAKE_SYSTEM_NAME STREQUAL "Windows" )
        # Windows
        set( PLATFORM "windows" )
        set( ZERO_WINDOWS ON )
        add_definitions( -DZERO_WINDOWS=1 )
    elseif ( ANDROID OR $CMAKE_SYSTEM_NAME STREQUAL "Android" )
        # Android
        set( PLATFORM "android" )
        set( ZERO_ANDROID ON )
        add_definitions( -DZERO_ANDROID=1 )
    elseif ( APPLE OR CMAKE_SYSTEM_NAME STREQUAL "Darwin" )
        # Mac
        set( PLATFORM "mac" )
        set( ZERO_MAC ON )
        add_definitions( -DZERO_MAC=1 )
    elseif ( LINUX OR UNIX OR CMAKE_SYSTEM_NAME STREQUAL "Linux" OR CMAKE_SYSTEM_NAME STREQUAL "FreeBSD" OR CMAKE_SYSTEM_NAME STREQUAL "CrayLinuxEnvironment" )
        # Linux
        set( PLATFORM "linux" )
        set( ZERO_LINUX ON )
        add_definitions( -DZERO_LINUX=1 )
    elseif ( IOS )
        set( PLATFORM "ios" )
        set( ZERO_IOS ON )
        add_definitions( -DZERO_IOS=1 )
    else ( WIN32 OR WIN64 OR MINGW OR MING32 OR MINGW64 OR CYGWIN OR CYGWIN64 OR MSYS OR CMAKE_SYSTEM_NAME STREQUAL "Windows" ) # WINDOWS
        message( FATAL_ERROR "${PROJECT_NAME} - failed to detect target-platform, configuration required" )
    endif ( WIN32 OR WIN64 OR MINGW OR MING32 OR MINGW64 OR CYGWIN OR CYGWIN64 OR MSYS OR CMAKE_SYSTEM_NAME STREQUAL "Windows" ) # WINDOWS

    message ( STATUS "${PROJECT_NAME} - platform is ${PLATFORM}" )

    set( ZERO_PLATFORM_DETECTED ON )
    add_definitions( -DZERO_PLATFORM_DEFINED=1 )

endif ( NOT DEFINED ZERO_PLATFORM_DETECTED )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
