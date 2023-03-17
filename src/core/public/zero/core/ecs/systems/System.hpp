/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_ECS_SYSTEM_HPP
#define ZERO_ECS_SYSTEM_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::ecs::ISystem
#ifndef ZERO_ECS_I_SYSTEM_HXX
#include <zero/core/ecs/systems/ISystem.hxx>
#endif /// !ZERO_ECS_I_SYSTEM_HXX

// Include zero::mutex
#ifndef ZERO_CONFIG_MUTEX_HPP
#include <zero/core/configs/zero_mutex.hpp>
#endif /// !ZERO_CONFIG_MUTEX_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace ecs
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // System
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        /*!
           \brief Base System class
           \version 1.2
           \authors c0de4un
           \since 12.03.2023
        */
        ZERO_API class System : public zISystem
        {

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // META
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            ZERO_CLASS

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // TYPES
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            using state_t = z_uint_8_t;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTANTS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
               \brief System states
            */
            enum class EState : state_t
            {
                NONE     = 0,
                STARTING = 1,
                RUNNING  = 2,
                PAUSING  = 3,
                PAUSED   = 4,
                STOPPING = 5
            };

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        private:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            static ObjectID generateID();

            static void releaseID(const ObjectID id);

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        protected:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // FIELDS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            EState         mState;
            const TypeID   mTypeID;
            const ObjectID mID;
            mutable zMutex mStateMutex;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTORS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
               \param typeId Type-ID
               \throws can throw exceptions
            */
            explicit System(const TypeID typeId);

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DELETED
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            System(const System&)            = delete;
            System& operator=(const System&) = delete;
            System(System&&)                 = delete;
            System& operator=(System&&)      = delete;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
               \throws nothing
            */
            virtual ~System() ZERO_NOEXCEPT;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // GETTERS & SETTERS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
               \throws nothing
               \return type-id
            */
            virtual TypeID getTypeID() const noexcept final;

            /*!
               \throws nothing
               \return id
            */
            virtual ObjectID getID() const noexcept final;

            /*!
               \thread_safety thread-safe
               \throws nothing
            */
            virtual bool isStarted() const ZERO_NOEXCEPT final;

            /*!
               \thread_safety thread-safe
               \throws nothing
            */
            virtual bool isPaused() const ZERO_NOEXCEPT final;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS.ISystem
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
               \brief Start or Resume System
               \thread_safety thread-safe (locks)
               \return
               < 0 if error
               0 if failed
               > 0 if OK
               \throws can throw exception
            */
            virtual z_int_8_t Start() final;

            /*!
             * @brief Pause System
             * @thread_safety - thread-safe
             * @return > 0 if OK, < 0 if error, 0 if failed
             * @throws can throw exception
            */
            virtual z_int_8_t Pause() final;

            /*!
               \brief Resume System. Same as calling Start after Stop()
               \return
               < 0 if error
               0 if failed
               > 0 if OK
            */
            virtual z_int_8_t Resume() final;

            /*!
             * @brief 
            */
            virtual void Stop() ZERO_NOEXCEPT final;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// zero::ecs::System

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::ecs

} /// zero

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_ECS_SYSTEM_HPP
