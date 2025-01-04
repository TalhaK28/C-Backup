#include "Sensor.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>

// Codes de couleur ANSI
const std::string COLOR_RESET = "\033[0m";
const std::string COLOR_BLUE = "\033[34m";      // Température
const std::string COLOR_GREEN = "\033[32m";     // Humidité
const std::string COLOR_RED = "\033[31m";       // Son
const std::string COLOR_YELLOW = "\033[33m";    // Lumière

// Température
TemperatureSensor::TemperatureSensor(int id, Server* server)
        : Sensor(id, "Temperature", server) {}

void TemperatureSensor::execute() {
    // Génère une température réaliste entre -10.0 et 40.0
    value = static_cast<float>(rand() % 500 - 100) / 10.0f;
}

std::string TemperatureSensor::formatValue() const {
    std::ostringstream stream;
    stream << COLOR_BLUE << std::fixed << std::setprecision(1) << value  << "C" << COLOR_RESET;
    return stream.str();
}

// Humidité
HumiditySensor::HumiditySensor(int id, Server* server)
        : Sensor(id, "Humidity", server) {}

void HumiditySensor::execute() {
    // Génère une humidité réaliste entre 0 et 100 %
    value = static_cast<float>(rand() % 101);
}

std::string HumiditySensor::formatValue() const {
    return COLOR_GREEN + std::to_string(static_cast<int>(value)) + " %" + COLOR_RESET;
}

// Son
SoundSensor::SoundSensor(int id, Server* server)
        : Sensor(id, "Sound", server) {}

void SoundSensor::execute() {
    // Génère un niveau sonore entre 30 et 130 dB
    value = 30 + rand() % 101;
}

std::string SoundSensor::formatValue() const {
    return COLOR_RED + std::to_string(value) + " dB" + COLOR_RESET;
}

// Lumière
LightSensor::LightSensor(int id, Server* server)
        : Sensor(id, "Light", server) {}

void LightSensor::execute() {
    // Génère un booléen indiquant s'il y a de la lumière ou non (1 pour "lumière", 0 pour "obscurité")
    value = rand() % 2;
}

std::string LightSensor::formatValue() const {
    if (value) {
        return COLOR_YELLOW + "Lumi\x8Are pr\x82sente" + COLOR_RESET;
    } else {
        return COLOR_BLUE + "Obscurit\x82" + COLOR_RESET;
    }
}
