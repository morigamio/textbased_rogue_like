#pragma once
#include <cstdint>
#include <string>
#include <vector>

class Screen {
public:

	Screen(int rows, int cols) :
		m_rows(rows), m_cols(cols),
		m_back(rows* cols),
		m_front(rows* cols) {
	}
	void clear() {

	}

	void put(int col, int row, std::string glyph, uint8_t color, uint8_t style) {

	}

	void present() {
		for (int i = 0; i < m_front.size(); i++)
		{

		}
	}
private:
	int m_rows, m_cols;
	struct Cell {
		std::string glyph = " ";
		uint8_t fg = 7;      // color id, or pack RGB
		uint8_t bg = 0;
		uint8_t style = 0;   // bitflags: bold, italic, etc.
	};
	std::vector<Cell> m_front; // the actual screen content to be rendered
	std::vector<Cell> m_back; // the content of the previous frame, used for diffing and optimizing rendering


	int index(int row, int col) {
		return row * m_cols + col;
	}
};