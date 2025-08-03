#标题
cmake_minimum_required(VERSION 3.10.0)
project(space_shooter VERSION 0.1.0 LANGUAGES C CXX)
#设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#设置编译选项
if(MSVC)
    add_compile_options(/W4)
elseif(APPLE)
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()
#设置编译输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

set(TARGET ${PROJECT_NAME}_${CMAKE_SYSTEM_NAME}_${PROJECT_VERSION})
#查找SDL3库
find_package(SDL3 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)

#添加可执行文件
add_executable(${TARGET} main.cpp)
#链接SDL3库
target_link_libraries(${TARGET} 
                    SDL3::SDL3 
                    SDL2_mixer::SDL2_mixer 
                    SDL3_image::SDL3_image 
                    SDL3_ttf::SDL3_ttf)


