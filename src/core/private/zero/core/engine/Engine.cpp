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
#ifndef ZERO_CORE_ENGINE_HPP
#include <zero/core/engine/Engine.hpp>
#endif /// !ZERO_CORE_ENGINE_HPP

// Include zero::types
#ifndef ZERO_CONFIG_TYPES_HPP
#include <zero/core/configs/zero_types.hpp>
#endif /// !ZERO_CONFIG_TYPES_HPP

// DEBUG
#ifdef ZERO_DEBUG

// Include zero::debug
#ifndef ZERO_CONFIG_DEBUG_HPP
#include <zero/core/configs/zero_debug.hpp>
#endif /// !ZERO_CONFIG_DEBUG_HPP

#endif
// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Engine
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // FIELDS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Engine* Engine::mInstance(nullptr);
        zMutex  Engine::mInstanceMutex;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Engine::Engine()
            : System(static_cast<TypeID>(zECoreTypes::ENGINE))
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Engine::constructor");
#endif /// DEBUG
        }

#ifdef ZERO_DEBUG /// DEBUG
        Engine::~Engine() ZERO_NOEXCEPT
        {
            zLog::Info("Engine::destructor");
        }
#else /// !DEBUG
        Engine::~Engine() ZERO_NOEXCEPT = default;
#endif /// !DEBUG

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.System
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool Engine::onStart()
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Engine::onStart");
#endif /// DEBUG

            return true;
        }

        bool Engine::onPause()
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Engine::onPause");
#endif /// DEBUG

            return true;
        }

        bool Engine::onResume()
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Engine::onResume");
#endif /// DEBUG

            return true;
        }

        void Engine::onStop()
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Engine::onStop");
#endif /// DEBUG
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void Engine::Initialize(Engine* const pInstance)
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Engine::Initialize");
            zAssert(!mInstance && "Engine::Initialize: already initialized");
#endif /// DEBUG

            zSpinLock lock(&mInstanceMutex);

            if (!mInstance)
                mInstance = pInstance;
        }

        void Engine::Terminate() ZERO_NOEXCEPT
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Engine::Terminate");
#endif /// DEBUG

            zSpinLock lock(&mInstanceMutex);

            delete mInstance;
            mInstance = nullptr;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
