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

#include "I43DCommon.h"
#include <set>

/*!
 * @file
 *     This file contains classes relevant to the reception of keyboard events. This includes
 *     a listener class and an interface to the actual device on the operating system. 
 * @author Robert Eugene Simmons Jr. (Kraythe)
 */

namespace I43D {

// ---- Forward Declarations
enum _DLL_EXPORT NPKeyID;
class _DLL_EXPORT KeyboardListener;
class _DLL_EXPORT Keyboard;

/*!
 * @breif 
 *     An enumeration of the keys on a keyboard that are not printable.
 * @remarks
 *     This enumeration contains the keys on a keyboard that are not printable. These keys 
 *     consist of keys such as the Enter, Control, Shift and F keys as well as specialized 
 *     keys on special keyboards. This enumeration is provided to support cross platform 
 *     translation of these control keys.
 */
enum _DLL_EXPORT NPKeyID {
	NPK_ENTER = 1,								
	NPK_LCONTROL, NPK_RCONTROL,					// CTRL Keys
	NPK_LSHIFT, NPK_RSHIFT,						// Shift keys
	NPK_RALT, NPK_LALT,							// ALT keys
	NPK_LOS, NPK_ROS,							// OS Special keys like the windows key
	NPK_F1, NPK_F2, NPK_F3, NPK_F4,				// F Keys
	NPK_F5, NPK_F6, NPK_F7, NPK_F8,	
	NPK_F9, NPK_F10, NPK_F11, NPK_F12, 
	NPK_F13, NPK_F14, NPK_F15, 
	NPK_ESCAPE, NPK_BACKSPACE,	
	NPK_CAPSLOCK, NPK_NUMLOCK, 
	NPK_NUMPAD_HOME, NPK_NUMPAD_UP,				// Numpad keys when the pad is not in num mode.
	NPK_NUMPAD_PGUP, NPK_NUMPAD_LEFT,
	NPK_NUMPAD_CENTER, NPK_NUMPAD_RIGHT,
	NPK_NUMPAD_END, NPK_NUMPAD_DOWN,
	NPK_NUMPAD_PGDN, NPK_NUMPAD_INSERT,
	NPK_NUMPAD_DELETE, NPK_NUMPAD_COMMA,
	NPK_SCROLL_LOCK, NPK_SYSRQ, NPK_PAUSE,		// Print, scroll-lock block of keys
	NPK_BREAK,
	NPK_UP, NPK_DOWN, NPK_LEFT, NPK_RIGHT,		// Arrow Pad Keys
	NPK_HOME, NPK_END, NPK_PGUP, NPK_PGDOWN,	// Page-Up/Down, Home, End block
	NPK_INSERT, NPK_DELETE,
	NPK_OEM_102, NPK_PREVTRACK, NPK_STOP,		// Multimedia Keyboard keys
	NPK_AX, NPK_NEXTTRACK, NPK_MUTE, 
	NPK_CALCULATOR, NPK_PLAYPAUSE,
	NPK_MEDIASTOP, NPK_VOLUMEDOWN,
	NPK_VOLUMEUP, 
	NPK_WEBHOME,NPK_WEBSEARCH,					// OS command keys
	NPK_WEBFAVORITES, NPK_WEBREFRESH, 
	NPK_WEBSTOP, NPK_WEBFORWARD, 
	NPK_WEBBACK, NPK_MYCOMPUTER, NPK_MAIL, 
	NPK_MEDIASELECT, NPK_APPS,
	NPK_POWER, NPK_SLEEP, NPK_WAKE				// Power and computer sleep command keys
};

/*!
 * @brief
 *     The base of all listeners to key events.
 * @remarks
 *     The interface for a class that wishes to listen to keyboard events. Users 
 *     should, derive a class from this class, and implement the methods here. Listeners
 *     can be added throughusing the addListener() method in the keyboard class. Users
 *     that derive from this class will need only to override the methods that they choose
 *     to override as the listener has default empty implementations for all functions.
 */
class _DLL_EXPORT KeyboardListener abstract {
public:
	/*!
	 * @brief
	 *     Destructor.
	 */
	virtual ~KeyboardListener() {}

	/*!
	 * @brief
	 *     Called whenever a key is pressed.
	 * @remarks
	 *     This method is called whenever a key on the keyboard is pressed. Each keyPressed()
	 *     call will naturally be matched by a keyReleased() call. This method is one of the 
	 *     most primitive ways to get input from the keyboard.
	 * @param source
	 *     The source of the event. This will normally be a single keyboard on the system,
	 *     however in a console there could concievably be more than one keyboard. 
	 * @param keyNum
	 *     The number of the key that was pressed. This number represents an abstract 
	 *     representation of the key. The actual number is converted to a key or a non-printing
	 *     key using mappings that are dependent on the keyboard.
	 * @param scanCode
	 *     The scan code of the key that was pressed.
	 */
	virtual void keyPressed(const Keyboard* source, const unsigned short keyNum, 
	                        const unsigned int scanCode) {};

	/*!
	 * @brief
	 *     Called whenever a key is released.
	 * @remarks
	 *     This method is called whenever a key on the keyboard is released. Each keyReleased()
	 *     call will naturally be matched by a keyPressed() call. This method is one of the 
	 *     most primitive ways to get input from the keyboard. 
	 * @param source
	 *     The source of the event. This will normally be a single keyboard on the system,
	 *     however in a console there could concievably be more than one keyboard. 
	 * @param keyNum
	 *     The number of the key that was pressed. This number represents an abstract 
	 *     representation of the key. The actual number is converted to a key or a non-printing
	 *     key using mappings that are dependent on the keyboard.
	 * @param scanCode
	 *     The scan code of the key that was released.
	 */
	virtual void keyReleased(const Keyboard* source, const unsigned short keyNum, 
	                         const unsigned int scanCode) {}	

	/*!
	 * @brief
	 *     Called whenever a unicode character is typed by the user.
	 * @remarks 
	 *		Called when a printable key is typed by the user. This method will not necessarily
	 *		be called on every key press or release because there are some dead keys that result  
	 *		in a unicode character being output on the 2nd or even more key presses. For example, 
	 *		on a German keyboard, hitting ^ and the o will result in a single charTyped event
	 *		containing the unicode for an o with a ^ over it. 
	 * @param source
	 *     The source of the event. This will normally be a single keyboard on the system,
	 *     however in a console there could concievably be more than one keyboard. 
	 * @param typedChar
	 *		Contains the character that was typed.
	 */
	virtual void charTyped(const Keyboard* source, const wchar_t typedChar) {}

	/*!
	 * @brief
	 *     Called whenever a non-printable key is typed by the user.
	 * @remarks 
	 *		Called when a non-printable key (such as ESC) is typed. 
	 * @param source
	 *     The source of the event. This will normally be a single keyboard on the system,
	 *     however in a console there could concievably be more than one keyboard. 
	 * @param typedKey
	 *		Contains the key that was typed as one of the members of the NPKeyID enumeration.
	 */
	virtual void nonPrintKeyTyped(const Keyboard* source, const NPKeyID typedKey) {}
};

class _DLL_EXPORT Keyboard abstract {
public:
	/*!
	 * @brief
	 *     Constructor.
	 */
	Keyboard() {}
	
	/*!
	 * @brief
	 *     Destructor.
	 */
	virtual ~Keyboard() {
		this->listeners.clear();
	}

	/*!
	 * @brief
	 *     Gets the layout name of the keyboard.
	 * @todo
	 *     Should this be switched to an enumeration to allow platform neutral switching 
	 *     on the name?
	 */
	virtual const std::wstring getLayoutName() = 0;
	
	/*!
	 * @brief
	 *     Enable or disable key input events.
	 * @remarks
	 *     Enable or disable key input events. This allows the user of this class to turn
	 *     event dispatchign on and off at will.
	 * @param flag
	 *     A flag that says whether key input events should be enabled (true) or disabled 
	 *     (false) for this keyboard.
	 */
	virtual void enableEvents(const bool flag) = 0;

	/*!
	 * @brief
	 *     Tests to see whether the key with the given scan code is actually down at this 
	 *	   particular moment.
	 * @param keyNum
	 *     The key number of the key to check.
	 */
	virtual bool isKeyPressed(const unsigned short keyNum) = 0;

	/*!
	 * @brief
	 *      Gets the scan code pair for a particular key number. 
	 * @remarks
	 *      Each key will have a pair of scan codes. One that comes when the key is 
	 *      pressed and another that comes when the key is released. In the resulting array 
	 *      they will be in this order. 
	 * @param keyNum
	 *      The number of the key to look up.
	 * @see I43D::Keyboard::getKeyNumForScanCode(const unsigned int)
	 */
	virtual unsigned int getScanCodeForKeyNum(const unsigned short keyNum) = 0;

	/*!
	 * @brief
	 *     Gets the key number for the particular scan code. 
	 * @remarks
	 *     Since there are 2 scan codes mapped to any particular key (pressed/depressed), 
	 *     this method will return the key number whether the scan code is for a pressed 
	 *     or released key. 
	 * @param scanCode
	 *     The scan code to look up.
	 * @see I43D::Keyboard::getScanCodeForKeyNum(const unsigned short);
	 */
	virtual unsigned short getKeyNumForScanCode(const unsigned int scanCode) = 0;

	/*!
	 * @brief
	 *     Gets the non-printing key for the given key number. 
	 * @param keyNum
	 *     The key number to look up.
	 * @see I43D::NPKeyID
	 * @see I43D::Keyboard::getKeyNumForNPK(const NPKeyID)
	 */
	virtual NPKeyID getNPKForKeyNum(const unsigned short keyNum) = 0;

	/*!
	 * @brief
	 *     Gets the key number for the non-printing key given. 
	 * @param npk
	 *     The non-printing key for which to get the key number.
	 * @see I43D::NPKeyID
	 * @see I43D::Keyboard::getNPKForKeyNum(const unsigned short)
	 */
	virtual unsigned short getKeyNumForNPK(const NPKeyID npk) = 0;

	/*!
	 * @brief 
	 *     Adds a new keyboard listener.
	 * @param listener
	 *     The listener to add.
	 * @see I43D::Keyboard::removeKeyboardListener(const KeyboardListener const *)
	 */
	void addKeyboardListener(const KeyboardListener* listener) {
		this->listeners.insert(listener);
	}

	/*!
	 * @brief 
	 *     Remove a keyboard listener. 
	 * @remarks 
	 *     Make sure you call this method before deleting the listener or you will get access
	 *     violation exceptions all over. 
	 * @param listener
	 *     The listener to remove.
	 * @see I43D::Keyboard::addKeyboardListener(const KeyboardListener const *)
	 */
	void removeKeyboardListener(const KeyboardListener* listener) {
		this->listeners.erase(listener);
	}

private:
	/*!
	 * @breif
	 *     Stores the listeners to the keyboard.
	 */
	std::set<const KeyboardListener*> listeners;
};

} // namespace I43D 
#endif  // _I43D_KEYBOARD_H_