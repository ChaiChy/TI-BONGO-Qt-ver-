#ifndef POSITION
#define POSITION

#include <string>
#include <iostream>
class Position
{
protected:
    int x = 0;
    int y = 0;
public:
    Position operator+ (const Position& rhs) const;
    bool operator==(const Position& rhs) const;
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    std::string to_string();

    Position();
    Position(int x, int y);
    ~Position() {};
};
#endif
