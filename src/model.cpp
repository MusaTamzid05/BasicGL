#include "model.h"

namespace OpenGLUtil {

    Model::Model() {

    }

    void Model::draw(Shader shader) {

        for(std::shared_ptr<Mesh> mesh : meshes) 
            mesh->draw(shader);
    }
};
