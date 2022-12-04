/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_CORE_LOG_HPP
#define ZERO_CORE_LOG_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::api
#ifndef ZERO_CONFIG_API_HPP
#include <zero/core/configs/zero_api.hpp>
#endif /// !ZERO_CONFIG_API_HPP

// Include zero::core::ELogLevel
#ifndef ZERO_CORE_E_LOG_LEVEL_HPP
#include "ELogLevel.hpp"
#endif /// !ZERO_CORE_E_LOG_LEVEL_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// FORWARD-DECLARATION
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Forward-declare zero::core::ILogger
#ifndef ZERO_CORE_I_LOGGER_DECL
    #define ZERO_CORE_I_LOGGER_DECL
    namespace zero { namespace core { class ILogger; } }
    using zILogger = zero::core::ILogger;
#endif /// !ZERO_CORE_I_LOGGER_DECL

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // Log
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        /*!
            \brief Log facade
            \version 0.1
            \author c0de4un
            \date 04.12.2022
        */
        ZERO_API class Log final
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

            /*!
                \property Logger implementation to use
            */
            static ILogger* mInstance;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
                \brief Log default constructor
                \throws no exceptions
            */
            explicit Log() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DELETED
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            Log(const Log&) noexcept             = delete;
            Log& operator=(const Log&) noexcept  = delete;
            Log(const Log&&) noexcept            = delete;
            Log& operator=(const Log&&) noexcept = delete;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
                \brief Log destructor
                \throw doesn't throw any exceptions
            */
            ~Log() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            /*!
                \brief Initialize Log
                \param pInstance logger to use
                \throws no exceptions
            */
            static void Initialize(ILogger* const pInstance) noexcept;

            /*!
                \brief Terminate Logger
                \throws no exceptions
            */
            static void Terminate() noexcept;

            /*!
                \brief Print INFO-level message
                \param pMessage c-string message
                \thread_safety thread-safe
                \throw no exception
            */
            static void Info(const char* const pMessage) ZERO_NOEXCEPT;

            /*!
                \brief Print DEBUG-level message
                \param pMessage c-string message
                \thread_safety thread-safe
                \throw no exception
            */
            static void Debug(const char* const pMessage) ZERO_NOEXCEPT;

            /*!
                \brief Print WARNING-level message
                \param pMessage c-string message
                \thread_safety thread-safe
                \throw no exception
            */
            static void Warning(const char* const pMessage) ZERO_NOEXCEPT;

            /*!
                \brief Print ERROR-level message
                \param pMessage c-string message
                \thread_safety thread-safe
                \throw no exception
            */
            static void Error(const char* const pMessage) ZERO_NOEXCEPT;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// zero::core::Log

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// zero::core

} /// zero

using zLog = zero::core::Log;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_CORE_LOG_HPP
