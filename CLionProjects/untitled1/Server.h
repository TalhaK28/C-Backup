#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <fstream>
#include <string>

class Server {
public:
    // Coplien form (constructeur par défaut, destructeur, constructeur par copie, opérateur d'affectation)
    Server();
    ~Server();
    Server(const Server& other);
    Server& operator=(const Server& other);

    // Méthodes de gestion des données
    void consoleWrite(const std::string& sensorData);
    void fileWrite(const std::string& sensorData, const std::string& sensorType);

private:
    // Pour simplification, des noms de fichiers prédéfinis pour chaque capteur
    std::ofstream temperatureLogFile;
    std::ofstream humidityLogFile;
    std::ofstream soundLogFile;
    std::ofstream lightLogFile;

    void openLogFiles();  // Ouvrir les fichiers de log
    void closeLogFiles(); // Fermer les fichiers de log
};

#endif
