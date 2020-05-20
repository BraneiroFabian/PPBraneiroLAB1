#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "validaciones.h"
#include <string.h>
#include "mascotas.h"
#include "trabajos.h"
#define TAMMAS 5
#define TAMTIPOS 5
#define TAMCOLORES 5
#define TAMSERVICIOS 3
#define TAMTRABAJOS 20
#define TAMCLIENTES 5


int menuInformes();
void informar(eTrabajo trabajos[], int tamTrab,eMascota mascotas[],int tamMasc,eCliente clientes[],int tamCliente,eTipo tipos[],int tamTipo, eColor colores[], int tamColores);
void informarMascotasxTipo(eMascota mascotas[], int tamMasc, eCliente clientes[], int tamCliente, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);
void informarMascotasxColor(eMascota mascotas[], int tamMasc, eCliente clientes[], int tamCliente, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);
void listarMascotasxTipo(eMascota mascotas[],int tamMasc,eCliente clientes[], int tamCliente,eTipo tipos[],int tamTipo, eColor colores[], int tamColores);
int main()
{
    char seguir='s';
    char confirma;
    int flagAltaMascota=0;


    eMascota listaMascotas[TAMMAS];
    eTipo tipos[TAMTIPOS]= {{1000,"Ave"},{1001,"Perro"},{1002,"Gato"},{1003,"Roedor"},{1004,"Pez"}};
    eColor colores[TAMCOLORES]= {{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
    eServicio servicios[TAMSERVICIOS]= {{20000,"Corte",250},{20001,"Desparasitado",300},{20002,"Castrado",400}};
    eTrabajo trabajos[TAMTRABAJOS];
    eCliente clientes[TAMCLIENTES]= {{1,"Carlos",'m'},{2,"Ana",'f'},{3,"Alberto",'m'},{4,"Lucas",'m'},{5,"Luz",'f'}};
    inicializarMascotas(listaMascotas,TAMMAS);
    inicializarTrabajos(trabajos,TAMTRABAJOS);
    int proximoIdMascota=1;
    int proximoIdTrabajo=1;


    do
    {
        switch(mostrarMenu())
        {
        case 'A':
            //altaMasc
            if(altaMascota(proximoIdMascota,listaMascotas,TAMMAS,clientes,TAMCLIENTES,tipos,TAMTIPOS,colores,TAMCOLORES))
            {
                proximoIdMascota++;
                flagAltaMascota=1;

            }
            break;
        case 'B':
            if(flagAltaMascota)
            {

                modificarMascota(listaMascotas,TAMMAS,clientes,TAMCLIENTES,tipos,TAMTIPOS,colores,TAMCOLORES);

            }
            else
            {

                printf("Debe dar de alta una mascota antes de poder modificarla\n");
            }
            break;
        case 'C':
            //bajaMasc
            if(flagAltaMascota)
            {

                bajaMascota(listaMascotas,TAMMAS,clientes,TAMCLIENTES,tipos,TAMTIPOS,colores,TAMCOLORES);
            }
            else
            {
                printf("Debe dar de alta una mascota antes de poder eliminarla\n");
            }
            break;
        case 'D':
            if(flagAltaMascota)
            {
                mostrarMascotas(listaMascotas,TAMMAS,clientes,TAMCLIENTES,tipos,TAMTIPOS,colores,TAMCOLORES);

            }
            else
            {
                printf("Debe dar de alta una mascota para mostrarla\n");
            }
            break;
        case 'E':
            if(flagAltaMascota)
            {
                mostrarDescripcionTipos(tipos,TAMTIPOS);
            }
            else
            {
                printf("Debe dar de alta una mascota para mostrar los tipos\n");
            }
            break;
        case 'F':
            if(flagAltaMascota)
            {
                mostrarDescripcionColores(colores,TAMCOLORES);
            }
            else
            {
                printf("Debe dar de alta una mascota para mostrar los colores\n");
            }
            break;
        case 'G':
            if(flagAltaMascota)
            {
                mostrarDescripcionServicios(servicios,TAMSERVICIOS);
            }
            else
            {
                printf("Debe dar de alta una mascota para mostrar los servicios\n");
            }
            break;
        case 'H':
            if(flagAltaMascota)
            {
                if(altaTrabajo(proximoIdTrabajo,trabajos,TAMTRABAJOS,listaMascotas,TAMMAS,clientes,TAMCLIENTES,tipos,TAMTIPOS,colores,TAMCOLORES,servicios,TAMSERVICIOS))
                {
                    proximoIdTrabajo++;
                }
            }
            else
            {

                printf("Debe dar de alta una mascota para dar de alta un trabajo\n");

            }
            break;
        case 'I':
            if(flagAltaMascota)
            {
                mostrarTrabajos(trabajos,TAMTRABAJOS,listaMascotas,TAMMAS,servicios,TAMSERVICIOS);
            }
            else
            {
                printf("Debe dar de alta una mascota para mostrar los trabajos\n");
            }
            break;
        case 'J':
            if(flagAltaMascota)
            {

                mostrarClientes(clientes,TAMCLIENTES);
            }
            else
            {
                printf("Debe dar de alta una mascota para mostrar los clientes\n");
            }
            break;
        case 'K':
            if(flagAltaMascota){

                informar(trabajos,TAMTRABAJOS,listaMascotas,TAMMAS,clientes,TAMCLIENTES,tipos,TAMTIPOS,colores,TAMCOLORES);
            }else{

                printf("Debe dar de alta una mascota para ingresar a los informes\n");

            }
            break;
        case 'L':
            printf("Confirma salida? (s/n): ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                seguir='n';

            }
            else
            {
                printf("Se cancelo la operacion\n");
            }
            break;
        default:
            printf("Opcion no valida\n");
            break;


        }

        system("pause");
    }
    while(seguir=='s');
    return 0;
}




int menuInformes()
{

    system("cls");
    int opcion;
    printf("*****MENU INFORMES*****\n\n");
    printf("1. Mostrar las mascotas del color seleccionado por el usuario.\n");
    printf("2. Mostrar mascotas de un tipo seleccionado\n");
    printf("3. Informar la o las mascotas de menor edad");
    printf("4. Listar de las mascotas separadas por tipo\n");
    printf("5. Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo.\n");
    printf("6. Mostrar el o los colores con mas cantidad de mascotas\n");
    printf("7. Salir\n\n");
    printf("Ingrese opcion deseada: ");
    scanf("%d",&opcion);

    return opcion;

}

void informar(eTrabajo trabajos[], int tamTrab,eMascota mascotas[],int tamMasc,eCliente clientes[],int tamCliente,eTipo tipos[],int tamTipo, eColor colores[], int tamColores)
{


    char seguir ='s';
    char confirma;

    do
    {
        switch(menuInformes())
        {
        case 1:
            informarMascotasxColor(mascotas,tamMasc,clientes,tamCliente,tipos,tamTipo,colores,tamColores);
            system("pause");
            break;
        case 2:
            informarMascotasxTipo(mascotas,tamMasc,clientes,tamCliente,tipos,tamTipo,colores,tamColores);
            system("pause");
            break;
        case 3:
            printf("\nInforme c\n");
            system("pause");
            break;
        case 4:
            listarMascotasxTipo(mascotas,tamMasc,clientes,tamCliente,tipos,tamTipo,colores,tamColores);
            system("pause");
            break;
        case 5:
            printf("\nInforme e\n");
            system("pause");
            break;
        case 6:
            printf("Confirma salida: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
            break;
        }
    }
    while(seguir =='s');

}
void informarMascotasxTipo(eMascota mascotas[], int tamMasc, eCliente clientes[], int tamCliente, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
	int tipo;
	int flag = 0;

	system("cls");
	printf("***** Informe Mascotas por un Tipo *****\n\n");

	mostrarDescripcionTipos(tipos, tamTipos);
	utn_getEntero(&tipo, 3,"Ingrese el id del tipo que desea mostrar: ", "Id invalido.\n", 1000, 1004);

	printf("ID    Nombre   Tipo    Color    Edad\n\n");
	for(int i = 0; i < tamMasc ; i++)
	{
		if(mascotas[i].isEmpty == 0 && mascotas[i].idTipo == tipo)
		{
			mostrarMascota(mascotas[i],clientes,tamCliente,tipos,tamTipos, colores, tamColores);
			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("No hay mascotas de este tipo.\n\n");
	}
}


void informarMascotasxColor(eMascota mascotas[], int tamMasc, eCliente clientes[], int tamCliente, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
	int color;
	int flag = 0;

	system("cls");
	printf("***** Informe Mascotas por un color *****\n\n");

	mostrarDescripcionColores(colores, tamColores);
	utn_getEntero(&color, 3,"Ingrese el id del color que desea mostrar: ", "Id invalido.\n", 5000, 5004);

	printf("ID    Nombre   Tipo    Color    Edad\n\n");
	for(int i = 0; i < tamMasc ; i++)
	{
		if(mascotas[i].isEmpty == 0 && mascotas[i].idColor == color)
		{
			mostrarMascota(mascotas[i],clientes,tamCliente,tipos,tamTipos, colores, tamColores);
			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("No hay mascotas de este color.\n\n");
	}
}
void listarMascotasxTipo(eMascota mascotas[],int tamMasc,eCliente clientes[], int tamCliente,eTipo tipos[],int tamTipo, eColor colores[], int tamColores){
   int flag = 0;

    system("cls");
    printf("***** LISTAR MASCOTAS POR TIPO*****\n\n");
    //recorro los tipos
    for(int i=0; i<tamTipo; i++)
    {
        printf("Tipos: %s\n",tipos[i].descripcion);

        //recorro las mascotas buscando aquellas del tipo donde esta parado
        for(int j=0; j<tamMasc; j++)
        {
            if(mascotas[j].isEmpty == 0 && mascotas[j].idTipo == tipos[i].id)
            {
                mostrarMascota(mascotas[j],clientes,tamCliente,tipos,tamTipo,colores,tamColores);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay mascotas de este tipo\n\n");
            printf("\n---------------------------------------\n");
        }
    }
}
