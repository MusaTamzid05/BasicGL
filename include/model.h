#ifndef MODEL_H
#define MODEL_H

#include "shader.h"
#include <memory>
#include <string>



namespace OpenGLUtil {


    class Model {

        public:

            Model(const std::string& filepath = "");
            virtual void draw(Shader  shader) = 0;

    };

};
#endif
