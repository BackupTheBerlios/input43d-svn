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

#ifndef _I43D_WIN32MOUSE_H_
#define _I43D_WIN32MOUSE_H_

#include "I43DMouse.h"

/*!
 * @file
 *     This file contains the headers for the Win32, DirectX implementation of I43D::Mouse.
 * @author Robert Eugene Simmons Jr. (Kraythe)
 */

namespace I43D {

/*!
 * @brief
 *     Implements the basis mouse system. 
 */
class _DLL_EXPORT Win32Mouse : public I43D::Mouse {
public:
	/*!
	 * @brief
	 *     Constructor.
	 */
	Win32Mouse();

	/*!
	 * @brief
	 *     Destructor.
	 */
	virtual ~Win32Mouse();

	/*! @see I43D::Mouse:: */
	virtual void enableEvents(const bool flag);

	/*! @see I43D::Mouse:: */
	virtual unsigned int getX();

	/*! @see I43D::Mouse:: */
	virtual unsigned int getY();

	/*! @see I43D::Mouse:: */
	virtual bool isInClientArea();

	/*! @see I43D::Mouse:: */
	virtual bool isButtonPressed(const unsigned short buttonNum);

	/*! @see I43D::Mouse:: */
	virtual void setStandardCursor(const StandardCursorID cursorID);

	/*! @see I43D::Mouse:: */
	virtual void setCustomCursor(const void* cursorID) {
		throw I43DException(L"Not Implemented in this class", __WFILE__, __LINE__);
	}

	/*! @see I43D::Mouse:: */
	virtual void hideMouseCursor(const bool flag);

	/*! @see I43D::Mouse:: */
	virtual void captureMouse(const bool flag);
};
	
} // namespace I43D 
#endif  // _I43D_WIN32MOUSE_H_