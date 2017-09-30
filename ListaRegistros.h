#ifndef LISTA_REGISTROS_H
#define LISTA_REGISTROS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct {
	string id; // se compone de la concatenaci�n del emisor y la fecha (p.e. pepe@fdimail.com_143456443). Este identificador coincide con el identificador del tCorreo.
	bool leido;
} tRegCorreo;

const int DIM_REG = 10;
typedef tRegCorreo *tRegCorreoPtr; // P5
typedef  struct {
	tRegCorreoPtr listaRegistros; // Array Dinamico
	int cont;
	int capacidad;
} tListaRegCorreo;

void inicializar(tListaRegCorreo &listaReg, int capacidadInicial); // Inicializa la lista.
void cargar(tListaRegCorreo &listaReg, ifstream& archivo); // Dado un flujo de archivo de entrada(ya abierto), lee los datos que corresponden a una lista de registros y la devuelve.
void guardar(const tListaRegCorreo &listaReg, ofstream& archivo); // Dado un flujo de archivo de salida(ya abierto), guarda los datos de la lista de registro.
void insertar(tListaRegCorreo &listaReg, tRegCorreo registro); // Dado un registro lo inserta al final de la lista.Si la lista est� llena devuelve false, en otro caso devuelve true.Este subprograma se ejecutar� cuando un usuario env�e un correo ya que se insertar� el registro correspondiente en la lista de registros que representa su bandeja de salida, y tambi�n en las listas de registros que representan las bandejas de entrada de cada uno de los destinatarios del correo.
bool borrar(tListaRegCorreo &listaReg, string id); // Dado un identificador de correo, busca el registro correspondiente y si lo encuentra lo elimina de la lista(�sin dejar huecos!).Si no lo encuentra, devuelve false, en otro caso devuelve true.Este subprograma representa la acci�n de un usuario del borrado de un determinado correo de una de sus bandejas.OJO : esta operaci�n s�lo supone que el registro es borrado de la lista de registros, pero el correo seguir� existiendo en la lista de correos.
bool correoLeido(tListaRegCorreo &listaReg, string id); // Dado un identificador de correo, busca el correspondiente registro y pone el indicador de le�do a true.La operaci�n devuelve un booleano indicando si se encontr� o no el registro.
int buscar(const tListaRegCorreo &listaReg, string id); // Dado un identificador de correo y la lista, devuelve, si dicho identificador existe en la lista, su posici�n, y si no existe devuelve - 1.

void redimensionar(tListaRegCorreo& listaReg); // P5
void destruir(tListaRegCorreo& listaReg);  // P5

#endif