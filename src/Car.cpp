#include "Car.h"

Car::Car(Direction dir, int start, int speed):
    direction(dir), position(start), speed(speed), isMoving(false) {}

void Car::update(const TrafficLight& trafficLight) {
    LightState state = trafficLight.getState();
    bool greenForCar = false;
    switch(state){
        case LightState::RedYellow:
        case LightState::Green:
            greenForCar = true;
            break;
        default:
            greenForCar = false;
    }

    if(greenForCar && position > 0){
        position -= speed;
        if(position <= 0) {
            position = 0; 
        }
        isMoving = true;
    }
    else {
        isMoving = false;
    }   

}


int Car::getPosition() const {
    return position;
}

Direction Car::getDirection() const{
    return direction;
}

char Car::getSymbol() const {
    return '0'; 
}

