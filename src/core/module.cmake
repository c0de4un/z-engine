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
    "${ZERO_CORE_PUBLIC}configs/zero_atomic.hpp"
    "${ZERO_CORE_PUBLIC}configs/zero_debug.hpp"
    "${ZERO_CORE_PUBLIC}configs/zero_map.hpp"
    "${ZERO_CORE_PUBLIC}configs/zero_memory.hpp"
    "${ZERO_CORE_PUBLIC}configs/zero_mutex.hpp"
    "${ZERO_CORE_PUBLIC}configs/zero_numeric.hpp"
    "${ZERO_CORE_PUBLIC}configs/zero_platform.hpp"
    "${ZERO_CORE_PUBLIC}configs/zero_types.hpp"
    "${ZERO_CORE_PUBLIC}configs/zero_vector.hpp"
    # APPLICATION
    "${ZERO_CORE_PUBLIC}app/Application.hpp"
    # GAME
    "${ZERO_CORE_PUBLIC}game/IGame.hxx"
    "${ZERO_CORE_PUBLIC}game/Game.hpp"
    # ASYNC
    "${ZERO_CORE_PUBLIC}async/BaseLock.hpp"
    "${ZERO_CORE_PUBLIC}async/IMutex.hxx"
    "${ZERO_CORE_PUBLIC}async/ISharedMutex.hxx"
    "${ZERO_CORE_PUBLIC}async/ILock.hxx"
    "${ZERO_CORE_PUBLIC}async/Mutex.hpp"
    "${ZERO_CORE_PUBLIC}async/SpinLock.hpp"
    # MEMORY
    "${ZERO_CORE_PUBLIC}memory/IAllocator.hxx"
    "${ZERO_CORE_PUBLIC}memory/MemoryManager.hpp"
    "${ZERO_CORE_PUBLIC}memory/SharedPointer.hpp"
    # METRICS
    "${ZERO_CORE_PUBLIC}metrics/log/ELogLevel.hpp"
    "${ZERO_CORE_PUBLIC}metrics/log/ILogger.hxx"
    "${ZERO_CORE_PUBLIC}metrics/log/Log.hpp"
    # ECS
    "${ZERO_CORE_PUBLIC}ecs/types/IDStorage.hpp"
    "${ZERO_CORE_PUBLIC}ecs/components/Component.hpp"
    "${ZERO_CORE_PUBLIC}ecs/components/ComponentsManager.hpp"
    "${ZERO_CORE_PUBLIC}ecs/entities/IEntity.hxx"
    "${ZERO_CORE_PUBLIC}ecs/entities/Entity.hpp"
    "${ZERO_CORE_PUBLIC}ecs/entities/EntitiesManager.hpp"
    "${ZERO_CORE_PUBLIC}ecs/events/IEvent.hxx"
    "${ZERO_CORE_PUBLIC}ecs/events/Event.hpp"
    "${ZERO_CORE_PUBLIC}ecs/events/EventsManager.hpp"
    "${ZERO_CORE_PUBLIC}ecs/systems/ISystem.hxx"
    "${ZERO_CORE_PUBLIC}ecs/systems/System.hpp"
    "${ZERO_CORE_PUBLIC}ecs/systems/SystemsManager.hpp"
    "${ZERO_CORE_PUBLIC}ecs/types/types.hpp"
    "${ZERO_CORE_PUBLIC}ecs/ecs.hpp"
    # PCH
    "${ZERO_CORE_PUBLIC}zero.hpp"
    ${ZERO_HEADERS} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_SOURCES
    # APPLICATION
    "${ZERO_CORE_PRIVATE}app/Application.cpp"
    # GAME
    "${ZERO_CORE_PRIVATE}game/Game.cpp"
    # ASYNC
    "${ZERO_CORE_PRIVATE}async/BaseLock.cpp"
    "${ZERO_CORE_PRIVATE}async/Mutex.cpp"
    "${ZERO_CORE_PRIVATE}async/SpinLock.cpp"
    # MEMORY
    "${ZERO_CORE_PRIVATE}memory/MemoryManager.cpp"
    "${ZERO_CORE_PRIVATE}memory/SharedPointer.cpp"
    # METRICS
    "${ZERO_CORE_PRIVATE}metrics/log/Log.cpp"
    # ECS
    "${ZERO_CORE_PRIVATE}ecs/components/ComponentsManager.cpp"
    "${ZERO_CORE_PRIVATE}ecs/entities/Entity.cpp"
    "${ZERO_CORE_PRIVATE}ecs/entities/EntitiesManager.cpp"
    "${ZERO_CORE_PRIVATE}ecs/events/Event.cpp"
    "${ZERO_CORE_PRIVATE}ecs/events/EventsManager.cpp"
    "${ZERO_CORE_PRIVATE}ecs/systems/System.cpp"
    "${ZERO_CORE_PRIVATE}ecs/systems/SystemsManager.cpp"
    "${ZERO_CORE_PRIVATE}ecs/ecs.cpp"
    # PCH
    "${ZERO_CORE_PRIVATE}zero.cpp"
    ${ZERO_SOURCES} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
