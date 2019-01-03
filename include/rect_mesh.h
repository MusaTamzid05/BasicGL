#ifndef RECT_MESH_H
#define RECT_MESH_H

#include "mesh.h"

namespace OpenGLUtil {

    class RectMesh : public Mesh {

        public:
            RectMesh();
            void draw(Shader shader);
        private:

            void init_mesh();


    };
};

#endif
