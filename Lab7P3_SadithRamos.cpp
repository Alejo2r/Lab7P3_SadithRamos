#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "RobotExplorador.h"
#include "RobotMecanico.h"
using namespace std;

void menu() {
    int opcion;
    vector<Robot*> robots;
    do {
        cout << "\n--- MENU FABRICA DE ROBOTS ---\n";
        cout << "1. Crear Robot\n2. Listar Robots\n3. Optimizar Robot\n4. Mostrar Especificaciones\n5. Diagnostico General\n0. Salir\nElige: ";
        cin >> opcion;

        if (opcion == 1) {
            int tipo;
            cout << "1. Explorador  2. Mecanico: ";
            cin >> tipo;
            string nombre; int b, p;
            cout << "Nombre: ";
            cin >> nombre;
            do
            {
                cout << "Bateria (1-10): ";
                cin >> b;
            } while (b < 1 || b > 10);

            do
            {
                cout << "Procesadores (1-10): ";
                cin >> p;
            } while (p < 1 || p > 10);


            if (tipo == 1) {
                int alcance; cout << "Alcance: ";
                cin >> alcance;
                RobotExplorador* re = new RobotExplorador(nombre, b, p, alcance);
                int n; cout << "Cantidad de sensores: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    string t; cout << "Tipo sensor " << i + 1 << ": ";
                    cin >> t;
                    re->agregarSensor(new Sensor(t));
                }
                robots.push_back(re);
            }
            else {
                int potencia;

                do
                {
                    cout << "Potencia herramientas (0-100): ";
                    cin >> potencia;
                } while (potencia < 0 || potencia > 100);
                RobotMecanico* rm = new RobotMecanico(nombre, b, p, potencia);
                int n;
                cout << "Cantidad de herramientas: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    string h; cout << "Herramienta " << i + 1 << ": ";
                    cin >> h;
                    rm->agregarHerramienta(h);
                }
                robots.push_back(rm);
            }
        }
        else if (opcion == 2) {
            for (int i = 0; i < robots.size(); i++) {
               robots[i]->mostrarEspecificaciones();
            }
        }
        else if (opcion == 3) {
            for (int i = 0; i < robots.size(); i++) {
                robots[i]->mostrarEspecificaciones();
            }
            int idx; cout << "Indice robot a optimizar (0 a " << robots.size() - 1 << "): "; 
            cin >> idx;
            if (idx >= 0 && idx < robots.size()) {
                robots[idx]->optimizar();
                robots[idx]->mostrarEspecificaciones();
            }
        }
        else if (opcion == 4) {
            int idx; cout << "Indice robot (0 a " << robots.size() - 1 << "): "; 
            cin >> idx;
            if (idx >= 0 && idx < robots.size()) robots[idx]->mostrarEspecificaciones();
        }
        else if (opcion == 5) {
            for (auto* r : robots) {
                if (RobotExplorador* re = dynamic_cast<RobotExplorador*>(r)) {
                    if (re->necesitaMantenimiento()) 
                        cout << "[DESCARGADO] "<< re->getNombre()<< " tiene bateria baja\n";
                    else
                    {
                        cout << "[OK] " << re->getNombre() << " no necesita mantenimiento\n";
                    }
                }
                if (RobotMecanico* rm = dynamic_cast<RobotMecanico*>(r)) {
                    if (rm->sobrecargado()) 
                        cout<<"[ERROR]" << rm->getNombre() << " esta sobrecargado\n";
                    else
                    {
                        cout << "[OK]" << rm->getNombre() << " no esta sobrecargado\n";
                    }
                }
            }
        }
    } while (opcion != 0);
    // liberar memoria
    for (auto* r : robots) delete r;
}


int main() {
    srand(time(0));
    menu();
}

