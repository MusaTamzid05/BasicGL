#ifndef MODEL_H
#define MODEL_H

#include "shader.h"
#include "mesh.h"
#include <memory>
#include <vector>



namespace OpenGLUtil {


    class Model {

        public:

            Model();
            virtual ~Model() {}
            void draw(Shader shader);

        protected:

            std::vector<std::shared_ptr<Mesh>> meshes;

    };

};
#endif
