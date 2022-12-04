# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# Dirs
set( ZERO_SRC_DIR "${ZERO_DIR}/src" )
set( ZERO_TESTS_DIR "${ZERO_DIR}/tests" )
set( ZERO_CORE_DIR "${ZERO_SRC_DIR}/core" )
set( ZER_CMAKE_DIR "${ZERO_DIR}/cmake" )

# Sources
if ( NOT DEFINED ZERO_HEADERS )
    set( ZERO_HEADERS "" )
    set( ZERO_SOURCES "" )
endif ( NOT DEFINED ZERO_HEADERS )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
