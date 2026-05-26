#include <iostream>
#include "funciones.h"
#include <cstdlib>
#include <ctime>
using namespace std;

// CREO VARIABLES GLOBALES PARA TENER DISPONIBLES EN TODO EL PROYECTO
const int TOTAL_INVOCACIONES = 15; //(todavia no la use)
int victoriasTotales = 0;
int derrotasTotales = 0;
int invocacionesUsadas = 0;
int totalDemoniosSellados = 0; //(todavia no la use)

// DEFINO funcion para pedir nombre del jugador
string solicitarNombreDescendiente()
{
    string nombreDescendiente1;
    cout << "Ingrese el nombre del descendiente: " << endl;
    cin >> nombreDescendiente1;
    return nombreDescendiente1;
}

// Fn que muestra msj de derrota
void showMessageDefeat(const string &nombreDescendiente1)
{
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
    cout << endl
         << "AMANECE Y LOS SIGILOS SIGUEN BRILLANDO. " << endl;
    cout << endl
         << nombreDescendiente1 << " no logró completar el ritual a tiempo. " << endl;
    cout << endl
         << "Las sombras restantes lo arrastraron entre las páginas del libro, " << endl;
    cout << "donde ahora custodiará el Necronomicón hasta que otro descendiente" << endl;
    cout << "repita el ritual. " << endl;
    cout << endl
         << "FIN DE LA PARTIDA - DERROTA " << endl;
    cout << endl
         << "invocaciones" << endl;
    cout << "Demonios sellados:" << endl;
    cout << "Demonios libres" << endl;
    cout << endl
         << "Presiona cualquier tecla para continuar..." << endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    cin.ignore();
    cin.get();
}

// Fn que muestra msj de victoria
void showMessageVictory(const string &nombreDescendiente1)
{
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
    cout << endl
         << "AMANECER. EL RITUAL ESTÁ COMPLETO. " << endl;
    cout << endl
         << "Los cinco sigilos se apagaron uno tras otro. " << endl;
    cout << "El Necronomicón se cerró por sí solo y volvió a sellarse. " << endl;
    cout << endl
         << nombreDescendiente1 << " sobrevivió a la noche más larga de su vida. " << endl;

    cout << endl
         << "Los Antiguos no regresarán... por ahora. " << endl;
    cout << endl
         << "FIN DE LA PARTIDA - VICTORIA " << endl;
    cout << endl
         << "Sellaste a los cinco demonios" << endl;
    cout << "Invocaciones utilizadas " << invocacionesUsadas << "de 15" << endl;

    cout << "Presiona cualquier tecla para continuar..." << endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    cin.ignore();
    cin.get();
}

// Funcion tirar dados
int tirarDado()
{
    return (rand() % 6) + 1; // funcion aleatoria que genera un rango de 1 a 6
}

void menuPrincipal()
{
    int opcion;
    string nombreDescendiente1;

    do
    {
        cout << "LOS CINCO DEMONIOS" << endl;
        cout << "------------------" << endl;
        cout << " 1 - JUGAR" << endl;
        cout << " 2 - ESTADISTICAS" << endl;
        cout << " 3 - CREDITOS" << endl;
        cout << "------------------" << endl;
        cout << "0 - SALIR" << endl
             << endl;
        cout << "Ingresar la opcion elegida" << endl;
        cin >> opcion;
        cout << endl;

        switch (opcion)
        {
            {
            case 1:
                nombreDescendiente1 = solicitarNombreDescendiente();
                jugar(nombreDescendiente1);
                break;
            }
            {
            case 2:

                estadisticas(nombreDescendiente1);
                break;
            }
            {
            case 3:
                creditos();
                break;
            }
        }

    } while (opcion != 0);
}

// Funcion principal (cdo eligen opcion jugar)
void jugar(const string &nombreDescendiente1)
{
    cout << "Iniciando juego para: " << nombreDescendiente1 << endl;
    // cout << " MOSTRANDO CANTIDAD DE TIRADAS? " << invocacionesRestantes << endl;

    // string nombreDescendiente = solicitarNombreDescendiente();
    const int TIRADAS_TOTALES = 15;
    int demoniosSellados = 0; // Contador de demonios sellados
    int tiradaActual = 0;     // Contador
    bool estado_sigilos[5] = {false, false, false, false, false};
    bool demonios_disponibles[5] = {false, false, false, false, false}; // ACA

    const string NOMBRES_DEMONIOS[] = {"Baramos", "Dracolord", "Darck", "WhiteKing", "Lazamanus"};
    const string ELEMENTOS_SOMBRAS[] = {"Sombra del Fuego", "Sombra del Agua", "Sombra de la Tierra", "Sombra del Aire", "Sombra Mayor"};
    const int CANT_DEMONIOS = 5; // Constante para comparar si hay demonios sellados.

    cout << "-----------------------------------------------------" << endl;
    cout << "Otoño de 2026. La biblioteca de tu familia profanada." << endl;
    cout << "El Necronomicón abierto. Cinco sigilos brillan en rojo." << endl;
    cout << "Las sombras vagan por el mundo. Solo vos podés sellarlas." << endl;
    cout << "Tenés 15 invocaciones antes del amanecer. Sellalas." << endl;
    cout << "-----------------------------------------------------" << endl;

    srand(time(NULL));

    while (tiradaActual < TIRADAS_TOTALES && demoniosSellados < CANT_DEMONIOS)
    {

        tiradaActual++;

        for (int i = 0; i < CANT_DEMONIOS; i++)
        {
            demonios_disponibles[i] = false;
        }

        cout << "\nLOS CINCO DEMONIOS" << endl;
        cout << "-------------------" << endl;
        cout << "Invocacion " << tiradaActual << " de " << TIRADAS_TOTALES << " quedan  " << TIRADAS_TOTALES - tiradaActual << endl;
        // cout << "DESCENDIENTE: " << nombreDescendiente << endl; //se tiene que quitar para tomar nombre descendiente de forma dinamica

        // Llamada a la funcion para saber el estado de los demonios.
        mostrarEstadoDeSigilos(estado_sigilos, NOMBRES_DEMONIOS, ELEMENTOS_SOMBRAS, CANT_DEMONIOS);
        cout << "-------------------";
        cout << "Presione ENTER para tirar los dados...";
        cin.ignore();
        cin.get();

        int dado1 = tirarDado();
        int dado2 = tirarDado();
        cout << "Tirada de dados: [" << dado1 << "] [" << dado2 << "]" << endl;
        EvaluarTirada(dado1, dado2, estado_sigilos, demonios_disponibles, CANT_DEMONIOS);

        int cantDisponible = contarDisponibles(demonios_disponibles, CANT_DEMONIOS);

        if (cantDisponible == 0)
        {
            cout << "La tirada no cumple ninguna combinacion. La invocacion falla." << endl;
        }
        else
        {
            cout << "Combinaciones cumplidas:" << endl;
            int opcionesValidas[5];
            int cantOpciones = 0;
            mostrarOpcionesDisponibles(demonios_disponibles, NOMBRES_DEMONIOS, ELEMENTOS_SOMBRAS, CANT_DEMONIOS, opcionesValidas, cantOpciones);
            int eleccion = elegirDemonio(cantOpciones);
            int indice = opcionesValidas[eleccion - 1];
            estado_sigilos[indice] = true;
            demoniosSellados++;
            cout << NOMBRES_DEMONIOS[indice] << " ha sido SELLADO." << endl;
        }
    }

    if (demoniosSellados == CANT_DEMONIOS)
    {
        cout << "¡Has sellado a todos los demonios! HAS GANADO." << endl;

        victoriasTotales++;
        invocacionesUsadas = tiradaActual;
        showMessageVictory(nombreDescendiente1);
    }
    else
    {
        derrotasTotales++;
        cout << "Se acabaron las invocaciones. HAS PERDIDO." << endl;
        showMessageDefeat(nombreDescendiente1);
    }
}

// Funcion estadisticas

void estadisticas(const string &nombreDescendiente1)
{
    int totalDePartidas = victoriasTotales + derrotasTotales;
    int cantDemoniosSellados = 5;
    cout << "PANTALLA ESTADISTICAS" << endl
         << endl;
    cout << nombreDescendiente1 << " fue quien sello a los " << cantDemoniosSellados << " demonios mas rapidamente en " << invocacionesUsadas << " invocaciones" << endl;
    cout << endl;
    cout << "TOTAL DE PARTIDAS: " << totalDePartidas << endl;
    cout << "VICTORIAS: " << victoriasTotales << endl;
    cout << "DERROTAS: " << derrotasTotales << endl;
    cout << endl;
    cout << " Presiona una tecla para continuar... " << endl
         << endl;
    // pausar la ejecución de un programa de consola hasta que el usuario presione Enter.
    cin.ignore();
    cin.get();
}

// Funcion creditos

void creditos()
{

    cout << "PANTALLA CREDITOS" << endl
         << endl;
    cout << "CREDITO CREDITO CREDITO" << endl;
}

void mostrarEstadoDeSigilos(bool estado_sigilos[], const string NomDemonios[], const string ElementosDemonios[], int cantDemonios)
{
    cout << "ESTADO DE LOS SIGILOS: " << endl;
    for (int i = 0; i < cantDemonios; i++)
    {
        if (estado_sigilos[i])
        {
            cout << "[ SELLADO ] ";
        }
        else
        {
            cout << "[ LIBRE ] ";
        }
        cout << NomDemonios[i] << " - " << ElementosDemonios[i] << endl;
    }
}

// Funcion para evaluar que demonios podemos cerrar
void EvaluarTirada(int dado1, int dado2, bool estado_sigilos[], bool demonios_disponibles[], int cantDemonios)
{
    int sumaDados = dado1 + dado2;

    // Baramos
    if (!estado_sigilos[0] && dado1 == dado2)
    {
        demonios_disponibles[0] = true;
    }
    // Dracolord
    if (!estado_sigilos[1] && sumaDados == 7)
    {
        demonios_disponibles[1] = true;
    }
    // Darck
    if (!estado_sigilos[2] && (dado1 - dado2 == 1 || dado2 - dado1 == 1))
    {
        demonios_disponibles[2] = true;
    }
    // Whiteking
    if (!estado_sigilos[3] && sumaDados >= 10)
    {
        demonios_disponibles[3] = true;
    }
    // Lazamanus
    if (!estado_sigilos[4] && dado1 == dado2 && (dado1 == 5 || dado1 == 6))
    {
        demonios_disponibles[4] = true;
    }
}

int contarDisponibles(bool demoniosDisponibles[], int cantDemonios)
{
    int cantDisponible = 0;

    for (int i = 0; i < cantDemonios; i++)
    {
        if (demoniosDisponibles[i])
        {
            cantDisponible++;
        }
    }
    return cantDisponible;
}

void mostrarOpcionesDisponibles(bool demonios_disponibles[], const string NOMBRES[], const string ELEMENTOS[], int cantDemonios, int opcionesValidas[], int &cantOpciones)
{
    cantOpciones = 0;
    for (int i = 0; i < cantDemonios; i++)
    {
        if (demonios_disponibles[i])
        {
            cantOpciones++;
            opcionesValidas[cantOpciones - 1] = i;
            cout << cantOpciones << " - " << NOMBRES[i] << " - " << ELEMENTOS[i] << endl;
        } // Falta desarollo
    }
}

int elegirDemonio(int cantOpciones)
{
    int eleccion;
    cout << "¿Que sigilo deseas apagar? ";
    cin >> eleccion;
    while (eleccion < 1 || eleccion > cantOpciones)
    {
        cout << "Opcion invalida. Ingrese una opcion valida: ";
        cin >> eleccion;
    }
    return eleccion;
}