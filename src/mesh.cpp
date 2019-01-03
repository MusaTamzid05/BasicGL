#include "mesh.h"

namespace OpenGLUtil {

    Mesh::~Mesh() {
        
        glDeleteVertexArrays(1 , &VAO);
        glDeleteBuffers(1 , &VBO);
        glDeleteBuffers(1 , &EBO);
    }
}
