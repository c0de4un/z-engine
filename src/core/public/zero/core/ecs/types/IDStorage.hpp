/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_ECS_ID_STORAGE_HPP
#define ZERO_ECS_ID_STORAGE_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::mutex
#ifndef ZERO_CONFIG_MUTEX_HPP
#include <zero/core/configs/zero_mutex.hpp>
#endif /// !ZERO_CONFIG_MUTEX_HPP

// Include zero::map
#ifndef ZERO_CONFIG_MAP_HPP
#include <zero/core/configs/zero_map.hpp>
#endif /// !ZERO_CONFIG_MAP_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace ecs
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // IDStorage
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        /*!
           \brief Thread-safe ids storage for ecs
           \version 1.2
           \since 11.03.2023
           \authors c0de4un
        */
        template <typename id_t>
        ZERO_API class IDStorage
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
            // TYPES
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            using ids_map_t = zMap<id_t, bool>;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // FIELDS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            zMutex           mMutex;
            ids_map_t        mIDs;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DELETED
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            IDStorage(const IDStorage&)            = delete;
            IDStorage& operator=(const IDStorage&) = delete;
            IDStorage(IDStorage&&)                 = delete;
            IDStorage& operator=(IDStorage&&)      = delete;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTORS & DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
               \param cap initial capacity
               \throws bad_alloc
            */
            explicit IDStorage()
                :
                mMutex(),
                mIDs()
            {
            }

            /*!
               \throws nothing
            */
            IDStorage::~IDStorage() ZERO_NOEXCEPT = default;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
               \thred_safety spinner lock used
               \return unique id
               \throws mutex, bad_alloc
            */
            id_t generateID()
            {
                id_t result(0);

                zSpinLock lock(&mMutex);

                const auto beginIter(mIDs.cbegin());
                const auto endIter(mIDs.cend());
                
                //ids_map_t::iterator iter(mIDs.begin());
                bool isReserved(true);
                for (auto iter = mIDs.begin(); iter != endIter; iter++)
                {
                    isReserved = iter->second;
                    if (!isReserved) {
                        result = iter->first;
                        break;
                    }
                }

                if (!result) {
                    result = mIDs.size() + 1;
                }

                mIDs[result] = true;

                return result;
            }

            void releaseID(const id_t id)
            {
                zSpinLock lock(&mMutex);

                mIDs[id] = false;
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// zero::ecs::IDStorage

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::ecs

} /// zero

template <typename T>
using zIDStorage = zero::ecs::IDStorage<T>;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_ECS_ID_STORAGE_HPP
