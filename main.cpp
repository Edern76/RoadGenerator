#include <iostream>
#include "include/types/RoadGrid.h"

using types::RoadGrid;

int main() {
    RoadGrid grid = RoadGrid(10, 10);
    std::cout << grid << std::endl;
    return 0;
}
