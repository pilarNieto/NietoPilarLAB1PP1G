#include <stdio.h>
#include "showMenuOptione.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "reports.h"
#include "vehiculo.h"
#include "brand.h"
#include "colors.h"
#include "service.h"
#include "job.h"
char showMenuOptions()
{
    char option;
    system("cls");

    printf("======================================================\n");
    printf("                    MENU DE OPCIONES                 \n");
    printf("=====================================================\n\n");
    printf("    (A) ALTA \n");
    printf("    (B) MODIFICAR \n");
    printf("    (C) BAJA \n");
    printf("    (D) LISTAR \n");
    printf("    (E) LISTAR MARCAS\n");
    printf("    (F) LISTAR COLORES\n");
    printf("    (G) LISTAR SERVICIOS\n");
    printf("    (H) ALTA TRABAJOS\n");
    printf("    (I) LISTAR TRABAJOS\n");
    printf("    (J) INFORMES\n");
    printf("(Z) SALIR\n\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%c", &option);
    option = tolower(option);

    return option;
}


void showPrincipalReports(eAuto vehiculos[], int tamAutos
                          , eColor colores[], int tamColor
                          , eMarcas marcas[], int tamMarca
                          , eTrabajo trabajos[], int tamTrabajo
                          , eServicio servicios[], int tamServicio)
{
    char salir = 'n';
    int auxID;
    int auxID2;
    int contadorAux = 0;
    char descAux[20];
    char descAux2[20];
    eFecha auxFecha;
    do
    {
        switch(showMenuReport())
        {
        case 1:
            system("cls");
            showColorS(colores, tamColor);
            printf("Ingrese el ID del color del vehiculo a mostrar: ");
            scanf("%d", &auxID);
            if (validateColor(colores, tamMarca, auxID))
            {
                if (!reportCarColors(vehiculos, tamAutos, colores, tamColor, marcas, tamMarca, auxID))
                {
                    printf("No se han encontrado vehiculos del color solicitado!\n\n");
                }
            } else
                {
                    printf("Se ha ingresado un color incorrecto! Volviendo al menu...\n\n");
                }
            break;
        case 2:
            system("cls");
            showBrandS(marcas, tamMarca);
            printf("Ingrese el ID de la marca a mostrar: ");
            scanf("%d", &auxID);
            if(validateBrand(marcas, tamMarca, auxID))
            {
                if(!reportCarBrand(vehiculos,tamAutos,colores,tamColor,marcas,tamMarca,auxID))
                {
                    printf("No se han encontrado vehiculos de la marca solicitada!\n\n");
                }
            } else
                {
                    printf("Se ha ingresado una marca incorrecta! Volviendo al menu...\n\n");
                }
            break;
        case 3:
            system("cls");
            if(!reportOldCars(vehiculos,tamAutos,colores,tamColor,marcas,tamMarca))
            {
                printf("No se han encontrado vehiculos antiguos!\n\n");
            }
            break;
        case 4:
            system("cls");
            {
                if(!reportSelectBrand(vehiculos,tamAutos,colores,tamColor,marcas,tamMarca))
                {
                    printf("No se han encontrado vehiculos disponibles!\n\n");
                }
            }
            break;
        case 5:
            system("cls");
            showColorS(colores, tamColor);
            printf("Ingrese el color del vehiculo a contar: ");
            scanf("%d", &auxID);
            if(!validateColor(colores, tamMarca, auxID))
            {
                printf("ID del color incorrecto! Volviendo al menu...\n");
            } else
                {
                    printf("\n");
                    showBrandS(marcas, tamMarca);
                    printf("Ingrese la marca del vehiculo a contar: ");
                    scanf("%d", &auxID2);
                    if (!validateBrand(marcas, tamMarca, auxID2))
                    {
                        printf("ID de la marca incorrecta! Volviendo al menu...\n");
                    } else
                        {
                            contadorAux = reportQuantitySelectColorAndBrand(vehiculos,tamAutos,colores
                                                                            ,tamColor,marcas,tamMarca,auxID2,auxID);
                            if (!contadorAux)
                            {
                                printf("No se han encontrado vehiculos disponibles!\n");
                            } else
                                {
                                    showDescriptionColors(auxID, colores, tamColor, descAux);
                                    showDescriptionBrand(auxID2, marcas, tamMarca, descAux2);
                                    printf("\nCantidad de vehiculos de color %s y marca %s: %d\n\n"
                                           , descAux, descAux2, contadorAux);
                                }
                        }
                }
            break;
        case 6:
            system("cls");
            reportMostChosenBrands(vehiculos,tamAutos,colores,tamColor,marcas,tamMarca);
            break;
        case 7:
            system("cls");
            showCarS(vehiculos, tamAutos, marcas, tamMarca, colores, tamColor);
            printf("Ingrese el ID del vehiculo a informar: ");
            scanf("%d", &auxID);
            if (searchIDCarEnArray(vehiculos,tamAutos, auxID) == -1)
            {
                printf("No se ha encontrado el vehiculo con el ID ingresado, volviendo al menu...");
            } else
                {
                    if (!reportJobEachCar(vehiculos, tamAutos, trabajos, tamTrabajo, auxID, servicios, tamServicio))
                    {
                        printf("No se han encontrado trabajos realizados a ese vehiculo!\n");
                    }
                }
            break;
        case 8:
            system("cls");
            showCarS(vehiculos, tamAutos, marcas, tamMarca, colores, tamColor);
            printf("Ingrese el ID del vehiculo a calcular precio de trabajos: ");
            scanf("%d", &auxID);
            if (searchIDCarEnArray(vehiculos,tamAutos, auxID) == -1)
            {
                printf("No se ha encontrado el vehiculo con el ID ingresado, volviendo al menu...");
            } else
                {
                    contadorAux = reportAddService(vehiculos,tamAutos,trabajos, tamTrabajo, auxID,servicios, tamServicio);
                    if (!contadorAux)
                    {
                        printf("No se han encontrado trabajos realizados a ese vehiculo!\n");
                    } else
                        {
                            printf("Suma de trabajos realizados al vehiculo: $%d\n", contadorAux);
                        }
                }
            break;
        case 9:
            system("cls");
            showServiceS(servicios, tamServicio);
            printf("Ingrese el ID del servicio a informar: ");
            scanf("%d", &auxID);
            if (!validateService(servicios, tamServicio, auxID))
            {
                printf("ID del servicio ingresado incorrecto! Volviendo al menu...\n");
            } else
                {
                    if(!reportServicePerformance(vehiculos, tamAutos, trabajos, tamTrabajo, auxID, servicios, tamServicio))
                    {
                        printf("No se han encontrado trabajos realizados a ese vehiculo!\n");
                    }
                }
            break;
        case 10:
            system("cls");
            showJobS(trabajos, tamTrabajo, servicios, tamServicio);
            printf("Ingrese una fecha de trabajo a informar:\n");
            printf("Dia: ");
            fflush(stdin);
            scanf("%d", &auxFecha.dia);
            while(!validateDay(auxFecha.dia))
            {
                printf("Dia ingresado incorrecto, reingrese: ");
                fflush(stdin);
                scanf("%d", &auxFecha.dia);
            }
            printf("Mes: ");
            fflush(stdin);
            scanf("%d", &auxFecha.mes);
            while(!validateMonth(auxFecha.mes))
            {
                printf("Mes ingresado incorrecto, reingrese: ");
                fflush(stdin);
                scanf("%d", &auxFecha.mes);
            }
            printf("Anio: ");
            fflush(stdin);
            scanf("%d", &auxFecha.anio);
            while(!validateYear(auxFecha.anio))
            {
                printf("Anio ingresado incorrecto, reingrese: ");
                fflush(stdin);
                scanf("%d", &auxFecha.anio);
            }
            if (!reportServiceDate(trabajos, tamTrabajo, servicios, tamServicio, auxFecha))
            {
                printf("No se han encontrado servicio(s) realizado(s) en esa fecha!\n");
            }
            break;
        case 11:
            printf("Confirmar salida (s/n): ");
            fflush(stdin);
            scanf("%c", &salir);
            salir = tolower(salir);
            validateOption(&salir);
            break;
            default:
                printf("Opcion ingresada incorrecta! Volviendo al menu...\n");
        }
    system("pause");
    }while(salir == 'n');
}

int showMenuReport()
{
    int opcion;
    system("cls");

    printf("======================================================\n");
    printf("                   MENU DE INFORMES                   \n");
    printf("====================================================\n\n");
    printf("    (1) Listar vehiculos segun el color\n");
    printf("    (2) Mostrar vehiculos segun la marca\n");
    printf("    (3) Informar el/los vehiculos antiguos\n");
    printf("    (4) Mostrar listado de los autos separados por marca\n");
    printf("    (5) Contar cuantos vehiculos existen segun marca y color\n");
    printf("    (6) Mostrar la/s marca/s mas elegidas por los clientes\n");
    printf("    (7) Mostrar trabajos realizados a un vehiculo en especifico\n");
    printf("    (8) Mostrar importe total de los trabajos realizados a un vehiculo en especifico\n");
    printf("    (9) Mostrar vehiculos segun servicio especifico\n");
    printf("    (10) Mostrar servicios realizados segun fecha especifica\n");
    printf("    (11) SALIR\n\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


