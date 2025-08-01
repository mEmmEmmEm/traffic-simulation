#pragma once
#include "Car.h"
#include "TrafficLight.h"
#include <vector>

class Simulation {
public:
    Simulation();

    void run(int steps, int stepDurationSeconds = 1);

private:
    std::vector<Car> cars;
    TrafficLight ewLight;
    TrafficLight nsLight;
    void update(int elapsedSeconds);
    void render() const;
    void syncEWWithNS();

    const TrafficLight& getTrafficaLightFor(const Car& car) const;

};