#include "Renderer.h"
#include "World.h"
#include "TexturesInfo.h"

int main() {
    Renderer app;
    World w;

    app.setVertices(w.getVertices(), w.getIndices());

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}