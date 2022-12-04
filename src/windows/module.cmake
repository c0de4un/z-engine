# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_WIN_DIR "${ZERO_SRC_DIR}/windows" )
set( ZERO_WIN_PUBLIC "${ZERO_WIN_DIR}/public/zero/windows/" )
set( ZERO_WIN_PRIVATE "${ZERO_WIN_DIR}/private/zero/windows/" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_HEADERS
    # METRICS
    "${ZERO_WIN_PUBLIC}metrics/log/WinLogger.hpp"
    # PCH
    "${ZERO_WIN_PUBLIC}zero_win.hpp"
    ${ZERO_HEADERS} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_SOURCES
    # METRICS
    "${ZERO_WIN_PRIVATE}metrics/log/WinLogger.cpp"
    # PCH
    "${ZERO_WIN_PRIVATE}zero_win.cpp"
    ${ZERO_SOURCES} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
