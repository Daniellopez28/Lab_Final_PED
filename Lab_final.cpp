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
};



void mostrarEstudiante(Estudiante* e) {
    cout << "Carnet: " << e->carnet
         << " Nombre: " << e->nombre
         << " Nota: " << e->nota << endl;
};

void inorden(Estudiante* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierdo);
        mostrarEstudiante(raiz);
        inorden(raiz->derecha);
    }

};

Estudiante* buscar(Estudiante* raiz, int carnet) {
    if (raiz == NULL || raiz->carnet == carnet)
        return raiz;
    if (carnet < raiz->carnet)
        return buscar(raiz->izquierdo, carnet);
    return buscar(raiz->derecha, carnet);
}

void mostrarAprobados(Estudiante* raiz) {
    if (raiz != NULL) {
        mostrarAprobados(raiz->izquierdo);
        if (raiz->nota >= 6)
            mostrarEstudiante(raiz);
        mostrarAprobados(raiz->derecha);
    }
}

};

