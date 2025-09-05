#pragma once
#include <string>
#include <iostream>
using namespace std;

class Robot {
protected:
    string nombre;
    int bateria;
    int procesadores;
    int capacidadTotal;

public:
    Robot(string nombre, int bateria, int procesadores);
    virtual ~Robot();

    string getNombre() const;
    int getBateria() const;
    int getProcesadores() const;
    int getCapacidadTotal() const;

    virtual void optimizar() = 0;
    virtual void mostrarEspecificaciones() = 0;
};
