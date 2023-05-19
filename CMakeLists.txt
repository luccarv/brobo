cmake_minimum_required(VERSION 3.22)

include(pico_sdk_import.cmake)

project(brobo C CXX ASM)
set(CMAKE_C_STANDARD 11)

add_executable(brobo)
target_sources(brobo PRIVATE src/main.c)

set(TEST "false")

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    
    set(TEST "true")

    pico_sdk_init()

endif()

add_subdirectory(test)

add_library(libsg90 src/sg90.c)
target_include_directories(libsg90 PUBLIC include)

add_library(arm_movement src/arm_movement.c)
target_include_directories(arm_movement PUBLIC include)

target_link_libraries(libsg90 PUBLIC pico_stdlib hardware_pwm)
target_link_libraries(arm_movement PUBLIC libsg90)
target_link_libraries(brobo PUBLIC arm_movement)

pico_add_extra_outputs(brobo)