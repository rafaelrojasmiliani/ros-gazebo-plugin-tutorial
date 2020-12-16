cmake_minimum_required(VERSION 3.0.2)
project(actor_package)
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs tf)
find_package(GAZEBO REQUIRED)
catkin_package(
  # INCLUDE_DIRS include LIBRARIES actor_package CATKIN_DEPENDS roscpp std_msgs
  # tf DEPENDS GAZEBO
)
include_directories(include ${catkin_INCLUDE_DIRS} ${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")
add_library(actor_plugin SHARED src/actor_plugin.cpp)
target_link_libraries(actor_plugin ${GAZEBO_LIBRARIES} ${catkin_LIBRARIES})
set_target_properties(actor_plugin PROPERTIES LIBRARY_OUTPUT_DIRECTORY
                                              ${CMAKE_SOURCE_DIR}/lib)
