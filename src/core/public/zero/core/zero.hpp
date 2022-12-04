/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_CORE_HPP
#define ZERO_CORE_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::core::api
#ifndef ZERO_CONFIG_API_HPP
#include <zero/core/configs/zero_api.hpp>
#endif /// !ZERO_CONFIG_API_HPP

// Include zero::core::numeric
#ifndef ZERO_CONFIG_NUMERIC_HPP
#include <zero/core/configs/zero_numeric.hpp>
#endif /// !ZERO_CONFIG_NUMERIC_HPP

// Include zero::core::Log
#ifndef ZERO_CORE_LOG_HPP
#include <zero/core/metrics/log/Log.hpp>
#endif /// !ZERO_CORE_LOG_HPP

// Include zero::core::BaseLogger
#ifndef ZERO_CORE_BASE_LOGGER_HPP
#include <zero/core/metrics/log/BaseLogger.hpp>
#endif /// !ZERO_CORE_BASE_LOGGER_HPP

// Include zero::core::Application
#ifndef ZERO_CORE_APPLICATION_HPP
#include <zero/core/app/Application.hpp>
#endif /// !ZERO_CORE_APPLICATION_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// zero::core
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !ZERO_CORE_HPP
