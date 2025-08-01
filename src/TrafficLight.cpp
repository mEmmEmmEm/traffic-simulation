#include "TrafficLight.h"

TrafficLight::TrafficLight(int greenD, int redyellowD, int yellowD, int redD):
    greenDuration(greenD), redYellowDuration(redyellowD), yellowDuration(yellowD) ,redDuration(redD), timer(0), currentState(LightState::Red){}


void TrafficLight::update(int elapsedSeconds){
    timer += elapsedSeconds;

    switch (currentState){
        case LightState::Red:
            if(timer >= redDuration){
                currentState = LightState::RedYellow;
                timer = 0;
            }
            break;
        case LightState::RedYellow:
            if(timer >= redYellowDuration){
                currentState = LightState::Green;
                timer = 0;
            }       
            break;
        case LightState::Green:         
            if(timer >= greenDuration){
                currentState = LightState::Yellow;
                timer = 0;
            }
            break;
        case LightState::Yellow:
            if(timer >= yellowDuration){
                currentState = LightState::Red;
                timer = 0;
            }               
            break;    

    }   
}



LightState TrafficLight::getState() const{
    return currentState;
}

void TrafficLight::setState(LightState state) {
    this->currentState = state;
}
