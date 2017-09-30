#ifndef LISTA_CORREOS_H
#define LISTA_CORREOS_H

#include "Correo.h"

using namespace std;

const int DIM_CORR = 10;
typedef tCorreo *tCorreoPtr; // P5
typedef struct {
	tCorreoPtr listaCorreos; // Array Dinamico
	int cont;
	int capacidad;
} tListaCorreos;

void inicializar(tListaCorreos &correos, int capacidadInicial); // Inicializa la lista.
bool cargar(tListaCorreos &correos, string dominio); // Implementa la carga de la lista de correos desde el fichero de correos de nombre <NombreDominio>_correos.txt.
void guardar(const tListaCorreos &correos, string dominio); // Implementa el guardado de la lista de correos en el fichero de correos de nombre <NombreDominio>_ correos.txt.Guarda en fichero la lista de correos.El nombre del fichero ser� como en el subprograma anterior.
void insertar(tListaCorreos &correos, const tCorreo &correo); // Dado un correo, si hay espacio en la lista, lo coloca en la posici�n de la lista que le corresponda de acuerdo con su identificador y devuelve true.Si no lo ha podido colocar devuelve false.
bool buscar(const tListaCorreos &correos, string id, int &pos); // Dado un identificador de correo y la lista, devuelve, si dicho identificador existe en la lista, su posici�n y el valor true, y si no existe en la lista, la posici�n que le corresponder�a y el valor false.
void ordenar_AF(tListaCorreos &correos); // Dada una lista de correos la devuelve ordenada por asunto y fecha.Como es una clave de ordenaci�n doble, habr� que redefinir el operador de comparaci�n en el m�dulo que corresponda.

bool operator<(tCorreo& c1, tCorreo& c2); // Devuelve true si c1 es menor alfabeticamente en asunto y en caso de tener el mismo asunto: lo ordena por fecha de mas antiguos a mas recientes, false en cualquier otro caso (se ignora todos los "Re: " de los asuntos)
void limpiarAsunto(string& asunto); // Elimina los "Re: " del un asunto si los hubiese
void mostrarLista(const tListaCorreos& listaCorreos);

void redimensionar(tListaCorreos& listaCorreos); // P5
void destruir(tListaCorreos& listaCorreos);  // P5

#endif