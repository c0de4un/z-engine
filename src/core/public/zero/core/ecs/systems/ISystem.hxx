/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_ECS_I_SYSTEM_HXX
#define ZERO_ECS_I_SYSTEM_HXX

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::api
#ifndef ZERO_CONFIG_API_HPP
#include <zero/core/configs/zero_api.hpp>
#endif /// !ZERO_CONFIG_API_HPP

// Include ecs::types
#ifndef ZERO_ECS_TYPES_HPP
#include <zero/core/ecs/types/types.hpp>
#endif /// !ZERO_ECS_TYPES_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace ecs
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // ISystem
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        /*!
           \brief System contract
           \version 1.1
           \authors c0de4un
           \since 12.03.2023
        */
        ZERO_API class ISystem
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
               \throws nothing
            */
            virtual ~ISystem() ZERO_NOEXCEPT = default;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // GETTERS & SETTERS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
               \throws nothing
               \return type-id
            */
            virtual TypeID getTypeID() const noexcept = 0;

            /*!
               \throws nothing
               \return id
            */
            virtual ObjectID getID() const noexcept = 0;

            /*!
               \thread_safety thread-safe
               \throws nothing
            */
            virtual bool isStarted(const bool lock = true) const ZERO_NOEXCEPT = 0;

            /*!
               \thread_safety thread-safe
               \throws nothing
            */
            virtual bool isPaused(const bool lock = true) const ZERO_NOEXCEPT = 0;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
               \brief Start or Resume System
               \thread_safety thread-safe (locks)
               \return true if OK
               \throws can throw exception
            */
            virtual bool Start() = 0;

            /*!
             * @brief Pause System
             * @thread_safety - thread-safe
             * @throws can throw exception
            */
            virtual bool Pause() = 0;

            /*!
               \brief Resume System. Same as calling Start after Stop()
               \return
            */
            virtual bool Resume() = 0;

            /*!
             * @brief 
            */
            virtual void Stop() ZERO_NOEXCEPT = 0;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// zero::ecs::ISystem

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::ecs

} /// zero

using zISystem = zero::ecs::ISystem;
#define ZERO_ECS_I_SYSTEM_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_ECS_I_SYSTEM_HXX
