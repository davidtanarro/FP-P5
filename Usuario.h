#ifndef USUARIO_H
#define USUARIO_H

#include "ListaRegistros.h"

using namespace std;

typedef struct {
	string nombre;			// - El nombre o identificador del usuario(string).Debe ser �nico en el gestor, es decir, en la lista de usuarios del gestor.
	string contrase�a;		// - La contrase�a del usuario(string).
	tListaRegCorreo	listaRegRecibidos;	// - La lista de registros de mensajes recibidos que ser� de tipo tListaRegistros y que nos permite implementar la bandeja de entrada del usuario.
	tListaRegCorreo	listRegEnviados;	// - La lista de registros de mensajes enviados que ser� de tipo tListaRegistros y que nos permite implementar la bandeja de salida del usuario.
} tUsuario;

bool cargar(tUsuario& usuario, ifstream& archivo); // Dado un flujo de archivo(ya abierto), se carga un usuario de fichero.
void guardar(const tUsuario& usuario, ofstream& archivo); // Dado un flujo de archivo(ya abierto), se guarda un usuario en fichero.
void inicializar(tUsuario& usuario, string id, string contrasenia); // Recibe un identificador de usuario y una contrase�a y los asigna al usuario.
bool validarContrasenia(const tUsuario &usuario, string contrasenia); // Recibe una contrase�a y un usuario y devuelve si la contrase�a es correcta o no.

void destruir(tUsuario& usuario); // P5

#endif