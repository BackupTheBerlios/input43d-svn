/* -------------------------------------------------------------------------------------
This source file is part of Input43D : Copyright (c) 2000-2005 The Input43D Team
----------------------------------------------------------------------------------------
LICENSE:

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
------------------------------------------------------------------------------------- */
#ifndef _I43D_PLATFORM_H_
#define _I43D_PLATFORM_H_

/*!
 * @file
 *     This file contains common macros and definitions that are used in all files of the
 *     Input43D library.
 * @author Robert Eugene Simmons Jr. (Kraythe)
 */

// -- Determine what macro expansion for dynamic library linkage should be.
#define _DLL_EXPORT

#if defined( _WIN32 ) // Windows
#	if defined ( _XBOX )
#	else
#		pragma unmanaged
#		if defined( _DLL ) // _DLL is automatically defined for DLL builds in MSVC
#			undef _DLL_EXPORT
//#			pragma warning (disable : 4251)
#			if defined( I43D_NONCLIENT_BUILD )
#				define _DLL_EXPORT __declspec( dllexport )
#			else
#				define _DLL_EXPORT __declspec( dllimport )
#			endif
#		endif
#	endif
#elif defined( __APPLE_CC__ ) // Apple OS X
#elif defined( __MINGW32__ ) // Linux
#else // for any other platform create an error.
#	error Unknown Platform
#endif

// -- Create a macro for wide string file names if it doesnt exist. 
#ifndef __WFILE__
#	define WIDEN2(x) L ## x
#	define WIDEN(x) WIDEN2(x)
#	define __WFILE__ WIDEN(__FILE__)
#endif

#include <string>
namespace I43D {
	
class I43DException {
public: 
	/*! @brief Contains the detail message. */
	const std::wstring detail;

	/*! @brief contains the file name where the exception occurred. */
	const std::wstring file;

	/*! @brief contains the line number in the file where the exception occurred. */
	const unsigned int line;

	/*!
	 * @breif
	 *     Constructor
	 */
	I43DException(const std::wstring detail, std::wstring file, const unsigned int line) 
		: detail(detail), file(file), line(line) {
		// no code needed.
	}
};

} // namespace I43D 
#endif  // _I43D_PLATFORM_H_