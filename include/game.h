#ifndef GAME_H
#define GAME_H

#include <memory>
#include "display.h"
#include "shader.h"

namespace Engine {

    class Game {

        public:

            explicit Game();
            virtual ~Game() {}
            void run();

        private:

            std::unique_ptr<Display> m_display;
            std::unique_ptr<OpenGLUtil::Shader> m_shader;

            void update_screen();
            void update_camera();

            void process();

    };
}
#endif