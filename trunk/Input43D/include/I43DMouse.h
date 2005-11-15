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

#ifndef _I43D_MOUSE_H_
#define _I43D_MOUSE_H_

#include "I43DCommon.h"
#include <set>

/*!
 * @file
 *     This file contains classes relevant to the reception of mouse events. This includes
 *     a listener class and an interface to the actual device on the operating system.
 * @author Robert Eugene Simmons Jr. (Kraythe)
 */

namespace I43D {

// ---- Forward Declarations
class _DLL_EXPORT Mouse;
class _DLL_EXPORT MouseListener;
enum _DLL_EXPORT MouseScrollDirection;
enum _DLL_EXPORT StandardCursorID;

/*!
 * @brief
 *     Contains directions that are used when on-mouse scrolling devices, like a mouse 
 *     wheel, are used.
 * @remarks
 *     Many mice have wheels that allow the user to scroll up and down. Some mice like the 
 *     "Mighty Mouse" from Apple and the 'MX Laser' from Ligitech allow the user to scroll
 *     left and right as well. 
 */
enum _DLL_EXPORT MouseScrollDirection {
	UP = 1, DOWN, LEFT, RIGHT
};

/*!
 * @brief
 *     This class defines a listener to mouse events.
 * @remarks
 *     The user of this class merely needs to derive a class from this class and then 
 *     add that instance as a listener in the Mouse class. This class provides default,
 *     no-operation implementations of all of the methods which means that the user 
 *     need only override the methods that they are interested in.
 */
class _DLL_EXPORT MouseListener abstract {
public:
	/*!
	 * @brief
	 *     Destructor.
	 */
	virtual ~MouseListener() {}

	/*!
	 * @brief
	 *     Called when the mouse is moved. 
	 * @remarks 
	 *     This method will be called whenever the mouse is moved whether or not there is
	 *     a button pressed (mouse drag) or not. The reason that there is no mouse drag 
	 *     method is because it isnt really necessary. All you have to do is detect the mouse
	 *     move event and then check if a button is currently pressed. 
	 * @param source
	 *     The mouse that generated the event. 
	 * @param x 
	 *     The current x coordinate of the mouse.
	 * @param x 
	 *     The current y coordinate of the mouse.
	 */
	virtual void moved(const Mouse* source, const unsigned int x, 
	                   const unsigned int y) {}

	/*!
	 * @brief 
	 *     Called when a mouse button is pressed. 
	 * @param source
	 *     The mouse that generated the event. 
	 * @param buttonNum
	 *     The number of the button that was pressed starting with button 1.
	 */
	virtual void buttonPressed(const Mouse* source, const unsigned short buttonNum) {}

	/*!
	 * @brief 
	 *     Called when a mouse button is released. 
	 * @param source
	 *     The mouse that generated the event. 
	 * @param buttonNum
	 *     The number of the button that was released starting with button 1.
	 */
	virtual void buttonReleased(const Mouse* source, const unsigned short buttonNum) {}

	/*!
	 * @brief 
	 *     Called when a mouse button is clicked. 
	 * @param source
	 *     The mouse that generated the event. 
	 * @param buttonNum
	 *     The number of the button that was clicked starting with button 1.
	 * @param clickCount
	 *     The number of times that the button was clicked.
	 */
	virtual void buttonClicked(const Mouse* source, const unsigned short buttonNum, 
	                           const unsigned short clickCount) {}

	/*!
	 * @brief
	 *     Called when there is a scroll up even resulting from something like a mouse wheel. 
	 * @param source
	 *     The mouse that generated the event. 
	 * @param direction
	 *     The direction that the mouse was scrolled.
	 */
	virtual void scrollUp(const Mouse* source, const MouseScrollDirection direction) {}

	/*!
	 * @breif 
	 *     Called when the mouse enters the client area of the 3D application.
	 * @remarks
	 *     This method can be used to detect the proper time to change the cursor on the
	 *     platform. However, cursor management is highly platform specific so that is not 
	 *     handled at this time by this library.
	 * @param source
	 *     The mouse that generated the event. 
	 */
	virtual void entered(const Mouse* source) {}

	/*!
	 * @breif 
	 *     Called when the mouse exits the client area of the 3D application.
	 * @param source
	 *     The mouse that generated the event. 
	 */
	virtual void exited(const Mouse* source) {}
};

/*!
 * @brief 
 *     Defines a number of predefined cursors for mouse cursor changing. 
 */
enum _DLL_EXPORT StandardCursorID {
	MCURS_NORMAL,			// Normal Cursor
	MCURS_TEXT_INPUT,		// Used for text input in fields
	MCURS_WAIT,				// Wait Cursor for long operations
	MCURS_RESIZE,			// All direction resize cursor
	MCURS_RESIZE_NWSE,		// Northeast-Southwest resize cursor
	MCURS_RESIZE_NESW,		// Northeast-Southwest resize cursor
	MCURS_RESIZE_EW,		// East-West resize cursor
	MCURS_RESIZE_NS			// North-South resize cursor 
};

/*!
 * @brief
 *     Implements the basis mouse system. 
 */
class _DLL_EXPORT Mouse abstract {
public:
	/*!
	 * @brief
	 *     Constructor.
	 */
	Mouse() {}

	/*!
	 * @brief
	 *     Destructor.
	 */
	virtual ~Mouse() {
	}

	/*!
	 * @brief
	 *     Enable or disable mouse input events.
	 * @remarks
	 *     Enable or disable mouse input events. This allows the user of this class to turn
	 *     event dispatchign on and off at will.
	 * @param flag
	 *     A flag that says whether mouse input events should be enabled (true) or disabled 
	 *     (false) for this mouse.
	 */
	virtual void enableEvents(const bool flag) = 0;

	/*!
	 * @brief 
	 *      Gets the current x position of the mouse in the client area. 
	 */
	virtual unsigned int getX() = 0;

	/*!
	 * @brief 
	 *     Gets the current y position of the mouse in the client area. 
	 */
	virtual unsigned int getY() = 0;

	/*!
	 * @brief 
	 *     Determines if the mouse is in the client area or not. 
	 */
	virtual bool isInClientArea() = 0;

	/*!
	 * @brief 
	 *     Determines if the given button on the mouse is currently pressed.
	 * @param buttonNum
	 *     The number of the button to check starting with number 1.
	 */
	virtual bool isButtonPressed(const unsigned short buttonNum) = 0;

	/*!
	 * @brief
	 *     Set the mouse cursor (also called mouse pointer) to one of the standard cursors.
	 * @pram cursorID 
	 *     This is the ID of the standard cursor to set.
	 */
	virtual void setStandardCursor(const StandardCursorID cursorID) = 0;

	/*!
	 * @brief
	 *     Set a custom mouse cursor (also called mouse pointer) to one of the standard cursors.
	 * @remarks
	 *     This method is highly OS (and window manager for Unix) dependent. It is here mainly
	 *     as a hook for those that wish to subclass this class or one of the platform implementation
	 *     classes to set a cursor in a way that can be easily ported across platforms. The default 
	 *     implementation of this class will merely throw an exception.
	 * @param cursorID 
	 *     This is the cursor to set. The void pointer would be interpreted differently depending
	 *     upon the user's wishes. For example, Some users might choose to define an enumeration  
	 *     like the I43D::StandardCursorID enumeration and pass that ID. Other users might take a 
	 *     different approach. 
	 */
	virtual void setCustomCursor(const void* cursorID) {
		throw I43DException(L"Not Implemented in this class", __WFILE__, __LINE__);
	}

	/*!
	 * @brief
	 *     Hides or unhides the mouse cursor from the user.
	 * @param flag
	 *     A flag indicating if the cursor should be hidden (true) or shown (false).
	 */
	virtual void hideMouseCursor(const bool flag) = 0;

	/*!
	 * @brief
	 *     Capture or release the mouse.
	 * @remarks
	 *     A captured mouse can not leave the client area. Often this is used to implement
	 *     functionality such as mouse look in FPS games. 
	 * @param flag
	 *     Whether to capture the mouse (true) or release the mouse (false).
	 */
	virtual void captureMouse(const bool flag) = 0;

	/*!
	 * @brief 
	 *     Adds a new Mouse listener.
	 * @param listener
	 *     The listener to add.
	 * @see I43D::Mouse::removeMouseListener(const MouseListener const *)
	 */
	inline void addMouseListener(const MouseListener* listener) {
		this->listeners.insert(listener);
	}

	/*!
	 * @brief 
	 *     Remove a Mouse listener. 
	 * @remarks 
	 *     Make sure you call this method before deleting the listener or you will get access
	 *     violation exceptions all over. 
	 * @param listener
	 *     The listener to remove.
	 * @see I43D::Mouse::addMouseListener(const MouseListener const *)
	 */
	inline void removeMouseListener(const MouseListener* listener) {
		this->listeners.erase(listener);
	}

private:
	/*!
	 * @brief
	 *     Stores the listeners to the keyboard.
	 */
	std::set<const MouseListener*> listeners;
};
	
} // namespace I43D 
#endif  // _I43D_MOUSE_H_