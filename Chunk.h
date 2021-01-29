#pragma once
#include "Renderer.h"
constexpr int CHUNK_SIZE = 32;
constexpr int CHUNK_HEIGHT = 128;

class Chunk
{
private:
	struct iVec2
	{
		int x;
		int z;
	};

	int blocks[CHUNK_SIZE][CHUNK_HEIGHT][CHUNK_SIZE];

	iVec2 chunkPos;

	std::vector<Vertex> chunkVertices;
	std::vector<uint32_t> chunkIndices;

public:
	Chunk(int chunkX, int chunkZ);
	~Chunk();

	void updateVertex();
	std::vector<Vertex> getVertices();
	std::vector<uint32_t> getIndices();
};

