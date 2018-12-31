#ifndef DISPLAY_H
#define DISPLAY_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

#include <glm/glm.hpp>

namespace Engine {

    class Camera;


    class Display {


        public:

            Display(const std::string& window_name , bool enable_depth_test = true);
            virtual ~Display();

            void process_input();
            void update();
            void clear();

            bool is_close() { return m_close; }

            float get_zoom();
            glm::mat4 get_view();

            void update_frame();

            GLFWwindow* get_window() { return m_window; }
            Camera* get_camera();

        protected:

            GLFWwindow* m_window;
            bool m_close;
            
            static void frambuffer_size_callback(GLFWwindow* window , int width , int height);
            static void mouse_callback(GLFWwindow* window , double xpos , double ypos);
            static void scroll_callback(GLFWwindow* window , double xoffset, double yoffset);

            void set_callbacks(bool capture_mouse = false);


            // this are the data that we will init.
            static Camera* m_camera;
            static float last_mouse_y;
            static float last_mouse_x;
            static bool first_mouse_move; // sets to true so that we do some calculation on the first mouse move.
            static float delta_time;
            
            float last_frame;




    };
    

};

#endif
