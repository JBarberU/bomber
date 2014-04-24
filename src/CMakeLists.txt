find_package(SFML REQUIRED COMPONENTS graphics window system)

set(SRC
main.cpp
Game.cpp
)

set(HEADERS
Game.h
stdafx.h
)

include_directories(${CMAKE_SOURCE_DIR})
include(${SFML_INCLUDE_DIR})

add_executable(bomber ${SRC})
target_link_libraries(bomber ${SFML_LIBRARIES})
