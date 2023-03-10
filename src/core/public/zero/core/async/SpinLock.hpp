/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_CORE_SPIN_LOCK_HPP
#define ZERO_CORE_SPIN_LOCK_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::core::BaseLock
#ifndef ZERO_CORE_BASE_LOCK_HPP
#include "./BaseLock.hpp"
#endif /// !ZERO_CORE_BASE_LOCK_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // SpinLock
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        /*!
           \brief Spin lock implementation. Based on loading CPU core to avoid context switching
           (unlikely thread-wait etc).
           \version 1.2
           \authors c0de4un
           \since 10.03.2023
        */
        ZERO_API class SpinLock final : public zBaseLock
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
            // DELETED
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            SpinLock(const SpinLock&)            = delete;
            SpinLock& operator=(const SpinLock&) = delete;
            SpinLock(SpinLock&&)                 = delete;
            SpinLock& operator=(SpinLock&&)      = delete;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTANTS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            static constexpr const unsigned char MAX_SPIN = 240;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTORS & DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
               \param pMutex mutex contract instance to use
               \throws std::bad_alloc
            */
            explicit SpinLock(zIMutex* const pMutex) ZERO_NOEXCEPT;

            /*!
               \throws nothing
            */
            virtual ~SpinLock() ZERO_NOEXCEPT;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS.ILock
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /**
             * @param pMutex mutex to use (switch to)
             * @return 'true' if locked, 'false' if failed
             * @throw can throw exception
            **/
            virtual bool try_lock(zIMutex* const pMutex = nullptr) ZERO_NOEXCEPT final;

            /**
             * @param pMutex mutex to use (switch to)
             * @throw can throw exception
            **/
            virtual void lock(zIMutex* const pMutex = nullptr) final;

            /**
             * @throw can throw exception
            **/
            virtual void unlock() ZERO_NOEXCEPT final;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// zero::core::SpinLock

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::core

} /// zero

using zSpinLock = zero::core::SpinLock;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_CORE_SPIN_LOCK_HPP
