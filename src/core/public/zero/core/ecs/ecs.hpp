/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_ECS_HPP
#define ZERO_ECS_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::atomic
#ifndef ZERO_CONFIG_ATOMIC_HPP
#include <zero/core/configs/zero_atomic.hpp>
#endif /// !ZERO_CONFIG_ATOMIC_HPP

// Include ecs::types
#ifndef ZERO_ECS_TYPES_HPP
#include "./types/types.hpp"
#endif /// !ZERO_ECS_TYPES_HPP

// Include ecs::IDStorage
#ifndef ZERO_ECS_ID_STORAGE_HPP
#include <zero/core/ecs/types/IDStorage.hpp>
#endif /// !ZERO_ECS_ID_STORAGE_HPP

// Include ecs::SystemsManager
#ifndef ZERO_ECS_SYSTEMS_MANAGER_HPP
#include <zero/core/ecs/systems/SystemsManager.hpp>
#endif /// !ZERO_ECS_SYSTEMS_MANAGER_HPP

// Include ecs::System
#ifndef ZERO_ECS_SYSTEM_HPP
#include <zero/core/ecs/systems/System.hpp>
#endif /// !ZERO_ECS_SYSTEM_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace ecs
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // ECSEngine
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        /*!
           \brief ECSEngine wrapper about all ECS parts
           \version 1.0
           \authords c0de4un
           \since 12.03.2023
        */
        ZERO_API class ECSEngine final
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

            static std::atomic_flag  mInitialized;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTORS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            explicit ECSEngine();

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DELETED
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            ECSEngine(const ECSEngine&)            = delete;
            ECSEngine& operator=(const ECSEngine&) = delete;
            ECSEngine(ECSEngine&&)                 = delete;
            ECSEngine& operator=(ECSEngine&&)      = delete;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            ~ECSEngine() ZERO_NOEXCEPT;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            static void Initialize();
            static void Terminate();

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// zero::ecs::ECSEngine

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::ecs

} /// zero

using zECS = zero::ecs::ECSEngine;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_ECS_HPP
