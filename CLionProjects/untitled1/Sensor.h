#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include "Server.h"

class Sensor {
public:
    Sensor(int id, const std::string& type, Server* server);
    virtual ~Sensor() = default;

    void update();
    virtual void execute() = 0;

protected:
    int id;
    std::string type;
    float value;
    Server* server;

    void sendDataToServer();
};

class TemperatureSensor : public Sensor {
public:
    TemperatureSensor(int id, Server* server);
    void execute() override;
};

class HumiditySensor : public Sensor {
public:
    HumiditySensor(int id, Server* server);
    void execute() override;
};

class SoundSensor : public Sensor {
public:
    SoundSensor(int id, Server* server);
    void execute() override;
};

class LightSensor : public Sensor {
public:
    LightSensor(int id, Server* server);
    void execute() override;
};

#endif
