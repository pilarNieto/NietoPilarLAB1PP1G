#include <stdio.h>
#include <stdlib.h>
#include "job.h"
#include "vehiculo.h"
#include "service.h"
#include "brand.h"
#include "colors.h"
#include "utn.h"

int addJob(eTrabajo trabajo[], int tamTrabajo, eAuto autos[], int tamAutos, eServicio servicios[], int tamService, eMarcas marcas[], int tamMarcas, eColor colores[], int tamColores, int idTrabajo)
{
    int isFine = 0;
    int auxIdVehiculo;
    int auxIdServicio;
    int indexCar;
    int indexService;
    int indexJob;
    eFecha auxFecha;

    system("cls");
    printf("=======================================================\n");
    printf("                   ALTA TRABAJO                        \n");
    printf("=======================================================\n\n");
    indexJob = searchFreeJob(trabajo, tamTrabajo);
    if (indexJob == -1)
    {
        printf("*******SIN ESPACIO PARA MÁS TRABAJOS*********\n");
    } else
        {
        showCarS(autos, tamAutos, marcas, tamMarcas, colores, tamColores);
        printf("Ingrese el ID del vehiculo para realizar un trabajo: ");
        fflush(stdin);
        scanf("%d", &auxIdVehiculo);
        indexCar = searchIDCarEnArray(autos, tamAutos, auxIdVehiculo);
        if(indexCar != -1)
        {
            showServiceS(servicios, tamService);
            printf("Ingrese el ID del servicio a aplicar: ");
            fflush(stdin);
            scanf("%d", &auxIdServicio);
            indexService = searchIDService(servicios, tamService, auxIdServicio);
            if (indexService != -1)
            {
                printf("Ingrese la fecha del trabajo:\n");
                printf("Dia: ");
                fflush(stdin);
                scanf("%d", &auxFecha.dia);
                while(!validateDay(auxFecha.dia))
                {
                    printf("Ingrese un dia correcto!\n");
                    printf("Dia: ");
                    scanf("%d", &auxFecha.dia);
                }
                printf("Mes: ");
                fflush(stdin);
                scanf("%d", &auxFecha.mes);
                while(!validateMonth(auxFecha.mes))
                {
                    printf("Ingrese un mes correcto!\n");
                    printf("Mes: ");
                    scanf("%d", &auxFecha.mes);
                }
                printf("Anio: ");
                fflush(stdin);
                scanf("%d", &auxFecha.anio);
                while(!validateYear(auxFecha.anio))
                {
                    printf("Ingrese un anio correcto!\n");
                    printf("Anio: ");
                    scanf("%d", &auxFecha.anio);
                }
                trabajo[indexJob] = cargarTrabajo(idTrabajo, autos[indexCar].patente, servicios[indexService].id, auxFecha);
                printf("Se ha cargado un trabajo correctamente!\n");
                isFine = 1;
            } else
                {
                    printf("No se ha encontrado el servicio con ese ID!\n");
                }
        } else
            {
                printf("No se ha encontrado un vehiculo con ese ID!\n");
            }
        }
    return isFine;
}

eTrabajo cargarTrabajo(int id, int patente, int servicio, eFecha fecha)
{
    eTrabajo tra;
    tra.id = id;
    tra.patente = patente;
    tra.idServicio = servicio;
    tra.fechaDeTrabajo = fecha;
    tra.isEmpty = 0;
    return tra;
}

void initializeJob(eTrabajo trabajos[], int tamTrabajos)
{
    for (int i = 0; i < tamTrabajos; i++)
    {
        trabajos[i].isEmpty = 1;
    }
}

int searchFreeJob(eTrabajo trabajos[], int tamTrabajos)
{
    int index = -1;
    for (int i = 0; i < tamTrabajos; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

void showJob(eTrabajo trabajo, eServicio servicios[], int tamService)
{
    char descServicio[20];
    showDescriptionService(trabajo.idServicio, servicios, tamService, descServicio);

    printf("   %d          %d      %20s        %02d/%02d/%d\n", trabajo.id,
            trabajo.patente,
            descServicio,
            trabajo.fechaDeTrabajo.dia,
            trabajo.fechaDeTrabajo.mes,
            trabajo.fechaDeTrabajo.anio);
}

int showJobS(eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamService)
{
    int isFine = 0;
    printf("=================================================\n");
    printf("            LISTADO DE TRABAJOS ACTUALES          \n");
    printf("=================================================\n\n");
    printf("     ID     PATENTE DEL VEHICULO          TRABAJO       FECHA DE TRABAJO\n");
    for(int i = 0; i < tamTrabajos; i++)
    {
        if (trabajos[i].isEmpty == 0)
        {
            showJob(trabajos[i], servicios, tamService);
            isFine = 1;
        }
    }
    return isFine;
}
