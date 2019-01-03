#ifndef MODEL_H
#define MODEL_H

#include "shader.h"
#include "mesh.h"
#include <memory>
#include <vector>



namespace OpenGLUtil {


    class Model {

        public:

            Model(const std::string& shader_path);
            virtual ~Model() {}
            void draw();

        protected:

            std::vector<std::shared_ptr<Mesh>> meshes;
            std::shared_ptr<Shader> m_shader;
    };

};
#endif
