/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_CORE_MUTEX_HPP
#define ZERO_CORE_MUTEX_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::core::IMutex
#ifndef ZERO_CORE_I_MUTEX_HXX
#include <zero/core/async/IMutex.hxx>
#endif /// !ZERO_CORE_I_MUTEX_HXX

// Include zero::atomic
#ifndef ZERO_CONFIG_ATOMIC_HPP
#include <zero/core/configs/zero_atomic.hpp>
#endif /// !ZERO_CONFIG_ATOMIC_HPP

// Include STL mutex
#include <mutex>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // Mutex
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        /*!
         * @brief Mutex wrapper for STL mutex API
         * @version 1.3
         * @author c0de4un
         * @since 28.01.2023
        */
        ZERO_API class Mutex final : public zIMutex
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

            zABool     mLocked;
            std::mutex mMutex;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DELETED
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            Mutex(const Mutex&) noexcept            = delete;
            Mutex& operator=(const Mutex&) noexcept = delete;
            Mutex(Mutex&&) noexcept                 = delete;
            Mutex& operator=(Mutex&&) noexcept      = delete;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTOR & DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
             * @throw no exceptions
            */
            explicit Mutex() ZERO_NOEXCEPT;

            /*!
             * @throw no exception
            */
            virtual ~Mutex() ZERO_NOEXCEPT;

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
            virtual bool isLocked() final;

            /**
             * @brief
             * Returns native handler
             *
             * @thread_safety not thread-safe
             * @throws no exception
            **/
            virtual void* native_handle() ZERO_NOEXCEPT final;

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
            virtual bool try_lock() ZERO_NOEXCEPT final;

            /**
             * @brief
             * Lock this mutex
             *
             * @thread_safety thread-safe (atomic, no locks)
             * @throws can throw exception (self-lock, etc)
            **/
            virtual void lock() final;

            /**
             * @brief
             * Unlock this mutex
             *
             * @thread_safety thread-safe (atomics, no locks)
             * @throws no exception
            **/
            virtual void unlock() ZERO_NOEXCEPT final;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// zero::core::Mutex

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::core

} /// zero

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_CORE_MUTEX_HPP
