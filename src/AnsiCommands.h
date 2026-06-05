#pragma once
#include <string>
#include <string_view>

namespace ansi {
	// colors
	inline constexpr std::string_view GREEN = "\033[1;32m";
	inline constexpr std::string_view DARK_GREEN = "\033[38;2;0;50;0m";
	inline constexpr std::string_view ORANGE = "\033[38;5;208m";
	inline constexpr std::string_view RED = "\033[1;31m";
	inline constexpr std::string_view YELLOW = "\033[1;33m";
	inline constexpr std::string_view DARK_YELLOW = "\033[38;2;50;50;0m";
	inline constexpr std::string_view CYAN = "\033[1;36m";
	inline constexpr std::string_view BLUE = "\033[1;34m";
	inline constexpr std::string_view MAGENTA = "\033[1;35m";
	inline constexpr std::string_view WHITE = "\033[1;37m";
	inline constexpr std::string_view GREY = "\033[38;2;128;128;128m";
	inline constexpr std::string_view BLACK = "\033[30m";

	// text styles
	inline constexpr std::string_view BOLD = "\033[1m";
	inline constexpr std::string_view DIM = "\033[2m";
	inline constexpr std::string_view ITALIC = "\033[3m";
	inline constexpr std::string_view UNDERLINE = "\033[4m";
	inline constexpr std::string_view BLINK = "\033[5m";
	inline constexpr std::string_view REVERSE = "\033[7m"; // swap fg/bg

	inline constexpr std::string_view RESET = "\033[0m";

	// cursor visibility & saved position
	inline constexpr std::string_view CURSOR_OFF = "\033[?25l";
	inline constexpr std::string_view CURSOR_ON = "\033[?25h";
	inline constexpr std::string_view SAVE_CURSOR_POS = "\033[s";
	inline constexpr std::string_view TO_SAVED_POS = "\033[u";
	inline constexpr std::string_view HOME = "\033[H";

	// erasing (cursor cell is included, cursor does not move)
	inline constexpr std::string_view CLEAR_ALL_AFTER = "\033[J";    // cursor -> end of screen
	inline constexpr std::string_view CLEAR_ALL_BEFORE = "\033[1J";  // start of screen -> cursor
	inline constexpr std::string_view CLEAR_SCREEN = "\033[2J";      // whole screen (pair with HOME)
	inline constexpr std::string_view CLEAR_LINE_AFTER = "\033[K";   // cursor -> end of line
	inline constexpr std::string_view CLEAR_LINE_BEFORE = "\033[1K"; // start of line -> cursor
	inline constexpr std::string_view CLEAR_LINE = "\033[2K";        // whole line

	// alternate screen buffer: enter on start, exit on quit to keep the
	// terminal's scrollback / original contents intact
	inline constexpr std::string_view ALT_SCREEN_ON = "\033[?1049h";
	inline constexpr std::string_view ALT_SCREEN_OFF = "\033[?1049l";

	// "\033[<row>;<col>H" — move cursor to absolute position
	inline std::string MOVE_TO(int col, int row) {
		return "\033[" + std::to_string(col) + ";" + std::to_string(row) + "H";
	}

	// "\033[<col>G" — move cursor to absolute column on the current row
	inline std::string MOVE_COL(int col) {
		return "\033[" + std::to_string(col) + "G";
	}

	// relative cursor movement
	inline std::string UP(int n = 1)    { return "\033[" + std::to_string(n) + "A"; }
	inline std::string DOWN(int n = 1)  { return "\033[" + std::to_string(n) + "B"; }
	inline std::string RIGHT(int n = 1) { return "\033[" + std::to_string(n) + "C"; }
	inline std::string LEFT(int n = 1)  { return "\033[" + std::to_string(n) + "D"; }

	// 24-bit truecolor — foreground / background from RGB
	inline std::string FG(int r, int g, int b) {
		return "\033[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
	}
	inline std::string BG(int r, int g, int b) {
		return "\033[48;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
	}
}
