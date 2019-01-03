#include "const.h"

#include "game.h"
#include "rect_model.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace Engine {

    Game::Game(bool update_camera):
        m_display(std::make_unique<Display>("Window")),
    update_camera_flag(update_camera){


        if(!update_camera_flag)
            std::cerr << "warning camera will not update,to update ,turn this flag on and update the shader.\n";

        m_model = std::make_unique<OpenGLUtil::RectModel>();
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


        m_display->clear();
    }

    void Game::process() {

        if(m_model == nullptr) {
            std::cout << "model is not set yet.\n";
            return;
        }

        m_model->draw();
    }

};
