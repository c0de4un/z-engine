# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_CORE_PUBLIC "${ZERO_CORE_DIR}/public/zero/core/" )
set( ZERO_CORE_PRIVATE "${ZERO_CORE_DIR}/private/zero/core/" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_HEADERS
    # CONFIGS
    "${ZERO_CORE_PUBLIC}configs/zero_platform.hpp"
    "${ZERO_CORE_PUBLIC}configs/zero_api.hpp"
    # APPLICATION
    "${ZERO_CORE_PUBLIC}app/Application.hpp"
    # PCH
    "${ZERO_CORE_PUBLIC}zero.hpp"
    ${ZERO_HEADERS} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_SOURCES
    # APPLICATION
    "${ZERO_CORE_PRIVATE}app/Application.cpp"
    # PCH
    "${ZERO_CORE_PRIVATE}zero.cpp"
    ${ZERO_SOURCES} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
