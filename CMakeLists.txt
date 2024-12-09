cmake_minimum_required(VERSION 3.16)
project("fexp"
    VERSION ""
    DESCRIPTION "Console file explorer written in C++."
    HOMEPAGE_URL "https://github.com/niemiets/fexp"
    LANGUAGES CXX
)

set(CURSES_NEED_NCURSES TRUE)
set(CURSES_NEED_WIDE TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

if (CURSES_HAVE_NCURSES_NCURSES_H)

    add_executable(${PROJECT_NAME}
        src/main.cpp
        src/App.cpp
        src/App.h
    )

    target_compile_features(${PROJECT_NAME}
        PUBLIC cxx_std_20
    )

    # target_sources(${PROJECT_NAME}
    #     PUBLIC
    #         FILE_SET headers
    #         TYPE HEADERS
    #         BASE_DIRS src
    #         FILES
    #             src/App.h
    # )

    target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

    target_compile_options(${PROJECT_NAME}
        PUBLIC -DNCURSES_STATIC
    )

endif()

# target_link_libraries(fexp PRIVATE ${CURSES_LIBRARIES})

# include(GNUInstallDirs)
# install(TARGETS fexp DESTINATION ${CMAKE_INSTALL_BINDIR})