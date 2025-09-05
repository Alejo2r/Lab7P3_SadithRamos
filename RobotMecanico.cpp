#include "RobotMecanico.h"
#include <iostream>
using namespace std;

RobotMecanico::RobotMecanico(string nombre, int bateria, int procesadores, int potencia)
    : Robot(nombre, bateria, procesadores) {
    this->potenciaHerramientas = potencia;
}

RobotMecanico::~RobotMecanico() {}

void RobotMecanico::agregarHerramienta(string h) {
    if (herramientas.size() < 5) herramientas.push_back(h);
}

void RobotMecanico::optimizar() {
    potenciaHerramientas += (potenciaHerramientas * 10) / 100; // +10%
    if (herramientas.size() < 5) herramientas.push_back("Herramienta " + to_string(herramientas.size() + 1));

    // 10% fallo: perder herramienta
    if ((rand() % 10) == 0 && !herramientas.empty()) {
        cout << nombre << " sufrio un fallo y perdio una herramienta." << endl;
        herramientas.pop_back();
    }
}

void RobotMecanico::mostrarEspecificaciones() {
    cout << "\n[Robot Mecanico] " << nombre << " | Capacidad: " << capacidadTotal << " | Herramientas: " << potenciaHerramientas;

    if (!herramientas.empty()) {
        vector<int> longitudes;
        for (auto& h : herramientas) longitudes.push_back((int)h.size());
        cout << " | Prom. longitud nombres herramientas: " << calcularPromedio(longitudes) << endl;
    }
}

bool RobotMecanico::sobrecargado() {
    if (potenciaHerramientas > 90 && herramientas.size() > 3)
        return true;
    else
    {
        return false;
    }
}
