cmake_minimum_required(VERSION 3.12.3)
project(fdf)

add_custom_target(fdf
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
        .:libft:/usr/local/include
        #        libft
        includes)
link_directories(libft
        includes)
find_library(OPEN_GL OpenGl)
find_library(APP_KIT AppKit)
link_libraries(mlx)

set(sources
        sources/brezeham.c
        sources/draw_dots.c
        sources/events.c
        sources/fdf.c
        sources/main.c
        sources/parser.c
        sources/s_lines.c
        sources/s_point.c)

add_executable(f
        #        sourses/debug.c
        ${sources}
        )

add_compile_options(-Wall -Wextra -Werror)

#add_subdirectory(libft)

target_link_libraries(f ft mlx ${OPEN_GL} ${APP_KIT})