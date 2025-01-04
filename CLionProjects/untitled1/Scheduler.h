#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "ISensor.h" // Interface ISensor

class Scheduler {
public:
    Scheduler();
    ~Scheduler();

    void addSensor(ISensor* sensor);
    void simulation(int duration);

private:
    std::vector<ISensor*> sensors;
};

#endif
