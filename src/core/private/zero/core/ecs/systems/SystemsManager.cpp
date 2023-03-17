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
#ifndef ZERO_ECS_SYSTEMS_MANAGER_HPP
#include <zero/core/ecs/systems/SystemsManager.hpp>
#endif /// !ZERO_ECS_SYSTEMS_MANAGER_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// SystemsManager
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace ecs
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // FIELDS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        zMutex          SystemsManager::mInstanceMutex;
        SystemsManager* SystemsManager::mInstance(nullptr);

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTORS & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        SystemsManager::SystemsManager()
            :
            mIDStorageMutex(),
            mIDs()
        {
        }

        SystemsManager::~SystemsManager() ZERO_NOEXCEPT = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GETTERS & SETTERS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        SystemsManager* SystemsManager::getInstance()
        {
            zSpinLock lock(&mInstanceMutex);

            return mInstance;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void SystemsManager::Initialize()
        {
            zSpinLock lock(&mInstanceMutex);

            if (!mInstance)
                mInstance = new SystemsManager();
        }

        void SystemsManager::Terminate()
        {
            zSpinLock lock(&mInstanceMutex);

            if (mInstance)
            {
                delete mInstance;
                mInstance = nullptr;
            }
        }

        ObjectID SystemsManager::generateID()
        {
            zSpinLock lock(&mIDStorageMutex);

            return mIDs.generateID();
        }

        void SystemsManager::poolID(const ObjectID id)
        {
            zSpinLock lock(&mIDStorageMutex);

            mIDs.releaseID(id);
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
