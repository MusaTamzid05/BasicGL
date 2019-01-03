#include "const.h"

#include "game.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace Engine {

    Game::Game(bool update_camera):
        m_display(std::make_unique<Display>("Window")),
        m_shader(std::make_unique<OpenGLUtil::Shader>("../shaders/model_loading.vs","../shaders/model_loading.fs")),
    update_camera_flag(update_camera){


        if(!update_camera_flag)
            std::cerr << "warning camera will not update,to update ,turn this flag on and update the shader.\n";

    }

    void Game::run() {

        while(!m_display->is_close()) {
            update_screen();
            process();
            m_display->update();
        }

    }

    void Game::update_screen() {
        
        m_display->update_frame();
        m_display->process_input();

        if(update_camera_flag)
            update_camera();

        m_display->clear();
    }

    void Game::process() {

        if(m_model == nullptr) {
            std::cout << "model is not set yet.\n";
            return;
        }

        m_model->draw(*m_shader);
    }

    void Game::update_camera() {
        
        m_shader->use();

        glm::mat4 projection = glm::perspective(glm::radians(m_display->get_zoom()), (float)Const::WIDTH /
                (float)Const::HEIGHT , 0.1f , 100.0f);

        glm::mat4 view =  m_display->get_view();

        m_shader->setMat4("projection" , projection);
        m_shader->setMat4("view" , view);


        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model , glm::vec3(0.0f , -1.75f , 0.0f));
        model = glm::scale(model , glm::vec3(0.2f , 0.2f , 0.2f));

        m_shader->setMat4("model" , model);

    }

};
