cmake_minimum_required(VERSION 3.18)

project(burden10e LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

if(MSVC)
  # /wd6326 "Potential comparison of a constant with another constant."
  # /wd4200 "nonstandard extension used: zero-sized array in struct/union"
  add_compile_options(/guard:cf /analyze /permissive- /W4 /WX /wd6326 /wd4200)

else()
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_subdirectory(chapter02)
add_subdirectory(chapter06)
