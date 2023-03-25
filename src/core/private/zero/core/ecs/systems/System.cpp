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
#ifndef ZERO_ECS_SYSTEM_HPP
#include <zero/core/ecs/systems/System.hpp>
#endif /// !ZERO_ECS_SYSTEM_HPP

// Include ecs::SystemsManager
#ifndef ZERO_ECS_SYSTEMS_MANAGER_HPP
#include <zero/core/ecs/systems/SystemsManager.hpp>
#endif /// !ZERO_ECS_SYSTEMS_MANAGER_HPP

// DEBUG
#ifdef ZERO_DEBUG

// Include zero::debug
#ifndef ZERO_CONFIG_DEBUG_HPP
#include <zero/core/configs/zero_debug.hpp>
#endif // !ZERO_CONFIG_DEBUG_HPP

#endif
// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// System
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace ecs
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTORS & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        System::System(const TypeID typeId)
            :
            mState(EState::NONE),
            mTypeID(typeId),
            mID(generateID()),
            mStateMutex()
        {
#ifdef ZERO_DEBUG // DEBUG
            std::string msg("System::construct: type=");
            msg += std::to_string(mTypeID);
            msg += "; id=";
            msg += mID;
            zLog::Debug(msg.c_str());
#endif // DEBUG
        }

        System::~System() ZERO_NOEXCEPT
        {
#ifdef ZERO_DEBUG // DEBUG
            std::string msg("System::destruct: type=");
            msg += std::to_string(mTypeID);
            msg += "; id=";
            msg += mID;
            zLog::Debug(msg.c_str());
#endif // DEBUG

            if (isStarted(true))
                Stop();
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GETTERS & SETTERS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        TypeID System::getTypeID() const noexcept
        { return mTypeID; }

        ObjectID System::getID() const noexcept
        { return mID; }

        bool System::isStarted(const bool lock) const ZERO_NOEXCEPT
        {
            bool result(false);

            if (lock)
            {
                zSpinLock lock(&mStateMutex);

                result = mState > EState::NONE && mState < EState::STOPPING;
            }
            else
                result = mState > EState::NONE && mState < EState::STOPPING;

            return result;
        }

        bool System::isPaused(const bool lock) const ZERO_NOEXCEPT
        {
            bool result(false);

            if (lock)
            {
                zSpinLock lock(&mStateMutex);

                result = mState == EState::PAUSING || mState == EState::PAUSED;
            }
            else
                result = mState == EState::PAUSING || mState == EState::PAUSED;

            return result;
        }

        void System::setState(const EState state, const bool shouldLock)
        {
            if (shouldLock)
            {
                zSpinLock lock(&mStateMutex);

                mState = state;
            }
            else
                mState = state;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        ObjectID System::generateID()
        {
            zSystems* const systemsManager(zSystems::getInstance());

            return systemsManager->generateID();
        }

        void System::releaseID(const ObjectID id)
        {
            zSystems* const systemsManager(zSystems::getInstance());

            systemsManager->poolID(id);
        }

        bool System::onStart()
        {
            throw std::exception("System::onStart: not implemented");
        }

        bool System::onPause()
        {
            throw std::exception("System::onPause: not implemented");
        }

        bool System::onResume()
        {
            throw std::exception("System::onResume: not implemented");
        }

        void System::onStop()
        {
            throw std::exception("System::onStop: not implemented");
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // OVERRIDE.ISystem
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool System::Start()
        {
            try
            {
#ifdef ZERO_DEBUG // DEBUG
                std::string msg("System::Start: type=");
                msg += std::to_string(mTypeID);
                msg += "; id=";
                msg += mID;
                zLog::Debug(msg.c_str());
#endif // DEBUG
                zSpinLock lock(&mStateMutex);

                if (isPaused(false))
                {
                    lock.unlock();

                    return Resume();
                }

                if (isStarted(false))
                {
#ifdef ZERO_DEBUG // DEBUG
                    msg = "System::Start: type=";
                    msg += std::to_string(mTypeID);
                    msg += "; id=";
                    msg += mID;
                    msg += ";: already started";
                    zLog::Warning(msg.c_str());
#endif // DEBUG

                    return true;
                }

                setState(EState::STARTING, false);
                lock.unlock();

                return onStart();
            }
#ifdef ZERO_DEBUG // DEBUG
            catch (const std::exception& _exception)
            {
                std::string logMsg("System::Start: ");
                logMsg += _exception.what();

                zLog::Error(logMsg.c_str());
            }
#endif // DEBUG
            catch (...)
            {
#ifdef ZERO_DEBUG // DEBUG
                zLog::Error("System::Start: unknown error");
#endif // DEBUG
            }

            return false;
        }

        bool System::Pause()
        {
            try
            {
#ifdef ZERO_DEBUG // DEBUG
                std::string msg("System::Pause: type=");
                msg += std::to_string(mTypeID);
                msg += "; id=";
                msg += mID;
                zLog::Debug(msg.c_str());
#endif // DEBUG

                zSpinLock lock(&mStateMutex);
                if (isPaused(false))
                    return true;

                setState(EState::PAUSING, false);
                lock.unlock();

                return onPause();
            }
#ifdef ZERO_DEBUG // DEBUG
            catch (const std::exception& _exception)
            {
                std::string logMsg("System::Pause: ");
                logMsg += _exception.what();

                zLog::Error(logMsg.c_str());
            }
#endif // DEBUG
            catch (...)
            {
#ifdef ZERO_DEBUG // DEBUG
                zLog::Error("System::Pause: unknown error");
#endif // DEBUG
            }

            return false;
        }

        bool System::Resume()
        {
            try
            {
#ifdef ZERO_DEBUG // DEBUG
                std::string msg("System::Resume: type=");
                msg += std::to_string(mTypeID);
                msg += "; id=";
                msg += mID;
                zLog::Debug(msg.c_str());
#endif // DEBUG

                zSpinLock lock(&mStateMutex);

                if (isStarted(false))
                {
#ifdef ZERO_DEBUG // DEBUG
                    msg = "System::Resume: type=";
                    msg += std::to_string(mTypeID);
                    msg += "; id=";
                    msg += mID;
                    msg += ";: already started";
                    zLog::Warning(msg.c_str());
#endif // DEBUG
                    return false;
                }

                if (isStarted(false))
                    return true;

                setState(EState::STARTING, false);
                lock.unlock();

                return onResume();
            }
#ifdef ZERO_DEBUG // DEBUG
            catch (const std::exception& _exception)
            {
                std::string logMsg("System::Resume: ");
                logMsg += _exception.what();

                zLog::Error(logMsg.c_str());
            }
#endif // DEBUG
            catch (...)
            {
#ifdef ZERO_DEBUG // DEBUG
                zLog::Error("System::Resume: unknown error");
#endif // DEBUG
            }

            return false;
        }

        void System::Stop() ZERO_NOEXCEPT
        {
            // Guarded-Block
            try
            {
#ifdef ZERO_DEBUG // DEBUG
                std::string msg("System::Stop: type=");
                msg += std::to_string(mTypeID);
                msg += "; id=";
                msg += mID;
                zLog::Debug(msg.c_str());
#endif // DEBUG

                zSpinLock lock(&mStateMutex);
                if (isStarted(false))
                {
                    setState(EState::STOPPING, false);
                    lock.unlock();

                    onStop();
                }
                else
                    return;
            }
#ifdef ZERO_DEBUG /// DEBUG
            catch (const std::exception& _exception)
            {
                std::string msg("System::Stop: ");
                msg += _exception.what();

                zLog::Error(msg.c_str());
            }
#endif /// DEBUG
            catch (...)
            {
#ifdef ZERO_DEBUG /// DEBUG
                zLog::Error("System::Stop: unknown error");
#endif /// DEBUG
            }
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
