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
#ifndef ZERO_CORE_LOG_HPP
#include <zero/core/metrics/log/Log.hpp>
#endif /// !ZERO_CORE_LOG_HPP

// Include zero::core::ILogger
#ifndef ZERO_CORE_I_LOGGER_HXX
#include <zero/core/metrics/log/ILogger.hxx>
#endif /// !ZERO_CORE_I_LOGGER_HXX

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Log
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // FIELDS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        zILogger* Log::mInstance(nullptr);

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTORS & DESTRUCTORS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        explicit Log::Log() noexcept = default;
        Log::~Log() noexcept         = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void Log::Initialize(ILogger* const pInstance) noexcept
        {
            if (!mInstance)
                mInstance = pInstance;
        }

        void Log::Terminate() noexcept
        {
            delete mInstance;
            mInstance = nullptr;
        }

        void Log::Info(const char* const pMessage) ZERO_NOEXCEPT
        {
            mInstance->Print(pMessage, static_cast<z_uint_8_t>(zELogLevel::INFO));
        }

        void Log::Debug(const char* const pMessage) ZERO_NOEXCEPT
        {
            mInstance->Print(pMessage, static_cast<z_uint_8_t>(zELogLevel::DEBUG));
        }

        void Log::Warning(const char* const pMessage) ZERO_NOEXCEPT
        {
            mInstance->Print(pMessage, static_cast<z_uint_8_t>(zELogLevel::WARNING));
        }

        void Log::Error(const char* const pMessage) ZERO_NOEXCEPT
        {
            mInstance->Print(pMessage, static_cast<z_uint_8_t>(zELogLevel::ERROR));
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
