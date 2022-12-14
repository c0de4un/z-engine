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
    "${ZERO_CORE_PUBLIC}configs/zero_api.hpp"
    "${ZERO_CORE_PUBLIC}configs/zero_numeric.hpp"
    "${ZERO_CORE_PUBLIC}configs/zero_platform.hpp"
    # APPLICATION
    "${ZERO_CORE_PUBLIC}app/Application.hpp"
    # METRICS
    "${ZERO_CORE_PUBLIC}metrics/log/ELogLevel.hpp"
    "${ZERO_CORE_PUBLIC}metrics/log/ILogger.hxx"
    "${ZERO_CORE_PUBLIC}metrics/log/Log.hpp"
    # PCH
    "${ZERO_CORE_PUBLIC}zero.hpp"
    ${ZERO_HEADERS} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_SOURCES
    # APPLICATION
    "${ZERO_CORE_PRIVATE}app/Application.cpp"
    # METRICS
    "${ZERO_CORE_PRIVATE}metrics/log/Log.cpp"
    # PCH
    "${ZERO_CORE_PRIVATE}zero.cpp"
    ${ZERO_SOURCES} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
