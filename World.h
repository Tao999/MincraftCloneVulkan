#pragma once
#include "SimplexNoise.h"
#include "Chunk.h"

constexpr int WORLD_NB_CHUNK = 100;

constexpr int WORLD_MAX_HEIGHT = CHUNK_HEIGHT;
constexpr int WORLD_MIN_HEIGHT = 64;

constexpr float SIMP_CORREC = 0.005;

static SimplexNoise simplex(1.0f, 1.0f, 2.0f, 0.5f);

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

