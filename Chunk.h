#pragma once
#include "Renderer.h"
constexpr int CHUNK_SIZE = 16;
constexpr int CHUNK_HEIGHT = 128;

class Chunk
{
private:
	int blocks[CHUNK_SIZE][CHUNK_HEIGHT][CHUNK_SIZE];
	std::vector<Vertex> chunkVertices;
	std::vector<int> chunkIndices;

public:
	Chunk();
	~Chunk();

	void updateVertex();
	std::vector<Vertex> getVertices();
	std::vector<int> getIndices();
};

