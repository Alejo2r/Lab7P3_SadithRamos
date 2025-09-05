#pragma once
#include "Robot.h"
#include "Sensor.h"
#include "FuncionesTemplate.h"
#include <vector>

class RobotExplorador : public Robot {
private:
    int alcanceTerreno;
    vector<Sensor*> sensores;

public:
    RobotExplorador(string nombre, int bateria, int procesadores, int alcance);
    ~RobotExplorador();

    void agregarSensor(Sensor* s);
    void optimizar() override;
    void mostrarEspecificaciones() override;

    bool necesitaMantenimiento();
};
