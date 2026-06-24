#pragma once
#include "Tile.h"
#include <vector>


class Map {

public:
	size_t rows() {
		return m_rows;
	}
	size_t cols() {
		return m_cols;
	}

	Map() {
		// determine map dimensions based on map_layout
		m_rows = map_layout.empty() ? 0 : map_layout.size();
		m_cols = map_layout.empty() ? 0 : map_layout[0].size();
		for (const std::string& row : map_layout) {
			for (size_t i = 0; i < row.length(); i++)
			{
				switch (row[i]) {
				case '.': map.push_back(Tile::Floor); break;
				case '#': map.push_back(Tile::Wall); break;
				case '+': map.push_back(Tile::Door); break;
				case '<': map.push_back(Tile::StairsUp); break;
				case '>': map.push_back(Tile::StairsDown); break;
				case 'O': map.push_back(Tile::Trapdoor); break;
				case '|': map.push_back(Tile::Fence); break;
				case '=': map.push_back(Tile::Bridge); break;
				case '~': map.push_back(Tile::Water); break;
				case 'V': map.push_back(Tile::Vendor); break;
				default: map.push_back(Tile::Empty); // ignore unknown characters, treat as empty space
				}
			}
		}
	}

	Tile tileAt(int col, int row) {
		int row_sanitized = row - 1; // convert to 0-based index
		int col_sanitized = col - 1; // same for column
		// technically not necessary to check, since map_layout should have boundaries on all sides, but good to be safe
		if (row_sanitized < 0 || row_sanitized >= m_rows || col_sanitized < 0 || col_sanitized >= m_cols) {
			return Tile::Empty; // out of bounds, treat as empty space
		}
		int i = index(col_sanitized, row_sanitized);
		return map[i];
	}

	bool isWalkable(int col, int row) {
		int row_sanitized = row - 1; // convert to 0-based index
		int col_sanitized = col - 1; // same for column

		// technically not necessary to check, since map_layout should have boundaries on all sides, but good to be safe
		if (row_sanitized < 0 || row_sanitized >= m_rows || col_sanitized < 0 || col_sanitized >= m_cols) {
			return false; // out of bounds, ignore
		}
		int i = index(col_sanitized, row_sanitized);
		return getTileInfo(map[i]).walkable;
	}

private:
	std::vector<std::string> map_layout = {
		"##########    ~~    ",
		"#........#    ~~    ",
		"#+###....######~####",
		"    #.........===..+",
		"    #........##~####",
		"    #..|V|...# ~~   ",
		"    ########## ~~~  "
	};

	std::vector<Tile> map;
	size_t m_cols; // this will be set to the length of the longest string in map_layout
	size_t m_rows; // this will be set to the number of strings in map_layout

	int index(int col, int row) {
		return row * m_cols + col;
	}
};



