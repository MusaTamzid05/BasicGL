#ifndef CAMERA_H
#define CAMERA_H

#include  <glm/glm.hpp>

namespace Engine {
    enum Camera_Movement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };


    const float YAW = -90.0f;
    const float PITCH = 0.0f;
    const float SPEED = 2.5f;
    const float SENSITIVITY = 0.1f;
    const float ZOOM = 45.0f;

    class Camera {
        
        public:

            glm::vec3 position;
            glm::vec3 front;
            glm::vec3 up;
            glm::vec3 right;
            glm::vec3 world_up;

            float yaw;
            float pitch;

            float movement_speed;
            float mouse_sensitivity;
            float zoom;

            Camera(glm::vec3 position = glm::vec3(0.0f , 0.0f , 0.0f) ,
                   glm::vec3 up = glm::vec3(0.0f , 1.0f , 0.0f),
                   float yaw = YAW,
                   float pitch = PITCH);

            Camera(float posX , float posY , float posZ , float upX , float upY , float upZ , float yaw,
                    float pitch);

            glm::mat4 get_view_matrix();

            void process_keyboard(Camera_Movement direction , float delta_time);
            void process_mouse_movement(float xoffset , float yoffset , bool constrainPitch = true);
            void process_mouse_scroll(float yoffset);


        private:

            void update_camera_vectors();


    };
};
#endif
