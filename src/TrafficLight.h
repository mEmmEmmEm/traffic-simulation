#pragma once

enum class LightState{
    Red,
    RedYellow,
    Yellow,
    Green
};

class TrafficLight{
public:
    TrafficLight(int greemDuration,  int redYellowDuration, int yellowDuration, int redDuration);

    void update(int elapsedTime);

    LightState getState() const;

    void setState(LightState state);
private:
    int greenDuration;
    int redYellowDuration;
    int yellowDuration;
    int redDuration;
    int timer;
    LightState currentState;
};