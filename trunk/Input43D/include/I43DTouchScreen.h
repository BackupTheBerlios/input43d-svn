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
#ifndef _I43D_TABLET_H_
#define _I43D_TABLET_H_

#include "I43DPlatform.h"

/*!
 * @file
 *     This file contains classes relevant to the reception of graphics tablet events. 
 *     This includes a listener class and an interface to the actual device on the 
 *     operating system.
 * @author Robert Eugene Simmons Jr. (Kraythe)
 */

namespace I43D {

// ---- Forward Declarations

// ---- Forward Declarations
class _DLL_EXPORT GameControllerListener;
class _DLL_EXPORT GameController;

/*!
 * @brief
 *     Implements a listener to graphics tablet input. 
 */
class _DLL_EXPORT TabletListener abstract {
};

/*!
 * @brief
 *     A graphics tablet that allows input of data through using a pen and
 *     special pad.
 */
class _DLL_EXPORT Tablet abstract {
}

} // namespace I43D 
#endif  // _I43D_TABLET_H_