#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <iostream>
#include "Celda.h"

using namespace std;

// Clase Tablero
// Esta clase representa el tablero del juego, que consiste en una matriz de celdas.
// Proporciona m�todos para colocar minas, mostrar el estado del tablero y descubrir celdas.
class Tablero {
private:
    vector<vector<Celda>> celdas; // Matriz de celdas que componen el tablero
    int filas;                     // N�mero de filas del tablero
    int columnas;                  // N�mero de columnas del tablero

public:
    // Constructor de la clase Tablero
    // Inicializa un tablero con el n�mero de filas y columnas especificadas.
    // Par�metros:
    // - f: n�mero de filas del tablero
    // - c: n�mero de columnas del tablero
    Tablero(int f, int c);

    // M�todo para colocar minas en el tablero
    // Coloca un n�mero espec�fico de minas en posiciones aleatorias del tablero.
    // Par�metro:
    // - minas: n�mero de minas a colocar en el tablero
    void colocarMinas(int minas);

    // M�todo para mostrar el estado del tablero
    // Muestra el tablero en la consola, revelando celdas seg�n el modo de juego.
    // Par�metro:
    // - administrador: booleano que indica si se debe mostrar el tablero completo (true) o solo las celdas descubiertas (false)
    void mostrar(bool administrador);

    // M�todo para descubrir una celda en el tablero
    // Intenta descubrir la celda en la posici�n especificada.
    // Par�metros:
    // - fila: n�mero de fila de la celda a descubrir (1-indexado)
    // - col: n�mero de columna de la celda a descubrir (1-indexado)
    // Retorna:
    // - true si se descubre una mina, false si la celda no tiene mina
    bool descubrir(int fila, int col);
};

#endif // TABLERO_H

