#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Sensor.h"

class Scheduler {
public:
    Scheduler();
    ~Scheduler();

    void addSensor(Sensor* sensor);
    void simulation(int duration);

private:
    std::vector<Sensor*> sensors;
};

#endif
