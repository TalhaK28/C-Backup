#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include "ISensor.h"
#include "Server.h"

// Classe template Sensor qui hérite de ISensor
template <typename T>
class Sensor : public ISensor {
public:
    Sensor(int id, const std::string& type, Server* server)
            : id(id), type(type), server(server), value() {}
    virtual ~Sensor() = default;

    void update() override;
    virtual void execute() = 0;
    virtual std::string formatValue() const = 0;

    std::string getType() const override { return type; }

protected:
    int id;
    std::string type;
    T value;
    Server* server;

    void sendDataToServer();
};

template <typename T>
void Sensor<T>::update() {
    execute();
    sendDataToServer();
}

template <typename T>
void Sensor<T>::sendDataToServer() {
    std::string data = "Sensor ID: " + std::to_string(id) + " | Type: " + type + " | Value: " + formatValue();
    server->consoleWrite(data);
    server->fileWrite(data, type);
}

// Déclarations des capteurs spécifiques
class TemperatureSensor : public Sensor<float> {
public:
    TemperatureSensor(int id, Server* server);
    void execute() override;
    std::string formatValue() const override;
};

class HumiditySensor : public Sensor<float> {
public:
    HumiditySensor(int id, Server* server);
    void execute() override;
    std::string formatValue() const override;
};

class SoundSensor : public Sensor<int> {
public:
    SoundSensor(int id, Server* server);
    void execute() override;
    std::string formatValue() const override;
};

class LightSensor : public Sensor<bool> {
public:
    LightSensor(int id, Server* server);
    void execute() override;
    std::string formatValue() const override;
};

#endif
