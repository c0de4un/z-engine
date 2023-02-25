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

// HEADER
#ifndef ZERO_CORE_MUTEX_HPP
#include <zero/core/async/Mutex.hpp>
#endif /// !ZERO_CORE_MUTEX_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Mutex
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Mutex::Mutex () ZERO_NOEXCEPT
            :
            mLocked(false),
            mLockedFlag(ATOMIC_FLAG_INIT),
            mMutex()
        {
        }

        Mutex::~Mutex() ZERO_NOEXCEPT = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GETTERS & SETTERS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool Mutex::isLocked()
        {
            return mLocked;
        }

        Mutex::handle_t Mutex::native_handle() ZERO_NOEXCEPT
        {
            return &mMutex;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool Mutex::try_lock() ZERO_NOEXCEPT
        {
            if (isLocked())
                return true;

            if (!mLockedFlag.test_and_set())
            {
                if (mMutex.try_lock())
                    mLocked = true;

                return true;
            }

            return false;
        }

        void Mutex::lock()
        {
            if (!mLockedFlag.test_and_set())
            {
                mLocked = true;
                mMutex.lock();
            }
        }

        void Mutex::unlock() ZERO_NOEXCEPT
        {
            if (!isLocked())
                return;

            try
            {
                mMutex.unlock();
            }
            catch (...)
            {
                // empty
            }

            mLockedFlag.clear();
            mLocked = false;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::core

} /// zero

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
