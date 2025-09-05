#include "RobotExplorador.h"
#include <iostream>
using namespace std;

RobotExplorador::RobotExplorador(string nombre, int bateria, int procesadores, int alcance)
    : Robot(nombre, bateria, procesadores) {
    this->alcanceTerreno = alcance;
}

RobotExplorador::~RobotExplorador() {
    for (auto* s : sensores) delete s;
}

void RobotExplorador::agregarSensor(Sensor* s) {
    sensores.push_back(s);
}

void RobotExplorador::optimizar() {
    alcanceTerreno += rand() % 31; // 0–30 km
    for (auto* s : sensores) {
        int mejora = (rand() % 16) + 5; // 5–20
        int nueva = s->getSensibilidad() + mejora;
        if (nueva > 100) nueva = 100;
        s->setSensibilidad(nueva);
    }

    // 10% probabilidad de fallo
    if ((rand() % 10) == 0 && sensores.size() > 1) {
        cout << nombre << " sufrió un fallo y perdió un sensor." << endl;
        delete sensores.back();
        sensores.pop_back();
    }
}

void RobotExplorador::mostrarEspecificaciones() { 
    cout << "\n[Robot Explorador] " << nombre << " | Capacidad: " << capacidadTotal << " | Alcance: " << alcanceTerreno << " km";

    if (!sensores.empty()) {
        vector<int> valores;
        for (auto* s : sensores) valores.push_back(s->getSensibilidad());

        cout << " | Promedio sensibilidad: " << calcularPromedio(valores);

        // Sensor más común sin map
        string comun = sensores[0]->getTipo();
        int maxFreq = 0;
        for (int i = 0; i < sensores.size(); i++) {
            int contador = 0;
            for (int j = 0; j < sensores.size(); j++) {
                if (sensores[i]->getTipo() == sensores[j]->getTipo()) {
                    contador++;
                }
            }
            if (contador > maxFreq) {
                maxFreq = contador;
                comun = sensores[i]->getTipo();
            }
        }
        cout << " | Sensor mas comun: " << comun << endl;
    }
}

bool RobotExplorador::necesitaMantenimiento() {
    int bajos = 0;
    for (auto* s : sensores) if (s->getSensibilidad() < 30) bajos++;
    return bajos >= 2;
}
