cmake_minimum_required(VERSION 3.12)
project(SDL2test)

# Compilation flags definition
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra")

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  message("## Compile with ccache")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif(CCACHE_FOUND)

# Project executable
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_include_directories(
  ${PROJECT_NAME}
  PRIVATE 
          ${CMAKE_SOURCE_DIR}/src
)

# Libraries
find_package(SDL2 REQUIRED)
#find_package(SDL2_image REQUIRED)
include_directories(
  ${SDL2_INCLUDE_DIRS}
# ${SDL2_IMAGE_INCLUDE_DIRS}
 )

target_link_libraries(
  ${PROJECT_NAME}
   ${SDL2_LIBRARIES}
#   ${SDL2_IMAGE_LIBRARIES}
)
