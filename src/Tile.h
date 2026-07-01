#pragma once
#include <string>
#include <cstdint>

enum class Tile {
	Empty,
	Floor,
	Border,
	Door,
	StairsUp,
	StairsDown,
	Trapdoor,
	Fence,
	Bridge,
	Water,
	Weaponsmith,
	Armorsmith,
	Teacher,
	Food,
	Alchemist,
	Bush,
	Tree,
	HrztlWall,
	VrtclWall,
	Weapon,
	Armor,
	Consumable,
};

struct TileInfo {
	std::string glyph;
	uint8_t fg, bg;
	bool walkable;
};

inline TileInfo getTileInfo(Tile tile) {
	switch (tile) {
	case Tile::Empty: return TileInfo{ " ", 7, 0, false };
	case Tile::Floor: return TileInfo{ ".", 95, 0, true };
	case Tile::Border: return TileInfo{ "#", 130, 0, false };
	case Tile::Bridge: return TileInfo{ "=", 137, 0, true };
	case Tile::VrtclWall: return TileInfo{ "|", 173, 0, false };
	case Tile::HrztlWall: return TileInfo{ "-", 173, 0, false };
	case Tile::Door: return TileInfo{ "+", 180, 0, true };
	case Tile::StairsUp: return TileInfo{ "<", 223, 0, true };
	case Tile::StairsDown: return TileInfo{ ">", 223, 0, true };
	case Tile::Trapdoor: return TileInfo{ "O", 94, 0, true };
	case Tile::Water: return TileInfo{ "~", 74, 0, false };
	case Tile::Weaponsmith: return TileInfo{ "W", 250, 0, true };
	case Tile::Armorsmith: return TileInfo{ "A", 244, 0, true };
	case Tile::Teacher: return TileInfo{ "T", 99, 0, true };
	case Tile::Food: return TileInfo{ "F", 208, 0, true };
	case Tile::Alchemist: return TileInfo{ "P", 39, 0, true };
	case Tile::Bush: return TileInfo{ "*", 28, 0, false };
	case Tile::Tree: return TileInfo{ "&", 22, 0, false };
	case Tile::Weapon: return TileInfo{ "!", 15, 0, true }; // base color is white, gets recolored based on weapon rarity
	case Tile::Armor: return TileInfo{ "]", 15, 0, true }; // same as above
	default: return TileInfo{ " ", 7, 0, false };
	}
}