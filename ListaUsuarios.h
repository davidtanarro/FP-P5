#ifndef LISTA_USUARIOS_H
#define LISTA_USUARIOS_H

#include "usuario.h"

using namespace std;

const int DIM_USU = 50;
typedef tUsuario *tUsuarioPtr;
typedef struct {
	tUsuarioPtr listaUsuarios[DIM_USU];
	int cont;
} tListaUsuarios;

void inicializar(tListaUsuarios &usuarios); // Inicializa la lista.
bool cargar(tListaUsuarios& usuarios, string dominio); // Implementa la carga de la lista de usuarios desde el fichero de usuarios de nombre <NombreDominio>_usuarios.txt .
void guardar(const tListaUsuarios& usuarios, string dominio); // Implementa el guardado de la lista de usuarios en el fichero de usuarios de nombre <NombreDominio>_usuarios.txt .
bool aniadir(tListaUsuarios& usuarios, const tUsuario& usuario); // A�ade un usuario en la posici�n de la lista que le corresponde, si hay sitio para ello.Adem�s devuelve un booleano indicando si la operaci�n tuvo �xito o no.
bool buscarUsuario(const tListaUsuarios& usuarios, string id, int& posicion); // Dado un identificador de usuario y la lista, devuelve, si dicho identificador existe en la lista, su posici�n y el valor true, y si no existe en la lista, la posici�n que le corresponder�a y el valor false.

void destruir(tListaUsuarios& listaUsuSistema); // P5

#endif