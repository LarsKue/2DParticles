cmake_minimum_required(VERSION 3.13)
project(2DParticles VERSION 0.1.0 DESCRIPTION "A 2-dimensional Particle Renderer.")

set(CMAKE_CXX_STANDARD 17)

# source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_compile_options(-m64)
add_link_options(-static-libgcc -static-libstdc++)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g -Wall -Wextra -Wshadow -W -pedantic -Weffc++)
else()
    add_compile_options(-O2)
endif()

add_executable(2DParticles ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "2DParticles")


# add SFML to the project
set(SFML_ROOT ${PROJECT_SOURCE_DIR}/../SFML-2.5.1)
set(SFML_STATIC_LIBARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)

if (SFML_FOUND)
    # the SYSTEM specifies that warnings should not be generated for these headers
    include_directories(SYSTEM ${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
else()
    message(FATAL_ERROR "SFML Could not be found.")
endif()

# copy the dlls from SFML to the exe dir
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${SFML_ROOT}/bin"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)