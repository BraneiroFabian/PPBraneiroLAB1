#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "mascotas.h"
#include "validaciones.h"


int mostrarMenu()
{

    char opcion;
    system("cls");
    printf("*****Menu veterinaria*****\n\n");
    printf("A. Alta mascota\n");
    printf("B. Modificar mascota\n");
    printf("C. Baja mascota\n");
    printf("D. Listar mascotas\n");
    printf("E. Listar tipos\n");
    printf("F. Listar colores\n");
    printf("G. Listar servicios\n");
    printf("H. Alta trabajo\n");
    printf("I. Listar trabajos\n");
    printf("J. Listar clientes\n");
    printf("K. Informes\n");
    printf("L. Salir\n\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);

    scanf("%c", &opcion);
    opcion=toupper(opcion);
    return opcion;

}


int altaMascota(int idX,eMascota vec[], int tam,eCliente clientes[], int tamCliente,eTipo tipos[], int tamTipos,eColor colores[],int tamColores)
{
    int todoOK = -1;
    int indice = buscarMascLibre(vec,tam);
    char auxChar[51];
    int auxInt;

    eMascota auxMascota;
    system("cls");

    printf("***** ALTA MASCOTA *****\n\n");

    if(indice == -1) // hay lugar?
    {
        printf("Sistema completo\n\n");
    }

    else
    {
        while(todoOK==-1)
        {
            //MARCA
            if((utn_getCadena(auxChar,21,2,"Ingrese el nombre: ","Error. Reingrese.\n"))==0)
            {
                strcpy(auxMascota.nombre,auxChar);
            }
            else
            {
                printf("Se quedo sin intentos\n");
                todoOK=0;
                break;
            }
            mostrarDescripcionTipos(tipos,tamTipos);
            if((utn_getEntero(&auxInt,2,"Ingrese el tipo: ","Error. Reingrese.\n",1000,1004))==0)
            {
                auxMascota.idTipo=auxInt;
            }
            else
            {
                printf("Se quedo sin intentos.\n");
                todoOK=0;
                break;
            }
            mostrarDescripcionColores(colores,tamColores);
            if((utn_getEntero(&auxInt,2,"Ingrese el color: ","Error. Reingrese.\n",5000,5004))==0)
            {
                auxMascota.idColor=auxInt;
            }
            else
            {
                printf("Se quedo sin intentos.\n");
                todoOK=0;
                break;
            }
            if((utn_getEntero(&auxInt,2,"Ingrese la edad: ","Error. Reingrese.\n",0,100))==0)
            {
                auxMascota.edad=auxInt;
                todoOK=1;
            }
            else
            {
                printf("Se quedo sin intentos.\n");
                todoOK=0;
                break;
            }

        }
        if(todoOK==1)
        {
            auxMascota.id = idX;

            auxMascota.isEmpty = 0;

            printf("El id de la nueva mascota es: %d\n",idX);

            vec[indice] = auxMascota;
        }


    }


    return todoOK;
}

int buscarMascLibre(eMascota vec[],int tam)
{

    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void inicializarMascotas(eMascota vec[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

void mostrarDescripcionTipos(eTipo tipos[],int tamTipo)
{
    system("cls");
    printf("\nListado de Tipos\n");
    printf("id        Descripcion\n");

    for(int i=0; i<tamTipo; i++)
    {
        printf("%d      %10s\n",tipos[i].id,tipos[i].descripcion);
    }

}

void mostrarDescripcionColores(eColor colores[],int tamColores)
{
    system("cls");
    printf("\nListado de Colores \n");
    printf("id        Descripcion\n");

    for(int i=0; i<tamColores; i++)
    {
        printf("%d      %10s\n",colores[i].id,colores[i].nombreColor);
    }

}

void modificarMascota(eMascota vec[], int tam, eCliente clientes[],int tamCliente,eTipo tipos[], int tamTipo, eColor colores[], int tamColores)
{

    int indice;
    char confirma;
    int id;
    int auxInt;
    char seguir='s';


    system("cls");
    mostrarMascotas(vec,tam,clientes,tamCliente,tipos,tamTipo,colores,tamColores);

    if((utn_getEntero(&auxInt,2,"Ingrese el ID: ","Error. ID no valido.Reingrese.\n",1,100))==0)
    {
        id=auxInt;
    }
    else
    {
        printf("Te quedaste sin intentos\n");
    }

    indice=buscarMascota(id,vec,tam);

    if (indice==-1)
    {
        printf("No hay ninguna mascota con el id:%d ",id);
    }
    else
    {
        system("cls");
        printf("     ID     NOMBRECLIENTE    NOMBRE        TIPO        COLOR        EDAD     \n\n");
        mostrarMascota(vec[indice],clientes,tamCliente,tipos,tamTipo,colores,tamColores);
        printf("Desea modificar esta mascota? (s/n): ");
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma=='s')
        {
            do
            {
                switch(menuModificar())
                {

                case 'a':
                    mostrarDescripcionTipos(tipos,tamTipo);
                    if(utn_getEntero(&auxInt,2,"Ingrese nuevo tipo: ", "Tipo no valido. Reingrese\n",1000,1004)==0)
                    {
                        vec[indice].idTipo=auxInt;
                        system("cls");
                        printf("Se actualizo el tipo\n");
                    }
                    else
                    {
                        printf("Se quedo sin intentos.\n");
                    }
                    break;
                case 'b':
                    if(utn_getEntero(&auxInt,2,"Ingrese nueva edad: ", "Edad no valida. Reingrese\n",0,100)==0)
                    {
                        vec[indice].edad=auxInt;
                        system("cls");
                        printf("Se actualizo la edad\n");
                    }
                    else
                    {
                        printf("Se quedo sin intentos.\n");
                    }
                    break;
                case 'c':
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

                default:
                    printf("Opcion no valida\n");
                    break;
                }
            }
            while(seguir=='s'); //anda mal
        }
    }
}

int menuModificar()
{
    system("cls");
    char opcion;
    printf("a. Modificar tipo\n");
    printf("b. Modificar edad\n");
    printf("c. Salir\n\n");
    printf("Ingrese opcion deseada: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}
int buscarMascota(int idx, eMascota vec[], int tam)
{

    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].id==idx && vec[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


void mostrarMascota(eMascota x, eCliente clientes[],int tamCliente, eTipo tipos[],int tamTipos, eColor colores[], int tamColores)
{

    char nombreTipo[21];
    char nombreColor[21];
    char nombreCliente[21];

    cargarDescripcionCliente(nombreCliente,x.idCliente,clientes,tamCliente);
    cargarDescripcionTipo(nombreTipo,x.idTipo,tipos,tamTipos);
    cargarDescripcionColor(nombreColor,x.idColor,colores,tamColores);
    printf("%d      %3s    %3s  %3s   %3s    %3d     \n\n",x.id,x.nombre,nombreCliente,nombreTipo,nombreColor,x.edad);

}


int cargarDescripcionTipo(char tipo[],int id, eTipo tipos[], int tamTipos)
{
    int todoOK = 0;

    for(int i=0; i<tamTipos; i++)
    {
        if(tipos[i].id==id)
        {
            strcpy(tipo,tipos[i].descripcion);
            todoOK = 1;
        }
    }

    return todoOK;
}

int cargarDescripcionColor(char color[],int id, eColor colores[], int tamColores)
{
    int todoOK = 0;

    for(int i=0; i<tamColores; i++)
    {
        if(colores[i].id==id)
        {
            strcpy(color,colores[i].nombreColor);
            todoOK = 1;
        }
    }

    return todoOK;
}

void bajaMascota(eMascota vec[], int tam, eCliente clientes[],int tamCliente,eTipo tipos[], int tamTipo, eColor colores[], int tamColores)
{

    int id;
    int indice;
    char confirma;


    printf("Ingrese ID de la mascota: ");
    scanf("%d",&id);

    indice=buscarMascota(id,vec,tam);

    if (indice==-1)
    {
        printf("No hay ninguna mascota con el id:%d ",id);

    }
    else
    {
        printf("ID       NOMBRE    NOMBREDUENIO   TIPO      COLOR      EDAD     \n\n");
        mostrarMascota(vec[indice],clientes, tamCliente,tipos,tamTipo,colores,tamColores);
        printf("Desea eliminar esta mascota? (s/n): ");
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma=='s')
        {
            vec[indice].isEmpty=1;
            printf("Se ha realizado la baja con exito.\n");

        }
        else
        {

            printf("\nSe cancelo la operacion\n\n");

        }
    }
}

void mostrarMascotas(eMascota vec[], int tam,eCliente clientes[], int tamCliente, eTipo tipos[], int tamTipo, eColor colores[], int tamColores)
{


    int flag=0;
    system("cls");
    printf("* * * * *LISTA DE MASCOTAS* * * * *\n\n");
    printf("ID   NOMBREDUENIO       NOMBRE       TIPO      COLOR      EDAD     \n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {

            mostrarMascota(vec[i],clientes,tamCliente,tipos,tamTipo,colores,tamColores);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("No hay mascotas que listar\n");
    }
}

int cargarDescripcionCliente(char nombreCliente[],int id, eCliente cliente[], int tamCliente)
{
    int todoOK = 0;

    for(int i=0; i<tamCliente; i++)
    {
        if(cliente[i].id==id)
        {
            strcpy(nombreCliente,cliente[i].nombre);
            todoOK = 1;
        }
    }

    return todoOK;
}

void mostrarCliente(eCliente clientes[],int tamCliente)
{

    printf("%d     %7s      %5c\n\n",clientes->id,clientes->nombre,clientes->sexo);

}


void mostrarClientes(eCliente clientes[], int tamCliente)
{
    int flag=0;
    system("cls");
    printf("* * * * *LISTA DE CLIENTES* * * * *\n\n");
    printf("ID       NOMBRE         SEXO\n\n");

    for(int i=0; i<tamCliente; i++)
    {
        if(clientes[i].isEmpty==0)
        {

            mostrarCliente(clientes,tamCliente);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("No hay clientes que listar\n");
    }
}
