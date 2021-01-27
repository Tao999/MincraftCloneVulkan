#include "Chunk.h"
#include "TexturesInfo.h"

Chunk::Chunk()
{
	for (int x = 0; x < CHUNK_SIZE; x++) {
		for (int y = 0; y < CHUNK_HEIGHT; y++) {
			for (int z = 0; z < CHUNK_SIZE; z++) {
				if ((z + x >= y && y == CHUNK_HEIGHT - 1) || z + x == y)
					blocks[x][y][z] = BLOCK_GRASS;
				else if (z + x > y)
					blocks[x][y][z] = BLOCK_DIRT;
			}
		}
	}
}

Chunk::~Chunk()
{
	chunkIndices.clear();
	chunkVertices.clear();
}

void Chunk::updateVertex()
{
	chunkIndices.clear();
	chunkVertices.clear();
	for (int x = 0; x < CHUNK_SIZE; x++) {
		for (int y = 0; y < CHUNK_HEIGHT; y++) {
			for (int z = 0; z < CHUNK_SIZE; z++) {
				if (blocks[x][y][z] != NO_BLOCK) {
					Vect2* texs = (Vect2*)TEXTURES[blocks[x][y][z] - 1];
					// pour toutes les directions, on regarde si il n'y a pas de block à coté, ou que l'on est pas en bord de chunk
					// nord
					if (x == CHUNK_SIZE - 1 || blocks[x + 1][y][z] == NO_BLOCK) {
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkVertices.push_back(Vertex(1.0f + x, 0.0f + y, 0.0f + z, texs[0].x + 1, texs[0].y + 1));
						chunkVertices.push_back(Vertex(1.0f + x, 1.0f + y, 0.0f + z, texs[0].x + 1, texs[0].y));
						chunkVertices.push_back(Vertex(1.0f + x, 1.0f + y, 1.0f + z, texs[0].x, texs[0].y));
						chunkVertices.push_back(Vertex(1.0f + x, 0.0f + y, 1.0f + z, texs[0].x, texs[0].y + 1));
					}
					// sud
					if (x == 0 || blocks[x - 1][y][z] == NO_BLOCK) {
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkVertices.push_back(Vertex(0.0f + x, 0.0f + y, 0.0f + z, texs[0].x, texs[0].y + 1));
						chunkVertices.push_back(Vertex(0.0f + x, 1.0f + y, 0.0f + z, texs[0].x, texs[0].y));
						chunkVertices.push_back(Vertex(0.0f + x, 0.0f + y, 1.0f + z, texs[0].x + 1, texs[0].y + 1));
						chunkVertices.push_back(Vertex(0.0f + x, 1.0f + y, 1.0f + z, texs[0].x + 1, texs[0].y));
					}
					// EST
					if (z == CHUNK_SIZE - 1 || blocks[x][y][z + 1] == NO_BLOCK) {
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkVertices.push_back(Vertex(0.0f + x, 0.0f + y, 1.0f + z, texs[0].x, texs[0].y + 1));
						chunkVertices.push_back(Vertex(0.0f + x, 1.0f + y, 1.0f + z, texs[0].x, texs[0].y));
						chunkVertices.push_back(Vertex(1.0f + x, 0.0f + y, 1.0f + z, texs[0].x + 1, texs[0].y + 1));
						chunkVertices.push_back(Vertex(1.0f + x, 1.0f + y, 1.0f + z, texs[0].x + 1, texs[0].y));
					}
					// ouest
					if (z == 0 || blocks[x][y][z - 1] == NO_BLOCK) {
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkVertices.push_back(Vertex(0.0f + x, 1.0f + y, 0.0f + z, texs[0].x + 1, texs[0].y));
						chunkVertices.push_back(Vertex(1.0f + x, 1.0f + y, 0.0f + z, texs[0].x, texs[0].y));
						chunkVertices.push_back(Vertex(0.0f + x, 0.0f + y, 0.0f + z, texs[0].x + 1, texs[0].y + 1));
						chunkVertices.push_back(Vertex(1.0f + x, 0.0f + y, 0.0f + z, texs[0].x, texs[0].y + 1));
					}
					// UP
					if (y == CHUNK_HEIGHT - 1 || blocks[x][y + 1][z] == NO_BLOCK) {
						//Vect2 temp = TEXTURES[0][1];
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkVertices.push_back(Vertex(0.0f + x, 1.0f + y, 0.0f + z, texs[1].x, texs[1].y + 1));
						chunkVertices.push_back(Vertex(1.0f + x, 1.0f + y, 0.0f + z, texs[1].x, texs[1].y));
						chunkVertices.push_back(Vertex(1.0f + x, 1.0f + y, 1.0f + z, texs[1].x + 1, texs[1].y));
						chunkVertices.push_back(Vertex(0.0f + x, 1.0f + y, 1.0f + z, texs[1].x + 1, texs[1].y + 1));
					}
					//down
					if (y == 0 || blocks[x][y - 1][z] == NO_BLOCK) {
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkVertices.push_back(Vertex(0.0f + x, 0.0f + y, 0.0f + z, texs[2].x + 1, texs[2].y + 1));
						chunkVertices.push_back(Vertex(1.0f + x, 0.0f + y, 0.0f + z, texs[2].x + 1, texs[2].y));
						chunkVertices.push_back(Vertex(1.0f + x, 0.0f + y, 1.0f + z, texs[2].x, texs[2].y));
						chunkVertices.push_back(Vertex(0.0f + x, 0.0f + y, 1.0f + z, texs[2].x, texs[2].y + 1));
					}
				}
			}
		}
	}
}

std::vector<Vertex> Chunk::getVertices()
{
	return chunkVertices;
}

std::vector<int> Chunk::getIndices()
{
	return chunkIndices;
}
