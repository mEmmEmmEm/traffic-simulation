#pragma once
#include "TrafficLight.h"

enum class Direction{
    North,
    South,
    East,
    West
};

class Car{
public: 
    Car(Direction dir, int startPos = 10, int speed = 1);
    void update(const TrafficLight& TrafficLight);
    int getPosition() const;
    Direction getDirection() const;
    char getSymbol() const;
private:    
    Direction direction;
    int position;
    int speed;
    char symbol;
    bool isMoving;
};