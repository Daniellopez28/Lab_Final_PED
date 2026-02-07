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

Estudiante* crearEstudiante(int carnet, const char* nombre, float nota) {
    Estudiante* nuevo = new Estudiante;
    nuevo->carnet = carnet;
    strcpy(nuevo->nombre, nombre);
    nuevo->nota = nota;
    nuevo->izquierdo = NULL;
    nuevo->derecha = NULL;
    return nuevo;
}

Estudiante* insertar(Estudiante* raiz, int carnet, const char* nombre, float nota) {
    if (raiz == NULL)
        return crearEstudiante(carnet, nombre, nota);

    if (carnet < raiz->carnet)
        raiz->izquierdo = insertar(raiz->izquierdo, carnet, nombre, nota);
    else if (carnet > raiz->carnet)
        raiz->derecha = insertar(raiz->derecha, carnet, nombre, nota);

    return raiz;
}

