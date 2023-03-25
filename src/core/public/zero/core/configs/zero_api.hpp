/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_CONFIG_API_HPP
#define ZERO_CONFIG_API_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// zero::core::config
#ifndef ZERO_CONFIG_PLATFORM_HPP
#include <zero/core/configs/zero_platform.hpp>
#endif /// !ZERO_CONFIG_PLATFORM_HPP

// Include STL exception
#include <exception>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// API
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#if defined( ZERO_SHARED ) // SHARED Library

#if defined( ZERO_EXPORT )
    #define ZERO_API __declspec( dllexport ) // EXPORT
#else
    #define ZERO_API __declspec( dllimport ) // IMPORT
#endif

#elif defined( ZERO_STATIC ) // STATIC Library
    #define ZERO_API /** void **/
#else
    #define ZERO_API /** void **/
#endif

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// REFLECTION
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define ZERO_STRUCT
#define ZERO_CLASS
#define ZERO_INTERFACE

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// DEBUG
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#if defined( DEBUG ) || defined( ZERO_DEBUG )
    #define ZERO_NOEXCEPT
#else
    #define ZERO_NOEXCEPT noexcept
#endif

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_CONFIG_API_HPP
