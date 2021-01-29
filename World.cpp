#include "World.h"

World::World()
{
	for (int i = 0; i < WORLD_NB_CHUNK; i++) {
		for (int j = 0; j < WORLD_NB_CHUNK; j++) {
			chunks[i][j] = new Chunk(i, j);
		}
	}
	std::cout << "\n\rattente du reste" << std::endl;
	updateVertices();
}

World::~World()
{
	vertices.clear();
	indices.clear();
	for (int i = 0; i < WORLD_NB_CHUNK; i++) {
		for (int j = 0; j < WORLD_NB_CHUNK; j++) {
			delete chunks[i][j];
		}
	}
}

std::vector<Vertex> World::getVertices()
{
	return vertices;
}

std::vector<uint32_t> World::getIndices()
{
	return indices;
}

void World::updateVertices()
{
	vertices.clear();
	indices.clear();
	for (int i = 0; i < WORLD_NB_CHUNK; i++) {
		for (int j = 0; j < WORLD_NB_CHUNK; j++) {
			std::vector<uint32_t> nvi = chunks[i][j]->getIndices();
			std::vector<Vertex> nv = chunks[i][j]->getVertices();

			int iOff = vertices.size();

			for (int i = 0; i < nv.size(); i++) {
				vertices.push_back(nv[i]);
			}
			for (int i = 0; i < nvi.size(); i++) {
				indices.push_back(nvi[i] + iOff);
			}
		}
	}
	for (int i = 0; i < WORLD_NB_CHUNK; i++) {
		for (int j = 0; j < WORLD_NB_CHUNK; j++) {
		}
	}

}
