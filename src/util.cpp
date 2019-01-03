#include "util.h"
#include "stb_image.h"


#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>

namespace Util {

    unsigned int load_texture_from_file(const char* path , const std::string& directory) {
        
        std::string filename = std::string(path);
        filename = directory + '/' + filename;

        unsigned int textureID;
        glGenTextures(1 , &textureID);

        int width , height , nrComponents;
        unsigned char* data = stbi_load(filename.c_str() , &width , &height , &nrComponents , 0);

        if(data) {

            GLenum format;
            
            if(nrComponents == 1)
                format = GL_RED;
            else if(nrComponents == 3)
                format = GL_RGB;
            else if(nrComponents == 4)
                format = GL_RGBA;


            glBindTexture(GL_TEXTURE_2D , textureID);
            glTexImage2D(GL_TEXTURE_2D , 0 , format , width , height , 0 , format ,  GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR);
            
            stbi_image_free(data);

        } else {
            std::cout << "Texture failed to load at path " << path << "\n";
            stbi_image_free(data);
        }

    
        return textureID;
    }


    void show_mat( const std::string& matrix_name ,glm::mat4& matrix) {

        std::cout << "============ " << matrix_name << "================\n";
        for(unsigned int i = 0 ; i < 4 ; i++)  {
            for(unsigned int j = 0 ; j < 4 ; j++)
                std::cout << matrix[i][j] << " ";

            std::cout << "\n";

        }


        std::cout << "============ ================\n";
    }


    std::vector<float> read_cordinates_from_file(const std::string& filepath) {

        std::vector<float> coordinates;

        std::ifstream input_file(filepath , std::ifstream::in);

        if(!input_file.is_open()) {

            std::cerr << "Could not open " << filepath << ".\n";
            return coordinates;
        }

        std::string line;

        while(std::getline(input_file , line)) 
            add_coordinate_from(line , coordinates);


        input_file.close();

        std::cout << "Total coordinates found : " << coordinates.size() << "\n";
        return coordinates;
    }


    std::vector<std::string> split_string(const std::string& str , char dilimeter) {

        std::stringstream ss(str);
        std::vector<std::string> result;
        std::string buff;

        while(std::getline(ss, buff , dilimeter))
            result.push_back(buff);

        return result;
    }

    void add_coordinate_from(const std::string& str , std::vector<float>& coordinates) {

        std::vector<std::string> result = split_string(str , ',');

        for(std::string number : result) 
            coordinates.push_back(atof(number.c_str()));
    }

};
