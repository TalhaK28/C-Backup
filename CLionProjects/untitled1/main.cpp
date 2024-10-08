#include "Server.h"
#include "Sensor.h"
#include "Scheduler.h"

int main() {
    Server server;

    // Création de capteurs
    TemperatureSensor tempSensor(1, &server);
    HumiditySensor humiditySensor(2, &server);
    SoundSensor soundSensor(3, &server);
    LightSensor lightSensor(4, &server);

    // Scheduler
    Scheduler scheduler;
    scheduler.addSensor(&tempSensor);
    scheduler.addSensor(&humiditySensor);
    scheduler.addSensor(&soundSensor);
    scheduler.addSensor(&lightSensor);

    // Lancer la simulation pendant 10 cycles
    scheduler.simulation(10);

    return 0;
}
