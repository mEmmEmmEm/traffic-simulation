#include "Simulation.h"
#include <iostream>
#include <thread>
#include <chrono>



Simulation::Simulation():
    ewLight(5, 2, 5, 2),
    nsLight(5, 2, 5, 2){
        cars.emplace_back(Direction::East, 10);
        cars.emplace_back(Direction::North, 5);
        cars.emplace_back(Direction::South, 6);
        cars.emplace_back(Direction::West, 8);
}

void Simulation::run(int steps, int stepDurationSeconds) {
    for (int i = 0; i < steps; ++i) {
        update(stepDurationSeconds);
        render();
        std::this_thread::sleep_for(std::chrono::seconds(stepDurationSeconds));
    }
}

void Simulation::update(int elapsedSeconds) {
    nsLight.update(elapsedSeconds);
    syncEWWithNS();

    for (auto& car : cars) {
        const TrafficLight& light = getTrafficaLightFor(car);
        car.update(light);
    }
}

void Simulation::syncEWWithNS() {
    switch (nsLight.getState()) {
        case LightState::Green:
            ewLight.setState(LightState::Red);
            break;
        case LightState::Yellow:
            ewLight.setState(LightState::RedYellow);  
            break;
        case LightState::Red:
            ewLight.setState(LightState::Green);
            break;
        case LightState::RedYellow:
            ewLight.setState(LightState::Yellow);  
            break;
    }
}


const TrafficLight& Simulation::getTrafficaLightFor(const Car& car) const {
    Direction dir = car.getDirection();
    if (dir == Direction::North || dir == Direction::South)
        return nsLight;
    else
        return ewLight;
}

void Simulation::render() const {
    auto lightSymbol = [](LightState state) -> std::string {
        switch(state) {
            case LightState::Red: return "(R)";        // Red
            case LightState::RedYellow: return "(RY)"; // Red-Yellow
            case LightState::Green: return "(G)";      // Green
            case LightState::Yellow: return "(Y)";     // Yellow
        }
        return "?";
    };

    std::cout << "\n========== State ==========\n";
    std::cout << "Traffic Light [NS]: " << lightSymbol(nsLight.getState()) << "   "
              << "Traffic Light [EW]: " << lightSymbol(ewLight.getState()) << "\n";


    for (Direction dir : {Direction::North, Direction::South, Direction::West, Direction::East}) {
        std::cout << (dir == Direction::North ? "North : " :
                      dir == Direction::South ? "South : " :
                      dir == Direction::West  ? "West  : " :
                                                "East  : ");

        for (const auto& car : cars) {
            if (car.getDirection() == dir) {
                for (int i = 0; i < car.getPosition(); ++i)
                    std::cout << " ";
                std::cout << car.getSymbol();
            }
        }
        std::cout << "\n";
    }
}
