cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(visualization)

find_package(OpenGL REQUIRED)
find_package(Qt4 COMPONENTS QtOpenGL QtCore QtGui REQUIRED)
include(${QT_USE_FILE})

find_package(Boost REQUIRED)


set(SOURCES 
   src/visualization/drawer_impl.cpp
   src/visualization/printer_impl.cpp
   src/visualization/main_window.cpp
   src/visualization/visualization.cpp
   src/visualization/draw_util.cpp
)

include_directories("headers/" "src/" ${Boost_INCLUDE_DIR})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall")

file(GLOB_RECURSE HEADERS "*.h")

add_custom_target(visualization_headers SOURCES ${HEADERS})

add_library(visualization
   ${SOURCES}
)

target_link_libraries(visualization ${QT_LIBRARIES} ${OPENGL_LIBRARIES})
