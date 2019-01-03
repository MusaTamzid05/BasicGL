#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

namespace OpenGLDataType {

    struct Vertex {

        Vertex(const glm::vec3& pos);
        glm::vec3 pos;
    };


};
#endif
