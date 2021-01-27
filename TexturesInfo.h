#pragma once
struct Vect2 {
	float x;
	float y;
};

constexpr float NB_TEXTURE = 8;

enum { NORTH, EAST, SOUTH, WEST, UP, DOWN };

enum {
	NO_BLOCK,
	BLOCK_GRASS,
	BLOCK_DIRT
};

// SIDE, UP, DOWN
constexpr Vect2 TEXTURES[][3] = {
	{{ 0, 0 }, { 1, 0 }, { 0, 1 }},
	{{ 0, 1 }, { 0, 1 }, { 0, 1 }}
};