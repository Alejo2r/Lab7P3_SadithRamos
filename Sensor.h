#pragma once
#include <string>
#include <cstdlib>
using namespace std;

class Sensor {
private:
    string tipo;
    int sensibilidad;

public:
    Sensor(string tipo);
    ~Sensor();

    string getTipo() const;
    int getSensibilidad() const;
    void setSensibilidad(int s);
};
