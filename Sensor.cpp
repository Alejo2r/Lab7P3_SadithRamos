#include "Sensor.h"

Sensor::Sensor(string tipo) {
    this->tipo = tipo;
    this->sensibilidad = rand() % 101; // 0-100
}

Sensor::~Sensor() {}

string Sensor::getTipo() const { 
    return tipo;
}

int Sensor::getSensibilidad() const {
    return sensibilidad; 
}

void Sensor::setSensibilidad(int s) { 
    this->sensibilidad = s; 
}
