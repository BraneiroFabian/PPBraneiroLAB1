#include "trabajos.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"

void mostrarDescripcionServicios(eServicio servicios[],int tamServ)
{
    printf("\nListado de Servicios\n");
    printf("id               Descripcion           Precio\n");

    for(int i=0; i<tamServ; i++)
    {
        printf("%d        %15s         %5.2f\n",servicios[i].id,servicios[i].descripcion,servicios[i].precio);
    }

}

int altaTrabajo(int idX,eTrabajo trabajos[], int tamTrabajos,eMascota mascotas[],int tam,eCliente clientes[],int tamCliente,eTipo tipos[], int tamTipos,eColor colores[],int tamColores,eServicio servicios[], int tamServ)
{


    int todoOK = -1;
    int indice = buscarTrabajoLibre(trabajos,tamTrabajos);
    int auxInt;

    eTrabajo auxTrabajo;
    system("cls");


    printf("***** ALTA TRABAJO *****\n\n");

    if(indice == -1) // hay lugar?
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        while(todoOK==-1)
        {
            mostrarMascotas(mascotas,tam,clientes,tamCliente,tipos,tamTipos,colores,tamColores);
            if(utn_getEntero(&auxInt,2,"Ingrese ID mascota: ", "ID no valido. Reingrese\n",1,1000)==0)
            {
                if(buscarMascota(idX,mascotas,tam)!=-1)
                {
                    auxTrabajo.idMascota=auxInt;

                }
                else
                {
                    printf("El id ingresado no existe.\n");

                }
            }
            else
            {
                printf("Se quedo sin intentos.\n");
                todoOK=0;
                break;
            }
            mostrarDescripcionServicios(servicios,tamServ);
            if(utn_getEntero(&auxInt,2,"Ingrese ID servicio: ","ID no valido. Reingrese\n",20000,20003)==0)
            {
                auxTrabajo.idServicio=auxInt;

            }
            else
            {
                printf("Se quedo sin intentos.\n");
                todoOK=0;
                break;
            }
            if(utn_getEntero(&auxInt,2,"Ingrese dia: ","Dia no valido. Reingrese\n",0,31)==0)
            {

                auxTrabajo.fecha.dia=auxInt;

            }
            else
            {
                printf("Se quedo sin intentos.\n");
                todoOK=0;
                break;
            }
            if(utn_getEntero(&auxInt,2,"Ingrese mes: ","Mes no valido. Reingrese\n",1,12)==0)
            {
                auxTrabajo.fecha.mes=auxInt;

            }
            else
            {
                printf("Se quedo sin intentos.\n");
                todoOK=0;
                break;
            }
            if(utn_getEntero(&auxInt,2,"Ingrese anio: ","Anio no valido. Reingrese\n",2000,2030)==0)
            {
                auxTrabajo.fecha.anio=auxInt;
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
            auxTrabajo.id = idX;

            auxTrabajo.isEmpty = 0;

            printf("El id del nuevo trabajo es: %d\n",idX);

            trabajos[indice] = auxTrabajo;
        }
    }
    return todoOK;
}


int buscarTrabajoLibre(eTrabajo vec[],int tam)
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

void inicializarTrabajos(eTrabajo vec[],int tam)
{


    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }

}
void mostrarTrabajo(eTrabajo x, eMascota mascota,eServicio servicios[], int tamServ)
{
    char descripcionServ[21];
    float precioServicio;
    cargarDescripcionServicios(descripcionServ,x.idServicio,servicios,tamServ,&precioServicio);
    printf("%d     %5d     %10s     %.2f     %d/%d/%d\n\n",x.id,x.idMascota,descripcionServ,precioServicio,x.fecha.dia,x.fecha.mes,x.fecha.anio);

}

int cargarDescripcionServicios(char descripcion[],int id, eServicio servicios[], int tamServ, float* precio)
{
    int todoOK = 0;

    for(int i=0; i<tamServ; i++)
    {
        if(servicios[i].id==id)
        {
            strcpy(descripcion,servicios[i].descripcion);
            *precio=servicios[i].precio;
            todoOK = 1;
        }
    }

    return todoOK;
}


void mostrarTrabajos(eTrabajo vec[],int tam, eMascota mascotas[],int tamMasc,eServicio servicios[], int tamServ)
{


    int flag=0;
    system("cls");
    printf("* * * * *LISTA DE TRABAJOS* * * * *\n\n");
    printf("IDTRAB  IDMASC     SERVICIO     PRECIO      FECHA  \n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {

            mostrarTrabajo(vec[i],mascotas[i],servicios,tamServ);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("No hay trabajos que listar\n");
    }
}
