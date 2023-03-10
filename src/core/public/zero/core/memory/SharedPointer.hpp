/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_CORE_SHARED_POINTER_HPP
#define ZERO_CORE_SHARED_POINTER_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::memory
#ifndef ZERO_CONFIG_MEMORY_HPP
#include <zero/core/configs/zero_memory.hpp>
#endif /// !ZERO_CONFIG_MEMORY_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // SharedPointer
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        /*!
            \brief Simple SharedPointer implementation. Compatable with STL shared_ptr API
            \date 22.01.2023
            \author c0de4un
            \version 0.1
        */
        template <typename T>
        class SharedPointer final
        {

        private:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // FIELDS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            T* mAddress;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            inline void setRef(T* const pAddress)
            {
                mAddress = pAddress;

                zMemory* memoryManager(zMemory::getInstance());
                memoryManager->registerReferenceUser(pAddress);
            }

            inline void unref()
            {
                if (mAddress)
                {
                    zMemory* memoryManager(zMemory::getInstance());
                    memoryManager->unregisterReferenceUser(mAddress, mDeleter, mAllocator);

                    mAddress = nullptr;
                }
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DELETED
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            SharedPointer(SharedPointer&&)            = delete;
            SharedPointer& operator=(SharedPointer&&) = delete;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
             
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTORS & DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
                \brief SharedPointer constructor
                \date 22.01.2023
                \param address|nullptr address to manage
                \param pDeleter|nullptr deleter
                \param pAlloc|nullptr allocator to use
            */
            explicit SharedPointer (
                T* const address = nullptr
            )
                :
                mAddress(nullptr)
            {
                setRef(address);
            }

            SharedPointer(SharedPointer& other)
                :
                mAddress(other.mAddress)
            {
                if (other.mAddress)
                    setRef(other.mAddress);
            }

            ~SharedPointer() ZERO_NOEXCEPT
            {
                if (mAddress)
                {
                    try { unref(); }
                    catch (...) {}
                }
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            T* get() const ZERO_NOEXCEPT
            { return mAddress; }

            unsigned int use_count() const
            {
                zMemory* memoryManager(zMemory::getInstance());

                return memoryManager ? memoryManager->countReferenceUsers(mAddress) : 0;
            }

            void reset(T* const pAddress = nullptr)
            {
                if (pAddress === mAddress)
                    return;

                if (mAddress)
                    unref();

                if (pAddress)
                    setRef(pAddress);
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // OPERATORS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            T& operator*() const ZERO_NOEXCEPT
            { return *mAddress; }

            T* operator->() const ZERO_NOEXCEPT
            { return mAddress; }

            void operator=(T* const pAddress) ZERO_NOEXCEPT
            { reset(pAddress); }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// zero::core::SharedPointer

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::core

} /// zero

template <typename T>
using zShared = zero::core::SharedPointer<T>;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_CORE_SHARED_POINTER_HPP
