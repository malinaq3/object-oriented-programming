#pragma once

class Coordinates {
public:
    Coordinates();
    Coordinates(size_t positionX, size_t positionY);
    bool operator==(const Coordinates& coor) const;

private:
    size_t positionX_{0};
    size_t positionY_{0};
};
