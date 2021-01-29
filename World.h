#pragma once
#include "SimplexNoise.h"
#include "Chunk.h"

constexpr int WORLD_NB_CHUNK = 10;

constexpr int WORLD_MAX_HEIGHT = 42;
constexpr int WORLD_MIN_HEIGHT = 32;

constexpr float SIMP_CORREC = 0.01;

static SimplexNoise simplex;

class World
{
private:
	Chunk* chunks[WORLD_NB_CHUNK][WORLD_NB_CHUNK];
	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;

public:
	World();
	~World();

	void updateVertices();

	std::vector<Vertex> getVertices();
	std::vector<uint32_t> getIndices();
};

