#include "Robot.h"

Robot::Robot(string nombre, int bateria, int procesadores) {
    this->nombre = nombre;
    this->bateria = bateria;
    this->procesadores = procesadores;
    this->capacidadTotal = bateria * procesadores;
}

Robot::~Robot() {}

string Robot::getNombre() const { 
    return nombre; 
}

int Robot::getBateria() const { 
    return bateria;
}

int Robot::getProcesadores() const { 
    return procesadores; 
}

int Robot::getCapacidadTotal() const { 
    return capacidadTotal; 
}
