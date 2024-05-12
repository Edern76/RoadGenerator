cmake_minimum_required(VERSION 3.28)
project(RoadGenerator)

set(CMAKE_CXX_STANDARD 20)

add_executable(RoadGenerator main.cpp
        include/types/RoadElement.h
        include/types/Coord.h
        src/constants/Directions.h
        src/types/RoadGrid.cpp
        include/types/DirectionEnum.h
        include/types/RoadGrid.h
        include/types/RoadTile.h
        src/constants/RoadElements.h
        src/types/Coord.cpp
        src/exceptions/OutOfBoundsException.h
        src/exceptions/InvalidNonEmptyAssumption.h
        src/utils/EnumRange.h
        placeholderTests.cpp
        placeholderTests.h
        src/types/DirectionEnum.cpp
        src/utils/SetUtils.h)
