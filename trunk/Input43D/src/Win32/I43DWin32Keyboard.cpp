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

#include "Win32/I43DWin32Keyboard.h"

namespace I43D {

Win32Keyboard::Win32Keyboard() {
}

Win32Keyboard::~Win32Keyboard() {
}

const std::wstring Win32Keyboard::getLayoutName() {
	return NULL;
}

void Win32Keyboard::enableEvents(const bool flag) {
}

bool Win32Keyboard::isKeyPressed(const unsigned short keyNum) {
	return false;
}

unsigned int Win32Keyboard::getScanCodeForKeyNum(const unsigned short keyNum) {
	return 0;
}

unsigned short Win32Keyboard::getKeyNumForScanCode(const unsigned int scanCode) {
	return 0;
}

NPKeyID Win32Keyboard::getNPKForKeyNum(const unsigned short keyNum) {
	return NPK_ENTER;
}

unsigned short Win32Keyboard::getKeyNumForNPK(const NPKeyID npk) {
	return 0;
}

} // namespace I43D 