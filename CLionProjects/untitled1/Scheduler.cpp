#include "Scheduler.h"
#include <chrono>
#include <thread>

Scheduler::Scheduler() {}

Scheduler::~Scheduler() {
    for (ISensor* sensor : sensors) {
        delete sensor;
    }
}

void Scheduler::addSensor(ISensor* sensor) {
    sensors.push_back(sensor);
}

void Scheduler::simulation(int duration) {
    for (int i = 0; i < duration; ++i) {
        for (ISensor* sensor : sensors) {
            sensor->update();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause d'une seconde
    }
}
