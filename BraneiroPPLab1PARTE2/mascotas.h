#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[21];
} eTipo;

typedef struct
{
    int id;
    char nombreColor[21];
} eColor;

typedef struct
{
    int id;
    int idCliente;
    char nombre[21];
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;
} eMascota;

typedef struct
{
    int id;
    char nombre[21];
    char sexo;
    int isEmpty;

}eCliente;

#endif // MASCOTAS_H_INCLUDED

int altaMascota(int idX,eMascota vec[], int tam,eCliente clientes[],int tamCliente,eTipo tipos[], int tamTipos,eColor colores[],int tamColores);
/** Pide al usuario los datos a ingresar de una mascota para darla de alta y guardarla en el sistema
 * recibe una variable de tipo int que es donde se va a guardar el id de la mascota ingresada
 * recibe un vector de tipo eMascota
 * recibe el tamanio del vector de tipo emascota a recorrer
 * recibe un vector de tipo ecliente
 * recibe el tamanio del vector de tipo ecliente a recorrer
 * recibe un vector de tipo etipo
 * recibe el tamanio del vector de tipo etipo a recorrer
 * recibe un vector de tipo ecolor
 * recibe el tamanio del vector de tipo ecolor a recorrer
 * devuelve todo ok si se pudieron cargar los datos
 */

int buscarMascLibre(eMascota vec[],int tam);
/** busca un lugar vacio para almacenar una mascota
 * recibe un vector de tipo emascota
 * recibe el tamanio del vector de tipo emascota a recorrer
 * devuelve el indice del lugar vacio
 */

void inicializarMascotas(eMascota vec[],int tam);
/** permite el ingreso del alta de una mascota
 * recibe un vector de tipo emascota
 * recibe el tamanio del vector de tipo emascota a recorrer
 */

void mostrarDescripcionTipos(eTipo tipos[],int tamTipo);
/** muestra por pantalla los diferentes tipos disponibles
 * recibe un vector de tipo etipo
 * recibe el tamanio del vector etipo a recorrer
 */

void mostrarDescripcionColores(eColor colores[],int tamColores);
/** muestra por pantalla los diferentes colores disponibles
 * recibe un vector de tipo ecolor
 * recibe el tamanio del vector ecolor a recorrer
 */

void modificarMascota(eMascota vec[], int tam, eCliente clientes[],int tamCliente,eTipo tipos[], int tamTipo, eColor colores[], int tamColores);
/** permite modificar los datos previamente ingresados de la mascota segun el usuario quiera
 * recibe un vector de tipo emascota
 * recibe el tamanio del vector de tipo emascota a recorrer
 * recibe un vector de tipo ecliente
 * recibe el tamanio del vector de tipo ecliente a recorrer
 * recibe un vector de tipo etipo
 * recibe el tamanio del vector de tipo etipo a recorrer
 * recibe un vector de tipo ecolor
 * recibe el tamanio del vector de tipo ecolor a recorrer
 */

int buscarMascota(int idx, eMascota vec[], int tam);
/** permite buscar una mascota para luego mostrarla mediante otra funcion
 * recibe el id de la mascota a buscar
 * recibe un vector de tipo emascota
 * recibe el tamanio del vector de tipo emascota a recorrer
 * devuelve la posicion de la mascota buscada o un mensaje de error si no se ingreso un id correcto
 */

void mostrarMascota(eMascota x, eCliente clientes[],int tamCliente, eTipo tipos[],int tamTipos, eColor colores[], int tamColores);
/** muestra por pantalla las mascotas con sus respectivos datos
 * recibe un escalar de tipo emascota
 * recibe un vector de tipo ecliente
 * recibe el tamanio del vector de tipo ecliente a recorrer
 * recibe un vector de tipo etipo
 * recibe el tamanio del vector de tipo etipo a recorrer
 * recibe un vector de tipo ecolor
 * recibe el tamanio del vector de tipo ecolor a recorrer
 */

int cargarDescripcionTipo(char tipo[],int id, eTipo tipos[], int tamTipos);
/** carga los datos seleccionados a los campos de la estructura etipo
 * recibe un vector de tipo char
 * recibe un id de tipo entero
 * recibe un vector de tipo etipo
 * recibe el tamanio del vector de tipo etipo a recorrer
 * devuelve todo ok si se pudieron cargar los datos
 */

int cargarDescripcionColor(char color[],int id, eColor colores[], int tamColores);
/** carga los datos seleccionados a los campos de la estructura ecolores
 * recibe un vector de tipo char
 * recibe un id de tipo entero
 * recibe un vector de tipo ecolor
 * recibe el tamanio del vector de tipo ecolor a recorrer
 * devuelve todo ok si se pudieron cargar los datos
 */

void bajaMascota(eMascota vec[], int tam, eCliente clientes[],int tamCliente,eTipo tipos[], int tamTipo, eColor colores[], int tamColores);
/** da de baja del sistema una mascota previamente ingresada
 * recibe un vector de tipo emascota
 * recibe el tamanio del vector de tipo emascota a recorrer
 * recibe un vector de tipo ecliente
 * recibe el tamanio del vector de tipo ecliente a recorrer
 * recibe un vector de tipo etipo
 * recibe el tamanio del vector de tipo etipo a recorrer
 * recibe un vector de tipo ecolor
 * recibe el tamanio del vector de tipo ecolor a recorrer
 */

void mostrarMascotas(eMascota vec[], int tam,eCliente clientes[], int tamCliente, eTipo tipos[], int tamTipo, eColor colores[], int tamColores);
/** muestra un listado de mascotas ingresadas
 * recibe un vector de tipo emascota
 * recibe el tamanio del vector de tipo emascota a recorrer
 * recibe un vector de tipo ecliente
 * recibe el tamanio del vector de tipo ecliente a recorrer
 * recibe un vector de tipo etipo
 * recibe el tamanio del vector de tipo etipo a recorrer
 * recibe un vector de tipo ecolor
 * recibe el tamanio del vector de tipo ecolor a recorrer
 */
int cargarDescripcionCliente(char nombreCliente[],int id, eCliente cliente[], int tamCliente);
/** carga los datos seleccionados a los campos de la estructura ecliente
 * recibe un vector de tipo char
 * recibe un id de tipo entero
 * recibe un vector de tipo ecliente
 * recibe el tamanio del vector de tipo ecliente a recorrer
 */

void mostrarCliente(eCliente clientes[],int tamCliente);
/** muestra a un cliente
 * recibe un vector de tipo ecliente
 * recibe el tamanio del vector de tipo ecliente a recorrer
 */

void mostrarClientes(eCliente clientes[], int tamCliente);
/** muestra el listado de clientes ingresados
 * recibe un vector de tipo ecliente
 * recibe el tamanio del vector de tipo ecliente a recorrer
 */



int menuModificar();
/** es el menu que se muestra para elegir el dato a modificar dentro de la funcion modificarMascota
 * devuelve la opcion seleccionada por el usuario
 */

int mostrarMenu();
/** es el menu principal con las opciones disponibles dentro del programa
 * devuelve la opcion seleccionada por el usuario
 */

