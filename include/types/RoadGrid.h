//
// Created by gawei on 11/05/2024.
//

#pragma once


#include <optional>
#include <unordered_map>
#include "RoadTile.h"

namespace types {

    struct ConnectivityCheckResult {
        std::set<DirectionEnum> possible;
        std::set<DirectionEnum> required;
    };

    // Not using template to allow for large grids to fit in heap
    class RoadGrid {
    private:
        std::optional<RoadTile> **tiles;

        enum class ConnectionType {
            NONE,
            CONNECTION,
            ACCESSIBLE
        };

        ConnectionType accessibiltyFromDirection(Coord position, DirectionEnum incomingDir);

    public:
        const int gridHeight, gridWidth;

        RoadGrid(int height, int width);

        ~RoadGrid();

        bool IsInBounds(Coord position) const;

        void SetTile(Coord position, RoadElement const *element);

        std::optional<RoadTile> &GetTile(Coord position);

        std::vector<OptionalRoadTileRef>
        GetAllNeighbors(Coord position);

        std::unordered_map<DirectionEnum, std::optional<OptionalRoadTileRef>> GetNeighborsMap(Coord position);

        ConnectivityCheckResult GetPossibleOutboundDirections(Coord position);

        RoadTile &GetTileNotNull(Coord position);

        friend std::ostream &operator<<(std::ostream &os, const RoadGrid &grid);

    };

}



