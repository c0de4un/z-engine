/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::core::MemoryManager
#ifndef ZERO_CORE_MEMORY_MANAGER_HPP
#include <zero/core/memory/MemoryManager.hpp>
#endif /// !ZERO_CORE_MEMORY_MANAGER_HPP

// Include zero::mutex
#ifndef ZERO_CONFIG_MUTEX_HPP
#include <zero/core/configs/zero_mutex.hpp>
#endif /// !ZERO_CONFIG_MUTEX_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// MemoryManager
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // FIELDS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        zIMutex* MemoryManager::mInstanceMutex(new zero::core::Mutex());

        MemoryManager* MemoryManager::mInstance(nullptr);

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        MemoryManager::MemoryManager()                = default;
        MemoryManager::~MemoryManager() ZERO_NOEXCEPT = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        MemoryManager* MemoryManager::Initialize() ZERO_NOEXCEPT
        {
            zThreadLock lock(mInstanceMutex);

            if (mInstance)
            {
                // Guarded-Block
                try
                {
                    mInstance = new MemoryManager();
                }
                catch (...)
                {
                    return nullptr;
                }
            }

            return mInstance;
        }

        void MemoryManager::Terminate() ZERO_NOEXCEPT
        {
            zThreadLock lock(mInstanceMutex);

            if (!mInstance)
                return;

            delete mInstance;
            mInstance = nullptr;
        }

        MemoryManager* MemoryManager::getInstance() noexcept
        { return mInstance; }

        z_uint_8_t MemoryManager::registerAllocator(zIAllocator* const pAllocator) ZERO_NOEXCEPT
        {
            // @TODO: MemoryManager::registerAllocator()
            return 0;
        }

        void MemoryManager::unregisterAllocator(const z_uint_8_t id) ZERO_NOEXCEPT
        {
            // @TODO: MemoryManager::unregisterAllocator()
        }

        zIAllocator* MemoryManager::getAllocator(const z_uint_8_t id) const ZERO_NOEXCEPT
        {
            // @TODO: MemoryManager::getAllocator()
            return nullptr;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::core

} /// zero

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
