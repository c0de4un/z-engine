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
#ifndef ZERO_CORE_SPIN_LOCK_HPP
#include <zero/core/async/SpinLock.hpp>
#endif /// !ZERO_CORE_SPIN_LOCK_HPP

// Include zero::core::IMutex
#ifndef ZERO_CORE_I_MUTEX_HXX
#include <zero/core/async/IMutex.hxx>
#endif /// !ZERO_CORE_I_MUTEX_HXX

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// SpinLock
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTORS & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        SpinLock::SpinLock(zIMutex* const pMutex, const bool delayedLock)
            : BaseLock(pMutex, delayedLock)
        {
            if (pMutex && !delayedLock)
                lock(pMutex);
        }

        SpinLock::~SpinLock() ZERO_NOEXCEPT = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.ILock
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool SpinLock::try_lock(zIMutex* const pMutex) ZERO_NOEXCEPT
        {
            if (!mMutex->isLocked())
                return mMutex->try_lock();

            unsigned char triesCounter(0);
            while (triesCounter < MAX_SPIN)
            {
                triesCounter++;

                if (!mMutex->isLocked())
                    break;
            }

            return mMutex->try_lock();
        }

        void SpinLock::lock(zIMutex* const pMutex)
        {
            if (!mMutex->isLocked())
                mMutex->lock();

            unsigned char triesCounter(0);
            while (triesCounter < MAX_SPIN)
            {
                triesCounter++;

                if (!mMutex->isLocked())
                    break;
            }

            mMutex->lock();
        }

        void SpinLock::unlock() ZERO_NOEXCEPT
        {
            mMutex->unlock();
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::core

} /// zero

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
