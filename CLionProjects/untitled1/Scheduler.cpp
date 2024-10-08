#include "Scheduler.h"
#include <chrono>
#include <thread>

Scheduler::Scheduler() {}

Scheduler::~Scheduler() {
    for (Sensor* sensor : sensors) {
        delete sensor;
    }
}

void Scheduler::addSensor(Sensor* sensor) {
    sensors.push_back(sensor);
}

void Scheduler::simulation(int duration) {
    for (int i = 0; i < duration; ++i) {
        for (Sensor* sensor : sensors) {
            sensor->update();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause d'une seconde
    }
}
