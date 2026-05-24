#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>

using namespace std;

void menuPrincipal();
string solicitarNombreDescendiente();

void jugar(const string &nombreDescendiente1);
void estadisticas(const string &nombreDescendiente1);
void creditos();

void mostrarEstadoDeSigilos(bool estado_sigilos[], const string NomDemonios[], const string ElementosDemonios[], int cantDemonios);
int tirarDado();

void showMessageDefeat(const string &nombreDescendiente1);

void EvaluarTirada(int dado1, int dado2, bool estado_sigilos[], bool demonios_disponibles[], int cantDemonios);
int contarDisponibles(bool demoniosDisponibles[], int cantDemonios);

void mostrarOpcionesDisponibles(bool demonios_disponibles[], const string NOMBRES[], const string ELEMENTOS[], int cantDemonios, int opcionesValidas[], int &cantOpciones);

int elegirDemonio(int cantOpciones);

#endif