#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int id;
    char descripcion[26];
    float precio;
} eServicio;

typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;


#endif // TRABAJOS_H_INCLUDED
#include "mascotas.h"
void mostrarDescripcionServicios(eServicio servicios[],int tamServ);
/** muestra la descripcion de los servicios
 * recibe un vector de tipo eServicio
 * recibe el tamaño del vector a recorrer
 */

int altaTrabajo(int idX,eTrabajo trabajos[], int tamTrabajos,eMascota mascotas[],int tam,eCliente clientes[],int tamCliente,eTipo tipos[], int tamTipos,eColor colores[],int tamColores,eServicio servicios[], int tamServ);
/** da de alta un trabajo pidiendo el id de una mascota y del servicio a realizar
 * recibe el id que luego se guardara para identificar al trabajo
 * recibe un vector de tipo etrabajo
 * recibe el tamanio del vector de tipo etrabajo a recorrer
 * recibe un vector de tipo emascota
 * recibe el tamanio del vector de tipo emascota a recorrer
 * recibe un vector de tipo etipo
 * recibe el tamanio del vector de tipo etipo a recorrer
 * recibe un vector de tipo ecolor
 * recibe el tamanio del vector de tipo ecolor a recorrer
 * recibe un vector de tipo eservicio
 * recibe el tamanio del vector de tipo eservicio a recorrer
 * devuelve todo ok si se pudieron cargar los datos
 */

int buscarTrabajoLibre(eTrabajo vec[],int tam);
/** busca un lugar vacio para guardar un trabajo ingresado
 * recibe un vector de tipo etrabajo
 * recibe el tamanio del vector a recorrer
 * devuelve el indice del lugar vacio para guardar el dato
 */

void inicializarTrabajos(eTrabajo vec[],int tam);
/** permite el ingreso del alta de un trabajo
 * recibe un vector de tipo etrabajo
 * recibe el tamanio del vector a recorrer
 */

int cargarDescripcionServicios(char descripcion[],int id, eServicio servicios[], int tamServ, float* precio);
/** copia a una variable el campo descripcion de la estructura eServicio para poder mostrarlo
 * recibe un vector de tipo char
 * recibe un id de tipo entero
 * recibe un vector de tipo eservicio
 * recibe el tamanio del vector de tipo eservicio a recorrer
 * recibe un puntero de tipo float para cargar el precio
 * devuelve todo ok si se pudo cargar los datos
 */

void mostrarTrabajos(eTrabajo vec[],int tam, eMascota mascotas[],int tamMasc,eServicio servicios[], int tamServ);
/** muestra un listado de los trabajos ingresados y verifica que haya trabajos ingresados
 * recibe un vector de tipo etrabajo
 * recibe el tamanio del vector de tipo etrabajo a recorrer
 * recibe un vector de tipo emascota
 * recibe el tamanio del vector de tipo emascota a recorrer
 * recibe un vector de tipo eservicio
 * recibe el tamanio del vector de tipo eservicio a recorrer
 */

void mostrarTrabajo(eTrabajo x, eMascota mascota,eServicio servicios[], int tamServ);
/** muestra los datos del trabajo ingresado
 * recibe un escalar de tipo etrabajo
 * recibe un escalar de tipo mascota
 * recibe un vector de tipo eservicio
 * recibe el tamanio del vector de tipo eservicio a recorrer
 */

