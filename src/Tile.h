#pragma once
#include <string>
#include <cstdint>

enum class Tile {
	Empty,
	Floor,
	Wall,
	Door,
	StairsUp,
	StairsDown,
	Trapdoor,
};

struct TileInfo {
	std::string glyph;
	uint8_t fg, bg;
	bool walkable;
};

inline TileInfo getTileInfo(Tile tile) {
	switch (tile) {
	case Tile::Empty: return TileInfo{ " ", 7, 0, false };
	case Tile::Floor: return TileInfo{ ".", 7, 0, true };
	case Tile::Wall: return TileInfo{ "#", 7, 0, false };
	case Tile::Door: return TileInfo{ "+", 7, 0, true };
	case Tile::StairsUp: return TileInfo{ "<", 7, 0, true };
	case Tile::StairsDown: return TileInfo{ ">", 7, 0, true };
	case Tile::Trapdoor: return TileInfo{ "O", 7, 0, true };
	default: return TileInfo{ " ", 7, 0, false };
	}
}