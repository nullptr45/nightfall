cmake_minimum_required(VERSION 3.16)
project(nightfall)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL3 REQUIRED)
find_package(Vulkan REQUIRED COMPONENTS volk shaderc_combined)

file(GLOB_RECURSE NIGHTFALL_SRCS CONFIGURE_DEPENDS src/*.cpp)
add_executable(nightfall ${NIGHTFALL_SRCS})

target_include_directories(nightfall PUBLIC src)
target_link_libraries(nightfall PRIVATE SDL3::SDL3 Vulkan::Vulkan Vulkan::volk Vulkan::shaderc_combined)
