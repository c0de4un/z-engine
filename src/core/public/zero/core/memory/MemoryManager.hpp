/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_CORE_MEMORY_MANAGER_HPP
#define ZERO_CORE_MEMORY_MANAGER_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::memory
#ifndef ZERO_CONFIG_MEMORY_HPP
#include <zero/core/configs/zero_memory.hpp>
#endif /// !ZERO_CONFIG_MEMORY_HPP

// Include zero::numeric
#ifndef ZERO_CONFIG_NUMERIC_HPP
#include <zero/core/configs/zero_numeric.hpp>
#endif /// !ZERO_CONFIG_NUMERIC_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// FORWARD-DECLARATIONS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Forward declare zero::core::IMutex
#ifndef ZERO_CORE_I_MUTEX_DECL
#define ZERO_CORE_I_MUTEX_DECL
namespace zero { namespace core { class IMutex; } }
using zIMutex = zero::core::IMutex;
#endif /// !ZERO_CORE_I_MUTEX_DECL

// Include zero::core::IAllocator
#ifndef ZERO_CORE_I_ALLOCATOR_DECL
#define ZERO_CORE_I_ALLOCATOR_DECL
namespace zero { namespace core { class IAllocator; } }
using zIAllocator = zero::core::IAllocator;
#endif /// !ZERO_CORE_I_ALLOCATOR_DECL

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // MemoryManager
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        /*!
            \brief Base memory management class

            Memory management is based around blocks, resources and allocators
            \date 22.01.2023
            \author c0de4un
            \version 0.1
        */
        ZERO_API class MemoryManager final
        {

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // META
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            ZERO_CLASS

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        private:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // FIELDS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            static zIMutex*       mInstanceMutex;

            static MemoryManager* mInstance;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
               \@throw bad_alloc
            */
            explicit MemoryManager();

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DELETED
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            MemoryManager(const MemoryManager&)             = delete;
            MemoryManager& operator=(const MemoryManager&)  = delete;
            MemoryManager(MemoryManager&&)                  = delete;
            MemoryManager& operator=(MemoryManager&&)       = delete;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
               \throws nothing
            */
            ~MemoryManager() ZERO_NOEXCEPT;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
             * @brief Initialize MemoryManager
             * @throw no exception
            */
            static MemoryManager* Initialize() ZERO_NOEXCEPT;

            /*!
             * @brief Terminate Memory manager
             * @throw no exception
            */
            static void Terminate() ZERO_NOEXCEPT;

            /*!
             * @brief Register allocator
             * @param pAllocator allocator to register
             * @return allocator id
             * @throw no exception
            */
            z_uint_8_t registerAllocator(zIAllocator* const pAllocator) ZERO_NOEXCEPT;

            /*!
             * @brief Unregister allocator
             * @param id allocator id
             * @throw no exception
            */
            void unregisterAllocator(const z_uint_8_t id) ZERO_NOEXCEPT;

            /*!
             * @param allocType allocator id
             * @throw no exception
            */
            zIAllocator* getAllocator(const z_uint_8_t id) const ZERO_NOEXCEPT;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// zero::core::MemoryManager

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::core

} /// zero

using zMemory = zero::core::MemoryManager;
#define ZERO_CORE_MEMORY_MANAGER_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !ZERO_CORE_MEMORY_MANAGER_HPP
