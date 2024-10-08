#include "Sensor.h"
#include <iostream>
#include <cstdlib> // Pour la génération aléatoire des valeurs

Sensor::Sensor(int id, const std::string& type, Server* server)
        : id(id), type(type), server(server), value(0.0f) {}

void Sensor::update() {
    execute();
    sendDataToServer();
}

void Sensor::sendDataToServer() {
    std::string data = "Sensor ID: " + std::to_string(id) + " | Type: " + type + " | Value: " + std::to_string(value);
    server->consoleWrite(data);
    server->fileWrite(data, type);
}

// Température
TemperatureSensor::TemperatureSensor(int id, Server* server)
        : Sensor(id, "Temperature", server) {}

void TemperatureSensor::execute() {
    value = static_cast<float>(rand() % 100); // Génère une valeur entre 0 et 100
}

// Humidité
HumiditySensor::HumiditySensor(int id, Server* server)
        : Sensor(id, "Humidity", server) {}

void HumiditySensor::execute() {
    value = static_cast<float>(rand() % 100); // Génère une valeur entre 0 et 100
}

// Son
SoundSensor::SoundSensor(int id, Server* server)
        : Sensor(id, "Sound", server) {}

void SoundSensor::execute() {
    value = rand() % 200; // Génère une valeur entre 0 et 200
}

// Lumière
LightSensor::LightSensor(int id, Server* server)
        : Sensor(id, "Light", server) {}

void LightSensor::execute() {
    value = rand() % 2; // Génère une valeur booléenne (0 ou 1)
}
