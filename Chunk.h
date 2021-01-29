#pragma once
#include "Renderer.h"
constexpr int CHUNK_SIZE = 16;
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

	void updateVertex(Chunk* north, Chunk* east, Chunk* south, Chunk* west);
	std::vector<Vertex> getVertices();
	std::vector<uint32_t> getIndices();
	int getBlock(int x, int y, int z);
};

