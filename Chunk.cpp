#include "World.h"
#include "Chunk.h"
#include "TexturesInfo.h"

Chunk::Chunk(int chunkX, int chunkZ)
{
	chunkPos = { chunkX, chunkZ };
	for (int x = 0; x < CHUNK_SIZE; x++) {
		for (int y = 0; y < CHUNK_HEIGHT; y++) {
			for (int z = 0; z < CHUNK_SIZE; z++) {
				float sX = float(chunkX * CHUNK_SIZE + x) * SIMP_CORREC;
				float sZ = float(chunkZ * CHUNK_SIZE + z) * SIMP_CORREC;
				int maxHeight = (1 + simplex.noise(sX, sZ)) / 2 * WORLD_MAX_HEIGHT + WORLD_MIN_HEIGHT;
				if (y == maxHeight)
					blocks[x][y][z] = BLOCK_GRASS;
				else if (y < maxHeight) {
					blocks[x][y][z] = (y <= maxHeight - 3) ? BLOCK_STONE : BLOCK_DIRT;
				}
			}
		}
	}
}

Chunk::~Chunk()
{
	chunkIndices.clear();
	chunkVertices.clear();
}

void Chunk::updateVertex(Chunk* north, Chunk* east, Chunk* south, Chunk* west)
{
	float xOff = (float)(chunkPos.x * CHUNK_SIZE);
	float zOff = (float)(chunkPos.z * CHUNK_SIZE);
	chunkIndices.clear();
	chunkVertices.clear();
	for (int x = 0; x < CHUNK_SIZE; x++) {
		for (int y = 0; y < CHUNK_HEIGHT; y++) {
			for (int z = 0; z < CHUNK_SIZE; z++) {
				if (blocks[x][y][z] != NO_BLOCK) {
					Vect2* texs = (Vect2*)TEXTURES[blocks[x][y][z] - 1];
					// pour toutes les directions, on regarde si il n'y a pas de block à coté, ou que l'on est pas en bord de chunk
					// nord
					if ((x == CHUNK_SIZE - 1 && ((north == nullptr) || (north != nullptr && !north->getBlock(0, y, z)))) || (x != CHUNK_SIZE - 1 && !blocks[x + 1][y][z])) {
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkVertices.push_back(Vertex(1.0f + x + xOff, 0.0f + y, 0.0f + z + zOff, texs[0].x + 1, texs[0].y + 1, NS_SHADOW));
						chunkVertices.push_back(Vertex(1.0f + x + xOff, 1.0f + y, 0.0f + z + zOff, texs[0].x + 1, texs[0].y, NS_SHADOW));
						chunkVertices.push_back(Vertex(1.0f + x + xOff, 1.0f + y, 1.0f + z + zOff, texs[0].x, texs[0].y, NS_SHADOW));
						chunkVertices.push_back(Vertex(1.0f + x + xOff, 0.0f + y, 1.0f + z + zOff, texs[0].x, texs[0].y + 1, NS_SHADOW));
					}
					// sud 
					if ((!x && ((south == nullptr) || (south != nullptr && !south->getBlock(CHUNK_SIZE - 1, y, z)))) || (x && !blocks[x - 1][y][z])) {
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkVertices.push_back(Vertex(0.0f + x + xOff, 0.0f + y, 0.0f + z + zOff, texs[0].x, texs[0].y + 1, NS_SHADOW));
						chunkVertices.push_back(Vertex(0.0f + x + xOff, 1.0f + y, 0.0f + z + zOff, texs[0].x, texs[0].y, NS_SHADOW));
						chunkVertices.push_back(Vertex(0.0f + x + xOff, 0.0f + y, 1.0f + z + zOff, texs[0].x + 1, texs[0].y + 1, NS_SHADOW));
						chunkVertices.push_back(Vertex(0.0f + x + xOff, 1.0f + y, 1.0f + z + zOff, texs[0].x + 1, texs[0].y, NS_SHADOW));
					}
					// EST
					if ((z == CHUNK_SIZE - 1 && ((east == nullptr) || (east != nullptr && !east->getBlock(x, y, 0)))) || (z != CHUNK_SIZE - 1 && !blocks[x][y][z + 1])) {
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkVertices.push_back(Vertex(0.0f + x + xOff, 0.0f + y, 1.0f + z + zOff, texs[0].x, texs[0].y + 1, EW_SHADOW));
						chunkVertices.push_back(Vertex(0.0f + x + xOff, 1.0f + y, 1.0f + z + zOff, texs[0].x, texs[0].y, EW_SHADOW));
						chunkVertices.push_back(Vertex(1.0f + x + xOff, 0.0f + y, 1.0f + z + zOff, texs[0].x + 1, texs[0].y + 1, EW_SHADOW));
						chunkVertices.push_back(Vertex(1.0f + x + xOff, 1.0f + y, 1.0f + z + zOff, texs[0].x + 1, texs[0].y, EW_SHADOW));
					}
					// ouest
					if ((!z && ((west == nullptr) || (west != nullptr && !west->getBlock(x, y, CHUNK_SIZE - 1)))) || (z && !blocks[x][y][z - 1])) {
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkVertices.push_back(Vertex(0.0f + x + xOff, 1.0f + y, 0.0f + z + zOff, texs[0].x + 1, texs[0].y, EW_SHADOW));
						chunkVertices.push_back(Vertex(1.0f + x + xOff, 1.0f + y, 0.0f + z + zOff, texs[0].x, texs[0].y, EW_SHADOW));
						chunkVertices.push_back(Vertex(0.0f + x + xOff, 0.0f + y, 0.0f + z + zOff, texs[0].x + 1, texs[0].y + 1, EW_SHADOW));
						chunkVertices.push_back(Vertex(1.0f + x + xOff, 0.0f + y, 0.0f + z + zOff, texs[0].x, texs[0].y + 1, EW_SHADOW));
					}
					// UP
					if (y == CHUNK_HEIGHT - 1 || !blocks[x][y + 1][z]) {
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkVertices.push_back(Vertex(0.0f + x + xOff, 1.0f + y, 0.0f + z + zOff, texs[1].x, texs[1].y + 1, TOP_SHADOW));
						chunkVertices.push_back(Vertex(1.0f + x + xOff, 1.0f + y, 0.0f + z + zOff, texs[1].x, texs[1].y, TOP_SHADOW));
						chunkVertices.push_back(Vertex(1.0f + x + xOff, 1.0f + y, 1.0f + z + zOff, texs[1].x + 1, texs[1].y, TOP_SHADOW));
						chunkVertices.push_back(Vertex(0.0f + x + xOff, 1.0f + y, 1.0f + z + zOff, texs[1].x + 1, texs[1].y + 1, TOP_SHADOW));
					}
					//down
					if (y == 0 || !blocks[x][y - 1][z]) {
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 0);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 3);
						chunkIndices.push_back(chunkVertices.size() + 1);
						chunkIndices.push_back(chunkVertices.size() + 2);
						chunkVertices.push_back(Vertex(0.0f + x + xOff, 0.0f + y, 0.0f + z + zOff, texs[2].x + 1, texs[2].y + 1, BOTTOM_SHADOW));
						chunkVertices.push_back(Vertex(1.0f + x + xOff, 0.0f + y, 0.0f + z + zOff, texs[2].x + 1, texs[2].y, BOTTOM_SHADOW));
						chunkVertices.push_back(Vertex(1.0f + x + xOff, 0.0f + y, 1.0f + z + zOff, texs[2].x, texs[2].y, BOTTOM_SHADOW));
						chunkVertices.push_back(Vertex(0.0f + x + xOff, 0.0f + y, 1.0f + z + zOff, texs[2].x, texs[2].y + 1, BOTTOM_SHADOW));
					}
				}
			}
		}
	}
	chunkVertices.shrink_to_fit();
	chunkIndices.shrink_to_fit();
}

std::vector<Vertex> Chunk::getVertices()
{
	return chunkVertices;
}

std::vector<uint32_t> Chunk::getIndices()
{
	return chunkIndices;
}

int Chunk::getBlock(int x, int y, int z)
{
	if (x == 0 && y == 0) {
		blocks[x][y][z] = blocks[x][y][z];
	}
	return blocks[x][y][z];
}
