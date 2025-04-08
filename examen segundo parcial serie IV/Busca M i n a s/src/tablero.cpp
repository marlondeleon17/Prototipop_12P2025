#include "Tablero.h"
#include <cstdlib>
#include <ctime>

// Constructor de la clase Tablero
// Inicializa un tablero con el n�mero de filas y columnas especificadas.
// Par�metros:
// - f: n�mero de filas del tablero
// - c: n�mero de columnas del tablero
Tablero::Tablero(int f, int c) : filas(f), columnas(c) {
    // Redimensiona el vector de celdas para que tenga el tama�o adecuado
    this->celdas.resize(this->filas, vector<Celda>(this->columnas));
}

// M�todo para colocar minas en el tablero
// Coloca un n�mero espec�fico de minas en posiciones aleatorias del tablero.
// Par�metro:
// - minas: n�mero de minas a colocar en el tablero
void Tablero::colocarMinas(int minas) {
    srand(time(0)); // Inicializa la semilla para la generaci�n de n�meros aleatorios
    int colocadas = 0; // Contador de minas colocadas
    while (colocadas < minas) {
        int fila = rand() % this->filas; // Genera una fila aleatoria
        int col = rand() % this->columnas; // Genera una columna aleatoria
        // Si la celda seleccionada no tiene una mina, se coloca una mina
        if (!this->celdas[fila][col].mina) {
            this->celdas[fila][col].mina = true; // Coloca la mina
            colocadas++; // Incrementa el contador de minas colocadas
        }
    }
}

// M�todo para mostrar el estado del tablero
// Muestra el tablero en la consola, revelando celdas seg�n el modo de juego.
// Par�metro:
// - administrador: booleano que indica si se debe mostrar el tablero completo (true) o solo las celdas descubiertas (false)
void Tablero::mostrar(bool administrador) {
    cout << "\n    "; // Espacio para la numeraci�n de columnas
    for (int j = 1; j <= this->columnas; j++) cout << j << " "; // Muestra los n�meros de las columnas
    cout << "\n   ";
    for (int j = 0; j < this->columnas; j++) cout << "--"; // Dibuja una l�nea divisoria
    cout << "\n";
    for (int i = 0; i < this->filas; i++) {
        cout << i + 1 << " | "; // Muestra el n�mero de la fila
        for (int j = 0; j < this->columnas; j++) {
            // Si es modo administrador y hay una mina, muestra un asterisco
            if (administrador && this->celdas[i][j].mina)
                cout << "* ";
            else
                // Muestra el estado de la celda: descubierta o no
                cout << (this->celdas[i][j].descubierta ? (this->celdas[i][j].mina ? "*" : "O") : "?") << " ";
        }
        cout << "|" << endl; // Cierra la fila
    }
}

// M�todo para descubrir una celda en el tablero
// Intenta descubrir la celda en la posici�n especificada.
// Par�metros:
// - fila: n�mero de fila de la celda a descubrir (1-indexado)
// - col: n�mero de columna de la celda a descubrir (1-indexado)
// Retorna:
// - true si se descubre una mina, false si la celda no tiene mina
bool Tablero::descubrir(int fila, int col) {
    // Verifica si las coordenadas est�n dentro de los l�mites del tablero
    if (fila < 1 || fila > this->filas || col < 1 || col > this->columnas) return false;
    // Verifica si la celda tiene una mina
    if (this->celdas[fila - 1][col - 1].mina) return true; // Retorna true si hay mina
    this->celdas[fila - 1][col - 1].descubierta = true; // Marca la celda como descubierta
    return false; // Retorna false si no hay mina
}
