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
	Fence,
	Bridge,
	Water,
	Vendor
};

struct TileInfo {
	std::string glyph;
	uint8_t fg, bg;
	bool walkable;
};

inline TileInfo getTileInfo(Tile tile) {
	switch (tile) {
	case Tile::Empty: return TileInfo{ " ", 7, 0, false };
	case Tile::Floor: return TileInfo{ ".", 246, 0, true };
	case Tile::Wall: return TileInfo{ "#", 130, 0, false };
	case Tile::Door: return TileInfo{ "+", 180, 0, true };
	case Tile::StairsUp: return TileInfo{ "<", 7, 0, true };
	case Tile::StairsDown: return TileInfo{ ">", 7, 0, true };
	case Tile::Trapdoor: return TileInfo{ "O", 7, 0, true };
	case Tile::Fence: return TileInfo{ "|", 144, 0, false };
	case Tile::Bridge: return TileInfo{ "=", 137, 0, true };
	case Tile::Water: return TileInfo{ "~", 117, 0, false };
	case Tile::Vendor: return TileInfo{ "V", 226, 0, true };
	default: return TileInfo{ " ", 7, 0, false };
	}
}