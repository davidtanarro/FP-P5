#include "ListaCorreos.h"

using namespace std;

// Inicializa la lista.
void inicializar(tListaCorreos &correos, int capacidadInicial) { // P5
	correos.listaCorreos = new tCorreo[capacidadInicial];
	correos.cont = 0;
	correos.capacidad = capacidadInicial;
}

// Implementa la carga de la lista de correos desde el fichero de correos de nombre <NombreDominio>_correos.txt.
bool cargar(tListaCorreos &correos, string dominio) { // P5
	bool ok = true;
	int n;
	ifstream archivo;

	archivo.open(dominio + "_correos.txt");
	if (!archivo.is_open()) {
		ok = false;
		inicializar(correos, DIM_CORR);
	}
	else {
		archivo >> n;
		inicializar(correos, (n + 10) - (n % 10));
		correos.cont = n;
		for (int i = 0; i < correos.cont; i++)
			cargar(correos.listaCorreos[i], archivo);
	}
	archivo.close();

	return ok;
}

// Implementa el guardado de la lista de correos en el fichero de correos de nombre <NombreDominio>_ correos.txt.
// Guarda en fichero la lista de correos. El nombre del fichero ser� como en el subprograma anterior.
void guardar(const tListaCorreos &correos, string dominio) { // P5 (cont y centinela)
	ofstream archivo;

	archivo.open(dominio + "_correos.txt");
	archivo << correos.cont << endl;
	for (int i = 0; i < correos.cont; i++)
		guardar(correos.listaCorreos[i], archivo);
	archivo.close();
}

// Dado un correo, si hay espacio en la lista, lo coloca en la posici�n de la lista que le corresponda de acuerdo con su identificador y devuelve true.
// Si no lo ha podido colocar devuelve false.
void insertar(tListaCorreos &correos, const tCorreo &correo) { // P5
	bool inter = true;
	int i = 0;
	tCorreo tmp;
	
	if (correos.cont == correos.capacidad)
		redimensionar(correos);
	correos.listaCorreos[correos.cont] = correo;
	correos.cont++;
	// Desde el 1� hasta el pen�ltimo si hay intercambios...
	while ((i < correos.cont - 1) && inter) {
		inter = false;
		// Desde el �ltimo hasta el siguiente a i...
		for (int j = correos.cont - 1; j > i; j--) {
			if (correos.listaCorreos[j].id < correos.listaCorreos[j - 1].id) {
				tmp = correos.listaCorreos[j];
				correos.listaCorreos[j] = correos.listaCorreos[j - 1];
				correos.listaCorreos[j - 1] = tmp;
				inter = true;
			}
		}
		if (inter) {
			i++;
		}
	}
}

// Dado un identificador de correo y la lista, devuelve, si dicho identificador existe en la lista, su posici�n y el valor true,
// y si no existe en la lista, la posici�n que le corresponder�a y el valor false.
bool buscar(const tListaCorreos &correos, string id, int &pos) {
	int ini = 0, fin = correos.cont - 1, mitad;
	bool encontrado = false;

	while (ini <= fin && !encontrado) {
		mitad = (ini + fin) / 2;
		if (id < correos.listaCorreos[mitad].id)
			fin = mitad - 1;
		else if (correos.listaCorreos[mitad].id < id)
			ini = mitad + 1;
		else
			encontrado = true;
	}
	if (encontrado) pos = mitad;
	else pos = ini;

	return encontrado;
}

// Dada una lista de correos la devuelve ordenada por asunto y fecha.
// Como es una clave de ordenaci�n doble, habr� que redefinir el operador de comparaci�n en el m�dulo que corresponda.
void ordenar_AF(tListaCorreos &correos) {
	bool inter = true;
	int i = 0;
	tCorreo tmp;

	while ((i < correos.cont - 1) && inter) {
		inter = false;
		// Desde el �ltimo hasta el siguiente a i...
		for (int j = correos.cont - 1; j > i; j--) {
			if (correos.listaCorreos[j] < correos.listaCorreos[j - 1]) {
				tmp = correos.listaCorreos[j];
				correos.listaCorreos[j] = correos.listaCorreos[j - 1];
				correos.listaCorreos[j - 1] = tmp;
				inter = true;
			}
		}
		if (inter) {
			i++;
		}
	}
}

// Devuelve true si c1 es menor alfabeticamente en asunto y en caso de tener el mismo asunto:
// lo ordena por fecha de mas antiguos a mas recientes, false en cualquier otro caso (se ignora todos los "Re: " de los asuntos)
bool operator<(tCorreo& c1, tCorreo& c2) {
	bool menor;

	limpiarAsunto(c1.asunto);
	limpiarAsunto(c2.asunto);

	if (c1.asunto < c2.asunto)
		menor = true;
	else if (c2.asunto < c1.asunto)
		menor = false;
	else if (c1.fecha > c2.fecha)
		menor = false;
	else
		menor = true;

	return menor;
}

// Elimina los "Re: " del un asunto si los hubiese
void limpiarAsunto(string& asunto) {
	string re = "Re: ", aux = re;

	while (aux == re) {
		aux = asunto.substr(0, 4);	// aux coge "Re: " si lo hubiese
		if (aux == re)
			asunto.erase(0, 4);		// borra "Re: " del asunto
	}
}

void mostrarLista(const tListaCorreos& listaCorreos) {
	for (int i = 0; i < listaCorreos.cont; i++) {
		cout << aCadena(listaCorreos.listaCorreos[i]);
		cout << "------------------------------------\n";
	}
}

void redimensionar(tListaCorreos& listaCorreos) { // P5
	tCorreoPtr arrayNuevo = new tCorreo[(listaCorreos.capacidad * 3) / 2 + 1];
	
	for (int i = 0; i < listaCorreos.cont; i++)
		arrayNuevo[i] = listaCorreos.listaCorreos[i];
	delete[] listaCorreos.listaCorreos;
	listaCorreos.listaCorreos = arrayNuevo;
	listaCorreos.capacidad = (listaCorreos.capacidad * 3) / 2 + 1;
}

void destruir(tListaCorreos& listaCorreos) { // P5
	delete[] listaCorreos.listaCorreos;
	listaCorreos.listaCorreos = nullptr;
	listaCorreos.cont = 0;
	listaCorreos.capacidad = 0;
}