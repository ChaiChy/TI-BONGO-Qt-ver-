#include "Position.h"

int Position::getX()
{
    return x;
}
void Position::setX(int x)
{
    this->x = x;
}
int Position::getY()
{
    return y;
}
void Position::setY(int y)
{
    this->y = y;
}

std::string Position::to_string()
{
    std::string x = std::to_string(getX());
    std::string y = std::to_string(getY());
    return ("Position: x = " + x + ", " + "y = " + y);
}

Position::Position()
    :x(0), y(0) {};

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}
//adding the coordinates x and y

Position Position::operator+ (const Position& rhs) const
{
    return Position(this->x + rhs.x, this->y + rhs.y);
}
//compare x and y, return true if same
bool Position::operator==(const  Position& rhs) const
{
    return (this->x == rhs.x && this->y == rhs.y);
}
