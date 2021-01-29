#include "World.h"

World::World()
{
	for (int i = 0; i < WORLD_NB_CHUNK; i++) {
		for (int j = 0; j < WORLD_NB_CHUNK; j++) {
			std::cout << "Chunk Gen : " << int(float(i * WORLD_NB_CHUNK + j) / float(WORLD_NB_CHUNK * WORLD_NB_CHUNK) * 100) << "%\r";
			chunks[i][j] = new Chunk(i, j);
		}
	}
	std::cout << std::endl;
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
	//calcules des vertices des chunks
	for (int i = 0; i < WORLD_NB_CHUNK; i++) {
		for (int j = 0; j < WORLD_NB_CHUNK; j++) {
			std::cout << "chargement des vertices : " << int(float(i * WORLD_NB_CHUNK + j) / float(WORLD_NB_CHUNK * WORLD_NB_CHUNK) * 100) << "%\r";
			Chunk* north = (i + 1 < WORLD_NB_CHUNK) ? chunks[i + 1][j] : nullptr;
			Chunk* east = (j + 1 < WORLD_NB_CHUNK) ? chunks[i][j + 1] : nullptr;
			Chunk* south = (i - 1 >= 0) ? chunks[i - 1][j] : nullptr;
			Chunk* west = (j - 1 >= 0) ? chunks[i][j - 1] : nullptr;

			chunks[i][j]->updateVertex(north, east, south, west);
		}
	}

	std::cout << std::endl;

	//calculs des vertices du monde
	vertices.clear();
	indices.clear();
	for (int i = 0; i < WORLD_NB_CHUNK; i++) {
		for (int j = 0; j < WORLD_NB_CHUNK; j++) {
			std::cout << "copie des vertices : " << int(float(i * WORLD_NB_CHUNK + j) / float(WORLD_NB_CHUNK * WORLD_NB_CHUNK) * 100) << "%\r";
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
	std::cout << std::endl << "copie des vertices dans les buffers..." << std::endl;

}
