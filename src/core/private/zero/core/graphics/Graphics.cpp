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
#ifndef ZERO_CORE_GRAPHICS_HPP
#include <zero/core/graphics/Graphics.hpp>
#endif /// !ZERO_CORE_GRAPHICS_HPP

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
// Graphics
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // FIELDS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Graphics* Graphics::mInstance(nullptr);
        zMutex    Graphics::mInstanceMutex;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Graphics::Graphics()
            : System(static_cast<TypeID>(zECoreTypes::GRAPHICS))
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Graphics::constructor");
#endif /// DEBUG
        }

        Graphics::~Graphics() ZERO_NOEXCEPT
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Graphics::destructor");
#endif /// DEBUG
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GETTERS & SETTERS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Graphics* Graphics::getInstance()
        { return mInstance; }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.System
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool Graphics::onStart()
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Graphics::onStart");
#endif /// DEBUG

            return true;
        }

        bool Graphics::onPause()
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Graphics::onPause");
#endif /// DEBUG

            return true;
        }

        bool Graphics::onResume()
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Graphics::onResume");
#endif /// DEBUG

            return true;
        }

        void Graphics::onStop()
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Graphics::onStop");
#endif /// DEBUG
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void Graphics::Initialize(Graphics* const pGraphics)
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Graphics::Initialize");
            zAssert(!mInstance && "Graphics::Initialize: already initialized");
#endif /// DEBUG

            zSpinLock lock(&mInstanceMutex);

            if (!mInstance)
                mInstance = pGraphics;
        }

        void Graphics::Terminate()
        {
#ifdef ZERO_DEBUG /// DEBUG
            zLog::Info("Graphics::Terminate");
#endif /// DEBUG

            zSpinLock lock(&mInstanceMutex);
            if (!mInstance)
                return;

            delete mInstance;
            mInstance = nullptr;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
