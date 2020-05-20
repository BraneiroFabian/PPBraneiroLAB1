#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

void pause();
/** Espera un caracter para continuar con el programa
 */

int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);
/** Valida que se ingrese un numero entero y no permita el ingreso de otra cosa
 *
 * \se le pasa un puntero auxiliar de tipo char
 * \recibe un limite del dato a almacenar
 * \recibe una cantidad de intentos
 * \recibe un mensaje donde pide el entero a ingresar
 * \devuelve un mensaje de error si el dato ingresado no es de tipo entero
 * \retorna que todo haya salido bien
 *
 */


int getCadena(char* pAux, int limit);
/** valida que se pida una cadena
 * \recibe un puntero auxiliar de tipo char
 * \recibe el limite de la cadena a ingresar
 * \devuelve que todo haya salido bien
 */


int isChar(char str[]);
/** verifica que se le ingrese una cadena de tipo caracter
 * recibe una cadena de caracteres
 * devuelve que todo haya salido bien
 */


int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);
/** valida que se ingrese un flotante y no permita el ingreso de otra cosa
 *
 * \recibe un puntero de tipo float
 * \recibe la cantidad de intentos para el ingreso
 * \recibe un mensaje que pide que se ingrese el dato
 * \recibe un mensaje de error en caso de que el usuario haya ingresado otro tipo de dato
 * \recibe un minimo de valor de ingreso
 * \recibe un maximo de valor de ingreso
 * \retorna que todo este ok
 *
 */


int getFloat(float*pAux);
/** pide que se le ingrese un flotante
 * \se le pasa un puntero auxiliar de tipo float
 * retorna que todo este ok
 */

int isFloat(char* pAux);
/** verifica que se le ingrese un dato de tipo flotante
 * recibe un puntero auxiliar de tipo char
 * devuelve que todo haya salido ok
 *
 */


int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);
/** valida que se le ingrese un dato de tipo entero y no deja continuar si es de otro tipo
 * recibe un puntero de tipo entero
 * recibe la cantidad de intentos para ingresar el dato
 * recibe un mensaje que pide el ingreso del dato
 * recibe un mensaje de error que se muestra en caso de que el dato no sea del tipo solicitado
 * recibe un minimo de valor de dato
 * recibe un maximo de valor de dato
 * devuelve que todo haya salido ok
 */


int getInt(int* pAux);
/** pide que se ingrese un dato de tipo entero
 * recibe un puntero auxiliar de tipo entero
 * devuelve que todo haya salido ok
 */

int isInt(char *pAux);
/** verifica que el dato ingresado sea de tipo entero
 * recibe un puntero auxiliar de tipo char
 * devuelve que todo haya salido ok
 */







#endif // VALIDACIONES_H_INCLUDED
