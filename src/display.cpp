#include "display.h"
#include <iostream>

#include "camera.h"
#include "const.h"

namespace Engine {

    bool Display::first_mouse_move = true;
    Camera* Display::m_camera = new Camera(glm::vec3(0.0f , 0.0f , 3.0f));
    float Display::last_mouse_x = Const::WIDTH / 2.0f;
    float Display::last_mouse_y = Const::HEIGHT / 2.0f;
    float Display::delta_time = 0.0f;

    Display::Display(const std::string& window_name, bool enable_depth_test , bool update_camera):m_close(false) , last_frame(0.0f)  {

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR , 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE ,GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(Const::WIDTH , Const::HEIGHT, window_name.c_str(), nullptr , nullptr);

        if(m_window == nullptr) {
            std::cerr << "Failed to create GLFW window.\n";
            glfwTerminate();
            exit(1);
        }

        glfwMakeContextCurrent(m_window);
        set_callbacks();


        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD.\n";
            exit(1);
        }


        if(enable_depth_test)
            glEnable(GL_DEPTH_TEST);


    }

    Display::~Display() {

        glfwTerminate();

        if(m_camera != nullptr)
            delete m_camera;
    }

    void Display::set_callbacks(bool capture_mouse) {
        
        glfwSetFramebufferSizeCallback(m_window , frambuffer_size_callback);

        if(capture_mouse)
            glfwSetInputMode(m_window , GLFW_CURSOR , GLFW_CURSOR_NORMAL);
        else
            glfwSetInputMode(m_window , GLFW_CURSOR , GLFW_CURSOR_DISABLED);

        glfwSetScrollCallback(m_window , scroll_callback);
        glfwSetCursorPosCallback(m_window , mouse_callback);

    }


    float Display::get_zoom() { return m_camera->zoom; }


    glm::mat4 Display::get_view() { return m_camera->get_view_matrix(); }

    void Display::process_input() {

        if(glfwGetKey(m_window ,GLFW_KEY_ESCAPE) == GLFW_PRESS)
            m_close = true;

        if(glfwGetKey(m_window , GLFW_KEY_W) == GLFW_PRESS) 
            m_camera->process_keyboard(FORWARD , delta_time);


        if(glfwGetKey(m_window , GLFW_KEY_S) == GLFW_PRESS)
            m_camera->process_keyboard(BACKWARD, delta_time);

        if(glfwGetKey(m_window , GLFW_KEY_A) == GLFW_PRESS)
            m_camera->process_keyboard(LEFT, delta_time);


        if(glfwGetKey(m_window , GLFW_KEY_D) == GLFW_PRESS)
            m_camera->process_keyboard(RIGHT, delta_time);

    }

    void Display::update_frame() {

        float current_frame = glfwGetTime();
        delta_time = current_frame - last_frame;
        last_frame = current_frame;

    }


    void Display::update() {

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    void Display::clear() {


        glClearColor(0.2f , 0.3f , 0.3f , 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    }


    void Display::frambuffer_size_callback(GLFWwindow* window , int width , int height) {

        glViewport(0 , 0 , width , height);
    }

    
    void Display::mouse_callback(GLFWwindow* window , double xpos , double ypos) {

        if(first_mouse_move) {

            last_mouse_y = ypos;
            last_mouse_x = xpos;
            first_mouse_move = false;
        }

        float xoffset = xpos - last_mouse_x;
        float yoffset = last_mouse_y - ypos;

        last_mouse_x = xpos;
        last_mouse_y =  ypos;

        m_camera->process_mouse_movement(xoffset , yoffset);
    }

    
    void Display::scroll_callback(GLFWwindow* window , double xoffset, double yoffset) {
        m_camera->process_mouse_scroll( yoffset);
    }

    Camera* Display::get_camera() { return m_camera; }

}

