#pragma once
#include "Robot.h"
#include "FuncionesTemplate.h"
#include <vector>
#include <string>

class RobotMecanico : public Robot {
private:
    int potenciaHerramientas;
    vector<string> herramientas;

public:
    RobotMecanico(string nombre, int bateria, int procesadores, int potencia);
    ~RobotMecanico();

    void agregarHerramienta(string h);
    void optimizar() override;
    void mostrarEspecificaciones() override;

    bool sobrecargado();
};
