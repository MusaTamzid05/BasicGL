#ifndef GAME_H
#define GAME_H

#include <memory>

#include "display.h"
#include "shader.h"
#include "model.h"

namespace Engine {

    class Game {

        public:

            explicit Game(bool update_camera = false);
            virtual ~Game() {}
            void run();

        private:

            std::unique_ptr<Display> m_display;

            void update_screen();

            void process();

            bool update_camera_flag;
            std::unique_ptr<OpenGLUtil::Model> m_model;

    };
}
#endif
