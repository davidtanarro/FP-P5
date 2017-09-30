#ifndef GESTOR_H
#define GESTOR_H

#include "ListaUsuarios.h"
#include "ListaCorreos.h"

using namespace std;

typedef struct {
	string dominio; // -El dominio del gestor de correo(string).Se trata de un identificador como por ejemplo �fdimail.com�.Nos indica la lista de correos y de usuarios que debemos cargar.
	tListaCorreos listaCorrSistema; // - La lista de correos del sistema que ser� de tipo tListaCorreos y que guarda la �nica copia de los correos que existir� en la aplicaci�n.
	tListaUsuarios listaUsuSistema; // - La lista de usuarios del sistema que ser� de tipo tListaUsuarios.
	int usuario_activo; // - �ndice del usuario activo en el sistema(de tipo int).Nos indica la posici�n en la lista de usuarios que ocupa el usuario que se encuentra registrado en el sistema.Si no hay ning�n usuario registrado(o el usuario ha cerrado sesi�n) valdr� - 1.
} tGestor;

void inicializar(tGestor& gestor, string dominio);
bool arrancar(tGestor& gestor, string dominio); // Inicializa el gestor e intenta arrancarlo cargando la informaci�n del dominio que se le pasa como par�metro.Para ello inicializar� y cargar� la lista de usuarios y de correos de dicho dominio.Si tiene �xito en todas las operaciones devuelve true y si alguna falla devuelve false.
void apagar(tGestor &gestor); // Esta operaci�n apaga el gestor y guarda para ello las listas de usuarios y de correos del dominio que se encontrase activo en ese momento.
bool crearCuenta(tGestor &gestor); // Lee los datos de usuario necesarios para crear una cuenta(id y contrase�a) y si el id de usuario no existe y hay espacio en la lista de usuarios, crea la cuenta del usuario y registra al nuevo usuario como usuario activo en el gestor.Devuelve un booleano indicando si la operaci�n tuvo �xito.
bool iniciarSesion(tGestor &gestor); // Lee los datos de usuario necesarios para validar la cuenta(id y contrase�a) y si el usuario existe y la contrase�a coincide, registra al usuario como usuario activo.Devuelve un booleano indicando si la operaci�n tuvo �xito.
void leerCorreo(tGestor& gestor, tListaRegCorreo& listaReg); // Solicita el correo que el usuario quiere leer(ser� el n�mero con el que el correo es mostrado por pantalla en la bandeja correspondiente), valida que existe y si es as�, lo marca como correo le�do.A continuaci�n, busca el correo en la lista de correos y si lo encuentra lo muestra en la pantalla de lectura del correo(Fig. 3).
void enviarCorreo(tGestor& gestor, const tCorreo &correo); // Este subprograma implementa el env�o del correo en nuestra aplicaci�n.Para ello el correo recibido como par�metro es insertado en la lista de correo.Si ha habido �xito, entonces se inserta el registro correspondiente en la lista de registros enviados del emisor y se intenta insertar igualmente un registro de dicho correo en la lista de registros recibidos del destinatario del correo.Si el destinatario no existe o si su bandeja de entrada est� llena, entonces se mostrar� un mensaje de error.
void borrarCorreo(tGestor& gestor, tListaRegCorreo& listaReg); // Este subprograma implementa el borrado del correo de una bandeja de un determinado usuario(OJO : el correo no se borra de la lista de correos).Para ello, solicita el correo que el usuario quiere borrar(ser� el n�mero con el que el correo es mostrado por pantalla en la bandeja correspondiente), valida que existe y si es as�, procede a borrarlo.
void lecturaRapida(tGestor& gestor, tListaRegCorreo& listaReg); // Este subprograma implementa la lectura r�pida de correos sin leer.El resultado es que muestra en una pantalla todos los correos sin leer ordenados por asunto(ignorando todos los �Re : �) y por fecha.Al finalizar su ejecuci�n los correos sin leer quedar�n marcados como le�dos.

#endif