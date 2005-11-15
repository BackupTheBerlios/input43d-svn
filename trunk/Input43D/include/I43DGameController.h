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
#ifndef _I43D_GAME_CONTROLLER_H_
#define _I43D_GAME_CONTROLLER_H_

#include "I43DPlatform.h"

/*!
 * @file
 *     This file contains classes relevant to the reception of game controller events. 
 *     This includes a listener class and an interface to the actual device on the 
 *     operating system.
 * @author Robert Eugene Simmons Jr. (Kraythe)
 * @todo Include Force feedback apis
 */

namespace I43D {

// ---- Forward Declarations
class _DLL_EXPORT GameControllerListener;
class _DLL_EXPORT GameController;

/*!
 * @brief
 *     Implements a listener to game controller input. 
 */
class _DLL_EXPORT GameControllerListener abstract {
public: 
	virtual void buttonPressed(const unsigned short buttonNum) {}
	virtual void buttonReleased(const unsigned short buttonNum) {}
	virtual void axisMoved(const unsigned short axisNum, const int[] delta){}
};

/*!
 * @brief
 *     A controller for a game. This consist of devices such as game pads, wheels, 
 *     joysticks, flight yokes and other game oriented controllers.
 */
class _DLL_EXPORT GameController abstract {
	/*!
	 * @brief
	 *     Constructor.
	 */
	GameController() {}

	/*!
	 * @brief
	 *     Destructor.
	 */
	virtual ~GameController() {
	}

	virtual unsigned short getAxesCount() = 0;
	virtual unsigned short getButtonCount() = 0;
	virtual int[] getXAxisMinMax(const unsigned short axisNum) = 0;
	virtual int[] getYAxisMinMax(const unsigned short axisNum) = 0;
	virtual int[] getZAxisMinMax(const unsigned short axisNum) = 0;
	virtual bool isButtonPressed(const unsigned short buttonNum) = 0;
	virtual int[] getCurrentAxisPosition(const unsigned short axisNum) = 0;

		/*!
	 * @brief 
	 *     Adds a new Game Controller listener.
	 * @param listener
	 *     The listener to add.
	 * @see I43D::GameController::removeGameControllerListener(const GameControllerListener const *)
	 */
	inline void addGameControllerListener(const GameControllerListener* listener) {
		this->listeners.insert(listener);
	}

	/*!
	 * @brief 
	 *     Remove a Game Controller listener. 
	 * @remarks 
	 *     Make sure you call this method before deleting the listener or you will get access
	 *     violation exceptions all over. 
	 * @param listener
	 *     The listener to remove.
	 * @see I43D::GameController::addGameControllerListener(const GameControllerListener const *)
	 */
	inline void removeGameControllerListener(const GameControllerListener* listener) {
		this->listeners.erase(listener);
	}

private:
	/*!
	 * @brief
	 *     Stores the listeners to the keyboard.
	 */
	std::set<const GameControllerListener*> listeners;
}

} // namespace I43D 
#endif  // _I43D_GAME_CONTROLLER_H_