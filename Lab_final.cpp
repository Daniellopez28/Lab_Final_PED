#include <iostream>
#include <cstring>
using namespace std;

struct Estudiante {
    int carnet;
    char nombre[50];
    float nota;
    Estudiante* izquierdo;
    Estudiante* derecha;
}; 


