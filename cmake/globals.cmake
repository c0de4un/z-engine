# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# Dirs
set( ZENGINE_SRC_DIR "${ZENGINE_DIR}/src" )
set( ZENGINE_TESTS_DIR "${ZENGINE_DIR}/tests" )
set( ZENGINE_CORE_DIR "${ZENGINE_SRC_DIR}/core" )

# Sources
if ( NOT DEFINED ZENGINE_HEADERS )
    set( ZENGINE_HEADERS "" )
    set( ZENGINE_SOURCES "" )
endif ( NOT DEFINED ZENGINE_HEADERS )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
