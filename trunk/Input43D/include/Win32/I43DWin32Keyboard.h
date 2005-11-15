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
#ifndef _I43D_KEYBOARD_H_
#define _I43D_KEYBOARD_H_

#include "I43DKeyboard.h"
#include <set>

/*!
 * @file
 *     This file contains classes relevant to the reception of keyboard events. This includes
 *     a listener class and an interface to the actual device on the operating system. 
 * @author Robert Eugene Simmons Jr. (Kraythe)
 */

namespace I43D {

class _DLL_EXPORT Win32Keyboard :: public I43D::Keyboard {
public:
	/*!
	 * @brief
	 *     Constructor.
	 */
	Win32Keyboard();
	
	/*!
	 * @brief
	 *     Destructor.
	 */
	virtual ~Win32Keyboard();

	/*! @see I43D::Keyboard:: */
	virtual const std::wstring getLayoutName();
	
	/*! @see I43D::Keyboard:: */
	virtual void enableEvents(const bool flag);

	/*! @see I43D::Keyboard:: */
	virtual bool isKeyPressed(const unsigned short keyNum);

	/*! @see I43D::Keyboard:: */
	unsigned int getScanCodeForKeyNum(const unsigned short keyNum);

	/*! @see I43D::Keyboard:: */
	unsigned short getKeyNumForScanCode(const unsigned int scanCode);

	/*! @see I43D::Keyboard:: */
	NPKeyID getNPKForKeyNum(const unsigned short keyNum);

	/*! @see I43D::Keyboard:: */
	unsigned short getKeyNumForNPK(const NPKeyID npk);

};

} // namespace I43D 
#endif  // _I43D_KEYBOARD_H_