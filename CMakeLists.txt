cmake_minimum_required(VERSION 3.16)
project(fexp
    VERSION ""
    DESCRIPTION "Console file explorer written in C++."
    HOMEPAGE_URL "https://github.com/niemiets/fexp"
    LANGUAGES CXX
)

set(CURSES_NEED_NCURSES TRUE)
set(CURSES_NEED_WIDE TRUE)

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "src/*.h" "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_20
)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES} panelw)

target_compile_options(${PROJECT_NAME}
    PUBLIC -DNCURSES_STATIC
)