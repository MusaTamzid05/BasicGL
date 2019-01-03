#ifndef MESH_H
#define MESH_H

#include <memory>
#include "shader.h"

namespace OpenGLUtil {

    class Mesh {

        public:

            Mesh() {}
            virtual ~Mesh() {}
            virtual void draw(Shader shader) = 0;

        protected:

            virtual void init_mesh() = 0;

            unsigned int VAO;
            unsigned int VBO;
            unsigned int EBO;
    };

};
#endif
