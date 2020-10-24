#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//MY LYBRARIES

#include "showMenuOptione.h"
#include "utn.h"
#include "vehiculo.h"
#include "colors.h"
#include "brand.h"
#include "service.h"
#include "job.h"

// DEFINE

#define TAM_CAR 1000
#define TAM_BRAND 5
#define TAM_COLOR 5
#define TAM_TRABAJO 100
#define TAM_SERVICE 4



int main()
{
    eAuto listaAutos[TAM_CAR];
    eMarcas listaMarcas[TAM_BRAND];
    eColor listaColores[TAM_COLOR];
    eServicio listaServicios[TAM_SERVICE];
    eTrabajo listaTrabajos[TAM_TRABAJO];

    int idMarca = 1000;
    int idColor = 5000;
    int idAuto = 7000;
    int idServicio = 20000;
    int idTrabajo = 10000;
    char salir = 'n';

    initializeCar(listaAutos, TAM_CAR);
    initializeJob(listaTrabajos, TAM_TRABAJO);

    idMarca = idMarca + harcodearBrand(listaMarcas, TAM_BRAND, 5);
    idColor = idColor + harcodearColors(listaColores, TAM_COLOR, 5);
    idAuto = idAuto + harcodearCars(listaAutos, TAM_CAR, 7);
    idServicio = idServicio + harcodearService(listaServicios, TAM_SERVICE, 4);
    idTrabajo = idTrabajo + harcodearJob(listaTrabajos, TAM_TRABAJO, 10); //------->BONUS TRACK

    do
    {
        switch(showMenuOptions())
        {
        case 'a':
            if(addCar(listaAutos, TAM_CAR, idAuto, listaMarcas, TAM_BRAND, listaColores, TAM_COLOR))
            {
                idAuto++;
            }
            break;
        case 'b':
            if(checkAuto(listaAutos, TAM_CAR))
            {
                modifyCar(listaAutos, TAM_CAR, listaMarcas, TAM_BRAND, listaColores, TAM_COLOR);
            } else
                {
                    printf("\n*************DAR DE ALTA UN VEHICULO POR FAVOR***************\n");
                }
            break;
        case 'c':
            if(checkAuto(listaAutos, TAM_CAR))
            {
                removeCar(listaAutos, TAM_CAR, listaMarcas, TAM_BRAND, listaColores, TAM_COLOR);
            } else
                {
                    printf("\n*************DAR DE ALTA UN VEHÍCULO POR FAVOR***************\\n");
                }
            break;
        case 'd':
            if(checkAuto(listaAutos, TAM_CAR))
            {
                system("cls");
                sortCars(listaAutos, TAM_CAR, listaMarcas, TAM_BRAND, listaColores, TAM_COLOR);
                showCarS(listaAutos, TAM_CAR, listaMarcas, TAM_BRAND, listaColores, TAM_COLOR);
            } else
                {
                    printf("\n*************DAR DE ALTA UN VEHÍCULO POR FAVOR***************\n");
                }
            break;
        case 'e':
            system("cls");
            showBrandS(listaMarcas, TAM_BRAND);
            break;
        case 'f':
            system("cls");
            showColorS(listaColores, TAM_COLOR);
            break;
        case 'g':
            system("cls");
            showServiceS(listaServicios, TAM_SERVICE);
            break;
        case 'h':
            if(addJob(listaTrabajos, TAM_TRABAJO, listaAutos, TAM_CAR, listaServicios
                      , TAM_SERVICE, listaMarcas, TAM_BRAND, listaColores, TAM_COLOR, idTrabajo))
            {
                idTrabajo++;
            }
            break;
        case 'i':
            system("cls");
            showJobS(listaTrabajos, TAM_TRABAJO, listaServicios, TAM_SERVICE);
            break;
        case 'j':
            system("cls");
            showPrincipalReports(listaAutos, TAM_CAR, listaColores, TAM_COLOR, listaMarcas, TAM_BRAND
                                , listaTrabajos, TAM_TRABAJO, listaServicios, TAM_SERVICE);
            break;
        case 'z':
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

    return 0;
}

