/*
Copyright (C) 2012 MoSync AB

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License,
version 2, as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA.
*/

/**
 * @file Util.h
 * @author Emma Tresanszki.
 *
 * Utility functions for the application.
 */

#ifndef PURCHASE_UTIL_H_
#define PURCHASE_UTIL_H_

#include <mastring.h>		// C string functions
#include <conprint.h>
#include <mavsprintf.h>
#include <MAUtil/String.h>

	// Usual size for a buffer.
	const int BUF_SIZE = 256;

	#define BUF_MAX 256

	enum platform_code
	{
		ANDROID = 0,
		IOS = 1,
		WINDOWSPHONE7 = 2
	};

	/**
	 * Detects the current platform
	 * @return platform_code specific for Android, iPhone OS or WindowsPhone
	 */
	extern int getPlatform();

#endif /* PURCHASE_UTIL_H_ */
