#pragma once
struct Vect2 {
	float x;
	float y;
};

constexpr float NB_TEXTURE = 8;

constexpr float TOP_SHADOW = 1;
constexpr float NS_SHADOW = 0.75;
constexpr float EW_SHADOW = 0.5;
constexpr float BOTTOM_SHADOW = 0.25;

enum { NORTH, EAST, SOUTH, WEST, UP, DOWN };

enum {
	NO_BLOCK,
	BLOCK_GRASS,
	BLOCK_DIRT,
	BLOCK_STONE,
	BLOCK_SNOW,
};

// SIDE, UP, DOWN
constexpr Vect2 TEXTURES[][3] = {
	{{ 1, 1 }, { 3, 1 }, { 1, 3 }},
	{{ 1, 3 }, { 1, 3 }, { 1, 3 }},
	{{ 3, 3 }, { 3, 3 }, { 3, 3 }},
	{{ 1, 5 }, { 1, 5 }, { 1, 5 }},
};