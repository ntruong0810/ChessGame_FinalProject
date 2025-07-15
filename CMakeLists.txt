cmake_minimum_required(VERSION 3.28)
project(finalProjectCS3A LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(finalProjectCS3A
        src/main.cpp
        src/ImageEnum.cpp
        src/ImageEnum.h
        src/TextureManager.cpp
        src/TextureManager.h
        src/PieceManager.cpp
        src/PieceManager.h
        src/DragManager.cpp
        src/DragManager.h
        src/PieceUtil.cpp
        src/PieceUtil.h
        src/MoveLogic.cpp
        src/MoveLogic.h
        src/PawnLogic.cpp
        src/PawnLogic.h
        src/RookLogic.cpp
        src/RookLogic.h
        src/KnightLogic.cpp
        src/KnightLogic.h
        src/BishopLogic.cpp
        src/BishopLogic.h
        src/QueenLogic.cpp
        src/QueenLogic.h
        src/KingLogic.cpp
        src/KingLogic.h
        src/MoveLogicFactory.cpp
        src/MoveLogicFactory.h
        src/CastleLogic.cpp
        src/CastleLogic.h
        src/GameState.cpp
        src/GameState.h
)

target_compile_features(finalProjectCS3A PRIVATE cxx_std_17)
target_link_libraries(finalProjectCS3A PRIVATE SFML::Graphics SFML::Window SFML::System)