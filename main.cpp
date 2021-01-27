#include "Renderer.h"
#include "Chunk.h"
#include "TexturesInfo.h"

int main() {
    Renderer app;
    Chunk c;
    c.updateVertex();
    app.setVertices(c.getVertices(), c.getIndices());
    //app.addFace(-1, 0, 0, BLOCK_TEST, NORTH);
    //app.addFace(-1, 0, 0, BLOCK_TEST, SOUTH);
    //app.addFace(-1, 0, 0, BLOCK_TEST, EAST);
    //app.addFace(-1, 0, 0, BLOCK_TEST, WEST);
    //app.addFace(-1, 0, 0, BLOCK_TEST, UP);
    //app.addFace(-1, 0, 0, BLOCK_TEST, DOWN);

    //app.addFace(1, 0, 0, BLOCK_TEST, NORTH);
    //app.addFace(1, 0, 0, BLOCK_TEST, SOUTH);
    //app.addFace(1, 0, 0, BLOCK_TEST, EAST);
    //app.addFace(1, 0, 0, BLOCK_TEST, WEST);
    //app.addFace(1, 0, 0, BLOCK_TEST, UP);
    //app.addFace(1, 0, 0, BLOCK_TEST, DOWN);

    //app.addFace(0, 0, -1, BLOCK_TEST, NORTH);
    //app.addFace(0, 0, -1, BLOCK_TEST, SOUTH);
    //app.addFace(0, 0, -1, BLOCK_TEST, EAST);
    //app.addFace(0, 0, -1, BLOCK_TEST, WEST);
    //app.addFace(0, 0, -1, BLOCK_TEST, UP);
    //app.addFace(0, 0, -1, BLOCK_TEST, DOWN);

    //app.addFace(0, 0, 1, BLOCK_TEST, NORTH);
    //app.addFace(0, 0, 1, BLOCK_TEST, SOUTH);
    //app.addFace(0, 0, 1, BLOCK_TEST, EAST);
    //app.addFace(0, 0, 1, BLOCK_TEST, WEST);
    //app.addFace(0, 0, 1, BLOCK_TEST, UP);
    //app.addFace(0, 0, 1, BLOCK_TEST, DOWN);

    //app.addFace(1, 1, 0, BLOCK_TEST, NORTH);
    //app.addFace(1, 1, 0, BLOCK_TEST, SOUTH);
    //app.addFace(1, 1, 0, BLOCK_TEST, EAST);
    //app.addFace(1, 1, 0, BLOCK_TEST, WEST);
    //app.addFace(1, 1, 0, BLOCK_TEST, UP);
    //app.addFace(1, 1, 0, BLOCK_TEST, DOWN);

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}