#include "rect_model.h"
#include "rect_mesh.h"

namespace OpenGLUtil  {

    RectModel::RectModel():
        Model("../shaders/shader") {
            meshes.push_back(std::make_shared<RectMesh>());
        }

};
