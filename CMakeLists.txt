cmake_minimum_required(VERSION 3.26)
project(squares_test_cpp)

add_subdirectory(dependencies)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE all_SRCS "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/include/*.h")

include_directories(
        "${PROJECT_SOURCE_DIR}/include/"
        "${PROJECT_SOURCE_DIR}/dependencies/glad/include/"
        "${PROJECT_SOURCE_DIR}/dependencies/glfw-3.3.8/include/"
        "${PROJECT_SOURCE_DIR}/dependencies/glm-0.9.9.8/include/"
)

add_executable(squares_test_cpp ${all_SRCS} "${PROJECT_SOURCE_DIR}/dependencies/glad/src/glad.c")

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
