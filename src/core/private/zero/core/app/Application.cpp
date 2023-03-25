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
#ifndef ZERO_CORE_APPLICATION_HPP
#include <zero/core/app/Application.hpp>
#endif /// !ZERO_CORE_APPLICATION_HPP

// DEBUG
#ifdef ZERO_DEBUG

// Include zero::debug
#ifndef ZERO_CONFIG_DEBUG_HPP
#include <zero/core/configs/zero_debug.hpp>
#endif /// !ZERO_CONFIG_DEBUG_HPP

#endif
// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// zero::core::Application
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // FIELDS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Application* Application::mInstance(nullptr);

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Application::Application() ZERO_NOEXCEPT = default;

        Application::~Application() ZERO_NOEXCEPT = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.System
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool Application::onStart()
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Application::onStart");
#endif /// DEBUG

            setState(EState::RUNNING);

            return true;
        }

        bool Application::onPause()
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Application::onPause");
#endif /// DEBUG

            setState(EState::PAUSED);

            return true;
        }

        bool Application::onResume()
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Application::onResume");
#endif /// DEBUG

            setState(EState::RUNNING);

            return true;
        }

        void Application::onStop()
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Application::onStop");
#endif /// DEBUG

            setState(EState::NONE);
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Application* Application::Initilize(Application* pInstance) ZERO_NOEXCEPT
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Application::Initilize");
#endif /// DEBUG

            if (!mInstance)
                mInstance = pInstance;

            return mInstance;
        }

        void Application::Terminate() ZERO_NOEXCEPT
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Application::Terminate");
#endif /// DEBUG

            delete mInstance;
            mInstance = nullptr;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
