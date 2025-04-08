#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"
#include "Configuracion.h"
#include <chrono>

// Clase Juego
// Esta clase gestiona la l�gica del juego, incluyendo la interacci�n con el tablero
// y la configuraci�n del juego. Permite iniciar el juego y manejar el flujo de la partida.
class Juego {
private:
    Tablero tablero;                          // Objeto que representa el tablero del juego
    Configuracion& config;                    // Referencia a la configuraci�n del juego
    std::chrono::steady_clock::time_point inicio; // Marca de tiempo para registrar el inicio del juego

public:
    // Constructor de la clase Juego
    // Inicializa el juego con la configuraci�n proporcionada.
    // Par�metro:
    // - cfg: referencia a un objeto de tipo Configuracion que contiene los par�metros del juego.
    Juego(Configuracion& cfg);

    // M�todo para iniciar el juego
    // Coloca las minas en el tablero y comienza la partida.
    void iniciar();

    // M�todo para gestionar la l�gica del juego
    // Permite al jugador descubrir celdas en el tablero y maneja la l�gica de ganar o perder.
    void jugar();
};

#endif // JUEGO_H
