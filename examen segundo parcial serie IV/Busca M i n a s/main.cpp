#include "Juego.h"
#include <iostream>

using namespace std;

// Funci�n para mostrar el men� principal
// Presenta las opciones disponibles al usuario para modificar la configuraci�n, jugar o salir.
void mostrarMenu() {
    cout << "\n--- MENU ----------------\n";
    cout << "1. Modificar configuraci�n\n";
    cout << "2. Jugar directamente\n";
    cout << "3. Salir\n";
    cout << "Elija una opcion: ";
}

// Funci�n para mostrar el men� de configuraci�n
// Permite al usuario ingresar los par�metros del juego, como filas, columnas, minas, vidas y modo de juego.
void mostrarConfiguracionMenu() {
    cout << "\n----------- CONFIGURACION -------------\n";
    cout << "Ingrese el numero de filas (maximo 40): ";
    int filas;
    cin >> filas; // Solicita al usuario el n�mero de filas
    if (filas > 40) filas = 40; // Limita el n�mero de filas a 40

    cout << "Ingrese el numero de columnas (maximo 40): ";
    int columnas;
    cin >> columnas; // Solicita al usuario el n�mero de columnas
    if (columnas > 40) columnas = 40; // Limita el n�mero de columnas a 40

    cout << "Ingrese el numero de minas: ";
    int minas;
    cin >> minas; // Solicita al usuario el n�mero de minas

    cout << "Ingrese el numero de vidas: ";
    int vidas;
    cin >> vidas; // Solicita al usuario el n�mero de vidas

    int modo;
    cout << "Modo de juego (1: Jugador, 0: Administrador): ";
    cin >> modo; // Solicita al usuario el modo de juego

    // Configuraci�n con los nuevos valores
    Configuracion config(filas, columnas, minas, vidas, modo); // Crea un objeto de configuraci�n con los valores ingresados
    Juego juego(config); // Crea un objeto de juego con la configuraci�n
    juego.iniciar(); // Inicia el juego
}

// Funci�n principal del programa
int main() {
    string jugador; // Variable para almacenar el nombre del jugador
    cout << "Ingrese su nombre: ";
    cin >> jugador; // Solicita al usuario su nombre

    int opcion = 0; // Variable para almacenar la opci�n seleccionada por el usuario
    Configuracion config(6, 6, 5, 3, 1); // Configuraci�n predeterminada del juego

    // Bucle principal que muestra el men� y gestiona las opciones seleccionadas
    do {
        mostrarMenu(); // Muestra el men� principal
        cin >> opcion; // Lee la opci�n seleccionada por el usuario

        switch (opcion) {
        case 1: {
            mostrarConfiguracionMenu(); // Muestra el men� de configuraci�n
            break;
        }
        case 2: {
            Juego juego(config); // Crea un objeto de juego con la configuraci�n actual
            juego.iniciar(); // Inicia el juego
            break;
        }
        case 3:
            cout << "Gracias por jugar, �hasta la proxima!\n"; // Mensaje de despedida
            break;
        default:
            cout << "Opci�n no v�lida, por favor elija una opcion entre 1 y 3.\n"; // Mensaje de error para opciones no v�lidas
            break;
        }
    } while (opcion != 3); // Contin�a mostrando el men� hasta que el usuario elija salir

    return 0; // Finaliza el programa
}
