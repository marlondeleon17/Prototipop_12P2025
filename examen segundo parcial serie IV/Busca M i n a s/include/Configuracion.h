#ifndef CONFIGURACION_H
#define CONFIGURACION_H

// Clase Configuracion
// Esta clase se encarga de almacenar y gestionar la configuraci�n del juego,
// incluyendo el estado del jugador y las caracter�sticas del tablero.
class Configuracion {
public:
    // Atributos p�blicos de la clase
    int filas;      // N�mero de filas del tablero
    int columnas;   // N�mero de columnas del tablero
    int minas;      // N�mero de minas en el tablero
    int vidas;      // N�mero de vidas del jugador
    int modo;       // Modo de juego (puede indicar diferentes configuraciones de juego)
    int derrotas;   // Contador de derrotas del jugador
    int victorias;  // Contador de victorias del jugador

    // Constructor de la clase Configuracion
    // Inicializa los atributos de la configuraci�n del juego.
    // Par�metros:
    // - f: n�mero de filas del tablero
    // - c: n�mero de columnas del tablero
    // - m: n�mero de minas en el tablero
    // - v: n�mero de vidas del jugador
    // - modo: modo de juego
    Configuracion(int f, int c, int m, int v, int modo);

    // M�todo para incrementar el contador de victorias en 1
    void aumentarVictoria();

    // M�todo para incrementar el contador de derrotas en 1
    void aumentarDerrota();
};

#endif // CONFIGURACION_H
