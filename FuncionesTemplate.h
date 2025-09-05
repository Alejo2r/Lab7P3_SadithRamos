#pragma once
#include <vector>
using namespace std;

template <typename T>
double calcularPromedio(const vector<T>& datos) {
    if (datos.empty()) return 0;
    double suma = 0;
    for (auto& d : datos) suma += d;
    return suma / datos.size();
}

