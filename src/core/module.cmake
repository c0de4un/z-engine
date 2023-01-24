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
    "${ZERO_CORE_PUBLIC}configs/zero_memory.hpp"
    "${ZERO_CORE_PUBLIC}configs/zero_numeric.hpp"
    "${ZERO_CORE_PUBLIC}configs/zero_platform.hpp"
    # APPLICATION
    "${ZERO_CORE_PUBLIC}app/Application.hpp"
    # ASYNC
    "${ZERO_CORE_PUBLIC}async/BaseLock.hpp"
    "${ZERO_CORE_PUBLIC}async/IMutex.hxx"
    "${ZERO_CORE_PUBLIC}async/ILock.hxx"
    # MEMORY
    "${ZERO_CORE_PUBLIC}memory/IAllocator.hxx"
    "${ZERO_CORE_PUBLIC}memory/MemoryManager.hpp"
    "${ZERO_CORE_PUBLIC}memory/SharedPointer.hpp"
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
    # ASYNC
    "${ZERO_CORE_PRIVATE}async/BaseLock.cpp"
    # MEMORY
    "${ZERO_CORE_PRIVATE}memory/MemoryManager.cpp"
    "${ZERO_CORE_PRIVATE}memory/SharedPointer.cpp"
    # METRICS
    "${ZERO_CORE_PRIVATE}metrics/log/Log.cpp"
    # PCH
    "${ZERO_CORE_PRIVATE}zero.cpp"
    ${ZERO_SOURCES} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
