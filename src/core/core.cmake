# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZENGINE_CORE_PUBLIC "${ZENGINE_CORE_DIR}/public/zero/core/" )
set( ZENGINE_CORE_PRIVATE "${ZENGINE_CORE_DIR}/private/zero/core/" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZENGINE_HEADERS
    "${ZENGINE_CORE_PUBLIC}zero.hpp"
    ${ZENGINE_HEADERS} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZENGINE_SOURCES
    "${ZENGINE_CORE_PRIVATE}zero.cpp"
    ${ZENGINE_SOURCES} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
