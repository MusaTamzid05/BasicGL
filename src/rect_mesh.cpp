#include "rect_mesh.h"
#include "util.h"

namespace OpenGLUtil {

    RectMesh::RectMesh() {

        init_mesh();
    }

    void RectMesh::draw(Shader shader) {

        shader.use();

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , 0);

    }

    void RectMesh::init_mesh() {

        std::vector<float> vertices = Util::read_cordinates_from_file("../res/coordinates.txt");
        
        int indicies[] = {
            0 , 1 , 3,
            1, 2 , 3
        };

        std::vector<unsigned int> ind_vector(indicies ,
                 indicies + sizeof(indicies) / sizeof(unsigned int)
                );

        
        glGenVertexArrays(1 , &VAO);
        glGenBuffers(1 , &VBO);
        glGenBuffers(1 , &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER , VBO);
        glBufferData(GL_ARRAY_BUFFER , vertices.size() * sizeof(unsigned int) , &vertices[0] , GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER , sizeof(indicies) , indicies , GL_STATIC_DRAW);

        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 3 * sizeof(float) , (void*) 0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER , 0);

        glBindVertexArray(0);

    }
};
