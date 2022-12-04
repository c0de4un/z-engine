/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ZERO_CONFIG_PLATFORM_HPP
#define ZERO_CONFIG_PLATFORM_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// DEFINES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#if !defined(ZERO_PLATFORM_DEFINED) || ZERO_PLATFORM_DEFINED == 0

    // WINDOWS
    #if defined( MINGW ) || defined( MINGGW32 ) || defined( MINGW64 ) || defined( WIN32 ) || defined( WIN64 ) || defined( WINDOWS ) || defined( MSVC )
        #define ZERO_WINDOWS
    #elif defined( __linux ) || defined( _linux ) || defined( _linux_ ) || defined( __linux__ ) || defined( LINUX )
        // LINUX
        #define ZERO_LINUX
    #elif defined( ANDROID ) || defined( _android_ ) || defined( __android__ ) || defined( _android ) || defined( __android )
        // ANDROID
        #define ZERO_ANDROID
    #else
        #error "zero_platform.hpp - configuration required"
    #endif

#endif

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_CONFIG_PLATFORM_HPP
