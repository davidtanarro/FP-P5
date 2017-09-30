#include "Usuario.h"

using namespace std;

const string CENTINELA = "XXX";

// Dado un flujo de archivo(ya abierto), se carga un usuario de fichero.
bool cargar(tUsuario& usuario, ifstream& archivo) {
	bool ok = true;

	archivo >> usuario.nombre;
	if (usuario.nombre == CENTINELA)
		ok = false;
	else {
		archivo >> usuario.contrase�a;
		cargar(usuario.listaRegRecibidos, archivo);
		cargar(usuario.listRegEnviados, archivo);
	}

	return ok;
}

// Dado un flujo de archivo(ya abierto), se guarda un usuario en fichero.
void guardar(const tUsuario& usuario, ofstream& archivo) {
	archivo << usuario.nombre << endl << usuario.contrase�a << endl;
	guardar(usuario.listaRegRecibidos, archivo);
	guardar(usuario.listRegEnviados, archivo);
}

// Recibe un identificador de usuario y una contrase�a y los asigna al usuario.
void inicializar(tUsuario& usuario, string id, string contrasenia) { // P5
	usuario.nombre = id;
	usuario.contrase�a = contrasenia;
	inicializar(usuario.listaRegRecibidos, DIM_REG);
	inicializar(usuario.listRegEnviados, DIM_REG);
}

// Recibe una contrase�a y un usuario y devuelve si la contrase�a es correcta o no.
bool validarContrasenia(const tUsuario &usuario, string contrasenia) {
	return usuario.contrase�a == contrasenia;
}

void destruir(tUsuario& usuario) { // P5
	destruir(usuario.listaRegRecibidos);
	destruir(usuario.listRegEnviados);
}