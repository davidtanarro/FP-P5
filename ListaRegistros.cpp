#include "ListaRegistros.h"

using namespace std;

// Inicializa la lista.
void inicializar(tListaRegCorreo &listaReg, int capacidadInicial) { // P5
	listaReg.listaRegistros = new tRegCorreo[capacidadInicial];
	listaReg.cont = 0;
	listaReg.capacidad = capacidadInicial;
}

// Dado un flujo de archivo de entrada(ya abierto), lee los datos que corresponden a una lista de registros y la devuelve.
void cargar(tListaRegCorreo &listaReg, ifstream& archivo) { // P5
	int n;

	archivo >> n;
	inicializar(listaReg, (n + 10) - (n % 10));
	listaReg.cont = n;
	for (int i = 0; i < listaReg.cont; i++)
		archivo >> listaReg.listaRegistros[i].id >> listaReg.listaRegistros[i].leido;
}

// Dado un flujo de archivo de salida(ya abierto), guarda los datos de la lista de registro.
void guardar(const tListaRegCorreo &listaReg, ofstream& archivo) {
	archivo << listaReg.cont << endl;
	for (int i = 0; i < listaReg.cont; i++)
		archivo << listaReg.listaRegistros[i].id << "		" << listaReg.listaRegistros[i].leido << endl;
}

// Dado un registro lo inserta al final de la lista.Si la lista est� llena devuelve false, en otro caso devuelve true.
// Este subprograma se ejecutar� cuando un usuario env�e un correo ya que se insertar� el registro correspondiente en la lista de registros que representa su bandeja de salida,
// y tambi�n en las listas de registros que representan las bandejas de entrada de cada uno de los destinatarios del correo.
void insertar(tListaRegCorreo &listaReg, tRegCorreo registro) { // P5
	if (listaReg.cont == listaReg.capacidad)
		redimensionar(listaReg);
	listaReg.listaRegistros[listaReg.cont].id = registro.id;
	listaReg.listaRegistros[listaReg.cont].leido = registro.leido;
	listaReg.cont++;
}

// Dado un identificador de correo, busca el registro correspondiente y si lo encuentra lo elimina de la lista(�sin dejar huecos!).
// Si no lo encuentra, devuelve false, en otro caso devuelve true.
// Este subprograma representa la acci�n de un usuario del borrado de un determinado correo de una de sus bandejas.
// OJO : esta operaci�n s�lo supone que el registro es borrado de la lista de registros, pero el correo seguir� existiendo en la lista de correos.
bool borrar(tListaRegCorreo &listaReg, string id) {
	bool ok = true;
	int pos;

	pos = buscar(listaReg, id);
	if (pos == -1)
		ok = false;
	else {
		for (int i = pos; i < listaReg.cont-1; i++)
			listaReg.listaRegistros[i] = listaReg.listaRegistros[i + 1];
		listaReg.cont--;
	}

	return ok;
}

// Dado un identificador de correo, busca el correspondiente registro y pone el indicador de le�do a true.
// La operaci�n devuelve un booleano indicando si se encontr� o no el registro.
bool correoLeido(tListaRegCorreo &listaReg, string id) {
	bool ok = true;
	int pos;

	pos = buscar(listaReg, id);
	if (pos == -1)
		ok = false;
	else
		listaReg.listaRegistros[pos].leido = true;

	return ok;
}

// Dado un identificador de correo y la lista, devuelve, si dicho identificador existe en la lista, su posici�n, y si no existe devuelve - 1.
int buscar(const tListaRegCorreo &listaReg, string id) {
	int pos = 0;
	bool encontrado = false;

	while (!encontrado && pos < listaReg.cont)
		if (listaReg.listaRegistros[pos].id == id)
			encontrado = true;
		else
			pos++;
	if (!encontrado)
		pos = -1;

	return pos;
}

void redimensionar(tListaRegCorreo& listaReg) { // P5
	tRegCorreoPtr arrayNuevo = new tRegCorreo[(listaReg.capacidad * 3) / 2 + 1];

	for (int i = 0; i < listaReg.cont; i++)
		arrayNuevo[i] = listaReg.listaRegistros[i];
	delete[] listaReg.listaRegistros;
	listaReg.listaRegistros = arrayNuevo;
	listaReg.capacidad = (listaReg.capacidad * 3) / 2 + 1;
}

void destruir(tListaRegCorreo& listaReg) { // P5
	delete[] listaReg.listaRegistros;
	listaReg.listaRegistros = nullptr;
	listaReg.cont = 0;
	listaReg.capacidad = 0;
}
