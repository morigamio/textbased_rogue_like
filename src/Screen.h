#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
#include "AnsiCommands.h"
#include <iostream>

class Screen {
public:

	Screen(int rows, int cols) :
		m_rows(rows), m_cols(cols),
		m_back(rows* cols),
		m_front(rows* cols) {
	}
	void clear() {
		std::fill(m_back.begin(), m_back.end(), Cell{});
	}

	void put(int col, int row, std::string glyph, uint8_t bg_color, uint8_t fg_color, uint8_t style) {
		int row_sanitized = row - 1; // convert to 0-based index
		int col_sanitized = col - 1; // same for column
		if (row_sanitized < 0 || row_sanitized >= m_rows || col_sanitized < 0 || col_sanitized >= m_cols) {
			return; // out of bounds, ignore
		}

		int i = index(col_sanitized, row_sanitized);
		m_back[i].glyph = glyph;
		m_back[i].fg = fg_color;
		m_back[i].bg = bg_color;
		m_back[i].style = style;
	}

	void present() {
		m_output_buffer.clear(); // reset output buffer

		for (int i = 0; i < m_front.size(); i++)
		{
			if (m_front[i] != m_back[i]) { // only update cells that changed since last frame
				m_output_buffer += ansi::MOVE_TO((i % m_cols) + 1, (i / m_cols) + 1); // move cursor to this converted 1-based position
				m_output_buffer += ansi::BG256(m_back[i].bg); // set bg color
				m_output_buffer += ansi::FG256(m_back[i].fg); // set fg color = glyph color
				m_output_buffer += m_back[i].glyph;
			}
		}

		std::swap(m_front, m_back); // now the back buffer becomes the new front buffer for the next frame, and we can start drawing the next frame into the back buffer without affecting what's currently shown on screen

		std::cout << m_output_buffer << std::flush; // output the new front_buffer at once for better performance
	}
private:
	int m_rows, m_cols;
	struct Cell {
		std::string glyph = " ";
		uint8_t fg = 7;      // color id, or pack RGB
		uint8_t bg = 0;
		uint8_t style = 0;   // bitflags: bold, italic, etc.

		bool operator!=(const Cell& other) const {
			return glyph != other.glyph || fg != other.fg || bg != other.bg || style != other.style;
		}

	};
	std::vector<Cell> m_front; // what's currently on screen (shown)
	std::vector<Cell> m_back; // buffer to draw the next frame into

	std::string m_output_buffer; // reusable string buffer for building output

	int index(int col, int row) {
		return row * m_cols + col;
	}
};