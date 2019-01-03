#include "model.h"

namespace OpenGLUtil {

    Model::Model(const std::string& shader_path):
    m_shader(std::make_shared<Shader>((shader_path + ".vs").c_str(), (shader_path + ".fs").c_str())){



    }

    void Model::draw() {

        for(std::shared_ptr<Mesh> mesh : meshes) 
            mesh->draw(*m_shader);
    }
};
