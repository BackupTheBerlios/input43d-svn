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

#include "Win32/I43DWin32Mouse.h"

namespace I43D {

Win32Mouse::Win32Mouse() {
}

Win32Mouse::~Win32Mouse() {
}

void Win32Mouse::enableEvents(const bool flag) {
}

unsigned int Win32Mouse::getX() {
	return 0;
}

unsigned int Win32Mouse::getY() {
	return 0;
}

bool Win32Mouse::isInClientArea() {
	return false;
}

bool Win32Mouse::isButtonPressed(const unsigned short buttonNum) {
	return false;
}

void Win32Mouse::setStandardCursor(const StandardCursorID cursorID) {
}

void Win32Mouse::hideMouseCursor(const bool flag) {
}

void Win32Mouse::captureMouse(const bool flag) {
}

} // namespace I43D 