cmake_minimum_required(VERSION 3.5)
project(map_creator)

add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES map_creator
  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

set(
  map_sources
  src/MapCreatorServer.cpp
  src/MapCreator.cpp
)

add_executable(
  map_creator
  ${map_sources}
)

target_link_libraries(
  map_creator
  ${catkin_LIBRARIES}
)
