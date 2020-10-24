#include <stdio.h>
#include <stdlib.h>
#include "vehiculo.h"
#include "colors.h"
#include "brand.h"
#include "job.h"
#include "service.h"

int reportCarColors(eAuto vehiculos[], int tamAuto, eColor colores[], int tamColor, eMarcas marcas[], int tamMarca, int idColor)
{
    int existingUnits = 0;
    system("cls");
    printf("======================================================================\n");
    printf("                     LISTA DE VEHICULOS POR COLOR                      \n");
    printf("=======================================================================\n");
    printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
    for (int i = 0; i < tamAuto; i++)
    {
        if (vehiculos[i].idColor == idColor)
        {
            showCar(vehiculos[i], marcas, tamMarca, colores, tamColor);
            existingUnits = 1;
        }
    }
    return existingUnits;
}

int reportCarBrand(eAuto vehiculos[], int tamAuto, eColor colores[], int tamColor, eMarcas marcas[], int tamMarca, int idMarca)
{
    int existingUnits = 0;
    system("cls");
    printf("=====================================================================\n");
    printf("                  LISTADO POR VEHICULOS POR MARCA                    \n");
    printf("=====================================================================\n");
    printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
    for (int i = 0; i < tamAuto; i++)
    {
        if (vehiculos[i].idMarca == idMarca && vehiculos[i].isEmpty == 0)
        {
            showCar(vehiculos[i], marcas, tamMarca, colores, tamColor);
            existingUnits = 1;
        }
    }
    return existingUnits;
}

int reportOldCars(eAuto vehiculos[], int tamAuto, eColor colores[], int tamColor, eMarcas marcas[], int tamMarca)
{
    int existingUnits = 0;
    system("cls");
    printf("===================================================================\n");
    printf("                  LISTADO DE VEHICULOS ANTIGUOS                    \n");
    printf("===================================================================\n");
    printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
    for (int i = 0; i < tamAuto; i++)
    {
        if (vehiculos[i].modelo <= 2000 && vehiculos[i].isEmpty == 0)
        {
            showCar(vehiculos[i], marcas, tamMarca, colores, tamColor);
            existingUnits = 1;
        }
    }
    return existingUnits;
}

int reportSelectBrand(eAuto vehiculos[], int tamAuto, eColor colores[], int tamColor, eMarcas marcas[], int tamMarca)
{
    int existingUnits = 0;
    system("cls");
    printf("====================================================================\n");
    printf("               LISTADO DE VEHICULOS POR MARCA                        \n");
    printf("=====================================================================\n");
    for(int i = 0; i < tamMarca; i++)
    {
        printf("\n         MARCA %s           \n", marcas[i].descripcion);
        printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
        for (int j = 0; j < tamAuto; j++)
        {
            if (vehiculos[j].idMarca == marcas[i].id && vehiculos[j].isEmpty == 0)
            {
                showCar(vehiculos[j], marcas, tamMarca, colores, tamColor);
                existingUnits = 1;
            }
        }
    }

    return existingUnits;
}

int reportQuantitySelectColorAndBrand(eAuto vehiculos[], int tamAuto, eColor colores[], int tamColor, eMarcas marcas[], int tamMarca, int idMarca, int idColor)
{
    int count = 0;

    for (int i = 0; i < tamAuto; i++)
    {
        if (vehiculos[i].idColor == idColor && vehiculos[i].idMarca == idMarca && vehiculos[i].isEmpty == 0)
        {
            count++;
        }
    }
    return count;
}

void reportMostChosenBrands(eAuto vehiculos[], int tamAuto, eColor colores[], int tamColor, eMarcas marcas[], int tamMarca)
{
    int quantity[tamMarca];
    int maxBrand;
    int flag = 0;
    printf("========================================================\n");
    printf("                  MARCAS MAS ELEGIDAS                    \n");
    printf("========================================================\n");

    for (int i = 0; i < tamMarca; i++)
    {
        quantity[i] = 0;
    }
    for (int i = 0; i < tamMarca; i++)
    {
        for (int j = 0; j < tamAuto; j++)
        {
            if (vehiculos[j].isEmpty == 0 && vehiculos[j].idMarca == marcas[i].id)
            {
                quantity[i]++;
            }
        }
    }
    for (int i = 0; i < tamMarca; i++)
    {
        if (quantity[i] > maxBrand || flag == 0)
        {
            maxBrand = quantity[i];
            flag = 1;
        }
    }
    printf("------> MARCAS MAS ELEGIDAS:\n");
    for (int i = 0; i < tamMarca; i++)
    {
        if (quantity[i] == maxBrand)
        {
            printf("------> %s\n", marcas[i].descripcion);
        }
    }
    printf("\n");
}

int reportJobEachCar(eAuto vehiculos[], int tamAuto, eTrabajo trabajos[], int tamTrabajo, int idAuto, eServicio servicios[], int tamService)
{
    int existingUnits = 0;
    printf("====================================================\n");
    printf("             LISTA DE TRABAJOS REALIZADOS            \n");
    printf("====================================================\n\n");
    printf("     ID     PATENTE DEL VEHICULO          TRABAJO       FECHA DE TRABAJO\n");
    for (int i = 0; i < tamTrabajo; i++)
    {
        for (int j = 0; j < tamAuto; j++)
        {
            if (vehiculos[j].patente == trabajos[i].patente && vehiculos[j].isEmpty == 0 && vehiculos[j].id == idAuto)
            {
                showJob(trabajos[i], servicios, tamService);
                existingUnits = 1;
            }
        }
    }
    return existingUnits;
}

int reportAddService(eAuto vehiculos[], int tamAuto, eTrabajo trabajos[], int tamTrabajo, int idAuto, eServicio servicios[], int tamService)
{
    int acumPriceService = 0;

    for (int i = 0; i < tamTrabajo; i++)
    {
        for (int j = 0; j < tamService; j++)
        {
           for (int k = 0; k < tamAuto; k++)
            {
                if (vehiculos[k].isEmpty == 0 && vehiculos[k].id == idAuto && vehiculos[k].patente == trabajos[i].patente && servicios[j].id == trabajos[i].idServicio)
                {
                    acumPriceService+=servicios[j].precio;
                }
            }
        }
    }
    return acumPriceService;
}

int reportServicePerformance(eAuto vehiculos[], int tamAuto, eTrabajo trabajos[], int tamTrabajo, int idServicio, eServicio servicios[], int tamService)
{
    int checkServicio = 0;
    printf("================================================================\n");
    printf("                       SERVICIOS REALIZADOS                      \n");
    printf("===============================================================\n\n");
    printf("  ID AUTO                   SERVICIO       FECHA DEL SERVICIO\n");
    for (int i = 0; i < tamTrabajo; i++)
    {
        for (int j = 0; j < tamService; j++)
        {
           for (int k = 0; k < tamAuto; k++)
            {
                if (vehiculos[k].isEmpty == 0 && servicios[j].id == idServicio && vehiculos[k].patente == trabajos[i].patente && servicios[j].id == trabajos[i].idServicio)
                {
                    printf("   %d        %20s           %02d/%02d/%d\n", vehiculos[k].id, servicios[j].descripcion, trabajos[i].fechaDeTrabajo.dia, trabajos[i].fechaDeTrabajo.mes, trabajos[i].fechaDeTrabajo.anio);
                    checkServicio = 1;
                }
            }
        }
    }
    return checkServicio;
}

int reportServiceDate(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamService, eFecha fechaParametro)
{
    int checkServicio = 0;
    printf("==================================================================\n");
    printf("                   SERVICIOS REALIZADOS                           \n");
    printf("================================================================\n\n");
    printf(" FECHA DEL SERVICIO           SERVICIO\n");
    for (int i = 0; i < tamTrabajo; i++)
    {
        for (int j = 0; j < tamService; j++)
        {
            if (fechaParametro.dia == trabajos[i].fechaDeTrabajo.dia &&
                fechaParametro.mes == trabajos[i].fechaDeTrabajo.mes &&
                fechaParametro.anio == trabajos[i].fechaDeTrabajo.anio
                && trabajos[i].idServicio == servicios[j].id)
            {
                printf("    %02d/%02d/%d   %20s\n", trabajos[i].fechaDeTrabajo.dia,trabajos[i].fechaDeTrabajo.mes,trabajos[i].fechaDeTrabajo.anio, servicios[j].descripcion);
                checkServicio = 1;
               }
        }
    }
    return checkServicio;
}
