cmake_minimum_required(VERSION 3.0.2)
project(first_laboratory_work)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    message_generation
    message_runtime
    std_msgs
)

add_service_files(
  FILES
  choose_path.srv
)

generate_messages(
    DEPENDENCIES
    std_msgs
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
#  sources
)

set(INCLUDE_FILES include/first_laboratory_work/hero.h include/first_laboratory_work/path.h include/first_laboratory_work/game.h)
set(SOURCE_FILES sources/hero.cpp sources/path.cpp sources/game.cpp)
add_executable(subscriber src/subscriber.cpp ${SOURCE_FILES} ${INCLUDE_FILES})

target_link_libraries(subscriber
        ${catkin_LIBRARIES}
)
