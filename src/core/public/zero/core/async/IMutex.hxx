/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_CORE_I_MUTEX_HXX
#define ZERO_CORE_I_MUTEX_HXX

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::api
#ifndef ZERO_CONFIG_API_HPP
#include <zero/core/configs/zero_api.hpp>
#endif /// !ZERO_CONFIG_API_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // IMutex
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        /*!
            \brief Mutex contract

            Contains STL-compatable API
            \date 22.01.2023
            \author c0de4un
            \version 1.0
        */
        ZERO_API class IMutex
        {

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // META
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            ZERO_INTERFACE

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
             * @throw no exception
            */
            virtual ~IMutex() ZERO_NOEXCEPT = default;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // GETTERS & SETTERS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @brief
             * Check if this mutex is locked
             *
             * @thread_safety thread-safe (atomic, not thread-lock)
             * @throws no exception
            **/
            virtual bool isLocked() = 0;

            /**
             * @brief
             * Returns native handler
             *
             * @thread_safety not thread-safe
             * @throws no exception
            **/
            virtual void* native_handle() ZERO_NOEXCEPT = 0;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @brief
             * Tries to lock this mutex
             *
             * @thread_safety thread-safe (atomic, not thread-lock)
             * @returns 'true' if locked, 'false' if failed
             * @throws no exception
            **/
            virtual bool try_lock() ZERO_NOEXCEPT = 0;

            /**
             * @brief
             * Lock this mutex
             *
             * @thread_safety thread-safe (atomic, no locks)
             * @throws can throw exception (self-lock, etc)
            **/
            virtual void lock() = 0;

            /**
             * @brief
             * Unlock this mutex
             *
             * @thread_safety thread-safe (atomics, no locks)
             * @throws no exception
            **/
            virtual void unlock() ZERO_NOEXCEPT = 0;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// zero::core::IMutex

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::core

} /// zero


#define ZERO_CORE_I_MUTEX_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_CORE_I_MUTEX_HXX
