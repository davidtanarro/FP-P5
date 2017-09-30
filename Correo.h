#ifndef CORREO_H
#define CORREO_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

typedef time_t tFecha;
typedef struct {
	string emisor, destinatario; // Corresponder�n con identificadores de usuarios en el sistema.
	string asunto, cuerpo;
	tFecha fecha;
	string id; // Se compone de la concatenaci�n del emisor y la fecha (Ej: pepe@fdimail.com_143456443)
} tCorreo;

void correoNuevo(tCorreo &correo, string emisor); // Recibe un identificador de emisor y devuelve un correo con todos sus datos rellenos seg�n se ha explicado en la secci�n 1.3.
void correoContestacion(const tCorreo &correoOriginal, tCorreo &correo, string emisor); // Recibe un identificador de emisor y el correo original que se va a contestar, y devuelve un correo con todos sus datos rellenos seg�n se ha explicado en la secci�n 1.3.
string aCadena(const tCorreo &correo); // Devuelve un string con el contenido completo del correo para poderlo mostrar por consola.
string obtenerCabecera(const tCorreo &correo); // Devuelve un string que contiene la informaci�n que se mostrar� en la bandeja de entrada / salida : emisor, asunto y fecha sin hora.
bool cargar(tCorreo &correo, ifstream& archivo); // Dado un flujo de archivo de entrada(ya abierto), lee los datos que corresponden a un correo y lo devuelve.Devuelve false s�lo si el correo cargado no es v�lido.
void guardar(const tCorreo &correo, ofstream& archivo); // Dado un flujo de archivo de salida(ya abierto), escribe en el flujo los datos que corresponden a un correo.

string mostrarSoloDia(tFecha fecha);
string mostrarFecha(tFecha fecha);

#endif