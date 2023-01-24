/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_CORE_I_LOCK_HXX
#define ZERO_CORE_I_LOCK_HXX

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::api
#ifndef ZERO_CONFIG_API_HPP
#include <zero/core/configs/zero_api.hpp>
#endif /// !ZERO_CONFIG_API_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// FORWARD-DECLARATIONS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Forward declare zero::core::IMutex
#ifndef ZERO_CORE_I_MUTEX_DECL
#define ZERO_CORE_I_MUTEX_DECL
namespace zero { namespace core { class IMutex; } }
using zIMutex = zero::core::IMutex;
#endif /// !ZERO_CORE_I_MUTEX_DECL

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // ILock
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        /**
         * @brief Lock contract
         * @date 22.01.2023
         * @author c0de4un
         * @version 1.3
        **/
        class ILock
        {

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @brief
             * ILock destructor.
             * 
             * @throws - no exceptions.
            **/
            virtual ~ILock() ZERO_NOEXCEPT = default;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // GETTERS & SETTERS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @brief
             * Check if this lock is locked.
             *
             * @thread_safety - atomic-flag used.
             * @throws - no exceptions.
            **/
            virtual bool isLocked() ZERO_NOEXCEPT = 0;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @param pMutex mutex to use (switch to)
             * @return 'true' if locked, 'false' if failed
             * @throw can throw exception
            **/
            virtual bool try_lock(zIMutex* const pMutex = nullptr) = 0;

            /**
             * @param pMutex mutex to use (switch to)
             * @throw can throw exception
            **/
            virtual void lock(zIMutex* const pMutex = nullptr) = 0;

            /**
             * @throw can throw exception
            **/
            virtual void unlock() ZERO_NOEXCEPT = 0;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// zero::core::ILock

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::core

} /// zero

#define ZERO_CORE_I_LOCK_DECL

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif /// !ZERO_CORE_I_LOCK_HXX
