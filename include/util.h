#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Util {
    unsigned int load_texture_from_file(const char* path , const std::string& directory);
    void show_mat(const std::string& matrix_name , glm::mat4& matrix);
    std::vector<float> read_cordinates_from_file(const std::string& filepath);

    std::vector<std::string> split_string(const std::string& str , char dilimeter);
    void add_coordinate_from(const std::string& str , std::vector<float>& coordinates);
};
#endif
