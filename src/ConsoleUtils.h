#pragma once
#include <iostream>
#include <windows.h>
#include "AnsiCommands.h"

namespace ConsoleUtils {

	void setSize(short cols, short rows) {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		// Shrink the window first so the buffer is allowed to shrink
		SMALL_RECT minimal = { 0, 0, 1, 1 };
		SetConsoleWindowInfo(h, TRUE, &minimal);

		// Set the buffer size
		COORD buffer = { cols, rows };
		SetConsoleScreenBufferSize(h, buffer);

		// Resize the window to the desired size
		SMALL_RECT window = { 0, 0, (short)(cols - 1), (short)(rows - 1) };
		SetConsoleWindowInfo(h, TRUE, &window);
	}

	void setEncoding() {
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
	}

	struct ScreenGuard {
		ScreenGuard() { std::cout << ansi::ALT_SCREEN_ON << ansi::CURSOR_OFF; } // setup
		~ScreenGuard() { std::cout << ansi::CURSOR_ON << ansi::ALT_SCREEN_OFF; }   // cleanup
	};

}




