#include "Server.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

// Constructeur par défaut
Server::Server() {
    openLogFiles();
}

// Destructeur
Server::~Server() {
    closeLogFiles();
}

// Constructeur de copie
Server::Server(const Server& other) {
    // Possible deep copy si nécessaire (pas besoin ici car on ne copie pas de fichiers en soi)
}

// Opérateur d'affectation
Server& Server::operator=(const Server& other) {
    if (this != &other) {
        // Logique de copie si nécessaire
    }
    return *this;
}

// Fonction pour écrire dans la console
void Server::consoleWrite(const std::string& sensorData) {
    std::cout << sensorData << std::endl;
}



std::string removeAnsiEscapes(const std::string& input) {
    // Expression régulière qui correspond aux séquences d'échappement ANSI
    std::regex escapeSequence(R"(\x1b\[[0-9;]*[mK])");

    // Remplacer toutes les séquences d'échappement par une chaîne vide
    return std::regex_replace(input, escapeSequence, "");
}

// Fonction pour écrire dans un fichier de log
void Server::fileWrite(const std::string& sensorData, const std::string& sensorType) {
    if (sensorType == "Temperature") {
        temperatureLogFile << removeAnsiEscapes(sensorData) << std::endl;
    } else if (sensorType == "Humidity") {
        humidityLogFile << removeAnsiEscapes(sensorData) << std::endl;
    } else if (sensorType == "Sound") {
        soundLogFile << removeAnsiEscapes(sensorData) << std::endl;
    } else if (sensorType == "Light") {
        lightLogFile << removeAnsiEscapes(sensorData) << std::endl;
    }
}

// Ouvrir les fichiers de log
void Server::openLogFiles() {
    temperatureLogFile.open("temperature_log.csv", std::ios::app);
    humidityLogFile.open("humidity_log.csv", std::ios::app);
    soundLogFile.open("sound_log.csv", std::ios::app);
    lightLogFile.open("light_log.csv", std::ios::app);
}

// Fermer les fichiers de log
void Server::closeLogFiles() {
    if (temperatureLogFile.is_open()) temperatureLogFile.close();
    if (humidityLogFile.is_open()) humidityLogFile.close();
    if (soundLogFile.is_open()) soundLogFile.close();
    if (lightLogFile.is_open()) lightLogFile.close();
}
