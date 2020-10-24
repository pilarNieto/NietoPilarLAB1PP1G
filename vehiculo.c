#include <stdio.h>
#include <stdlib.h>
#include "vehiculo.h"
#include "brand.h"
#include "colors.h"
#include "utn.h"

//----------------------------> TEST CASE

int harcodearCars(eAuto vehiculos[], int tamAutos, int quantity)
{
    int count;

    eAuto list[] =
    {
        {7000, 300555, 1002, 5004, 2018, 0},
        {7001, 403600, 1003, 5002, 1999, 0},
        {7002, 899600, 1000, 5003, 2001, 0},
        {7003, 552103, 1001, 5000, 1970, 0},
        {7004, 325700, 1005, 5003, 2016, 0},
        {7005, 830690, 1001, 5002, 2014, 0}
    };
    if (quantity <= 6 && tamAutos >= quantity)
    {
        for (int i = 0; i < quantity; i++)
        {
            vehiculos[i] = list[i];
            count++;
        }
    }
    return count;
}


void initializeCar(eAuto vehiculos[], int tamAutos)
{
    for(int i = 0; i < tamAutos; i++)
    {
        vehiculos[i].isEmpty = 1;
    }
}

int searchFree(eAuto vehiculos[], int tamAutos)
{
    int index = -1;
    for(int i = 0; i < tamAutos; i++)
    {
        if(vehiculos[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int checkAuto(eAuto vehiculos[], int tamAutos)
{
    int isFine = 0;
    for(int i = 0; i < tamAutos; i++)
    {
        if (vehiculos[i].isEmpty == 0)
        {
            isFine = 1;
        }
    }
    return isFine;
}

eAuto newAuto(int id, int patente, int idMarca, int idColor, int modelo)
{
    eAuto car;
    car.id = id;
    car.patente = patente;
    car.idColor = idColor;
    car.idMarca = idMarca;
    car.modelo = modelo;
    car.isEmpty = 0;
    return car;
}

int addCar(eAuto vehiculos[], int tamAutos, int idAuto, eMarcas marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int isFine = 0;
    int auxPatente;
    int auxIdMarca;
    int auxIdColor;
    int auxModelo;
    int indexCar;

    system("cls");
    printf("=====================================================\n");
    printf("                      ALTA AUTO                      \n");
    printf("=====================================================\n\n");
    indexCar = searchFree(vehiculos, tamAutos);
    if (indexCar == -1)
    {
        printf("********NO HAY ESPACIO PARA OTROS VEHICULOS********\n");
    }
    else
    {
        printf("Ingrese la patente del vehiculo: \n");
        scanf("%d", &auxPatente);
        //isAlphaNumerico
        while(!validatePatent(auxPatente))
        {
            printf("Se ha ingresado una patente incorrecta!\n");
            printf("Reingrese (Ej. 123456):\n");
            fflush(stdin);
            scanf("%d", &auxPatente);
        }
        showBrandS(marcas, tamMarca);
        fflush(stdin);
        utn_getNumero(&auxIdMarca, "Ingrese por favor modelo de la marca del auto:\n", "Error, Reingrese el ID:\n", 1000,1004,3);


        showColorS(colores, tamColor);
        fflush(stdin);
        utn_getNumero(&auxIdColor, "Ingrese por favor ID del color\n", "Error, Reingrese\n", 5000,5004,3);

        printf("Ingrese el anio de fabricacion del vehiculo (1930-2020): ");
        fflush(stdin);
        scanf("%d", &auxModelo);
        while (!validateModel(auxModelo))
        {
            printf("Ingrese un anio correcto! (1930-2020): ");
            fflush(stdin);
            scanf("%d", &auxModelo);
        }
        vehiculos[indexCar] = newAuto(idAuto, auxPatente, auxIdMarca, auxIdColor, auxModelo);
        printf("********EL ALTA DEL AUTO HA SIDO EXITOSA*******.\n");
        isFine = 1;
    }


    return isFine;
}

void showCar(eAuto vehiculos, eMarcas marca[], int tamMarca, eColor colores[], int tamColor)
{
    char descColores[20];
    char descMarca[20];

    showDescriptionColors(vehiculos.idColor, colores, tamColor, descColores);
    showDescriptionBrand(vehiculos.idMarca, marca, tamMarca, descMarca);

    printf("  %d    %d %10s   %8s   %d\n",
           vehiculos.id,
           vehiculos.patente,
           descMarca,
           descColores,
           vehiculos.modelo);
}

void showCarS(eAuto vehiculos[], int tamAutos, eMarcas marcas[], int tamMarca, eColor color[], int tamColor)
{

    printf("===============================================================\n");
    printf("                   LISTADO DE VEHICULOS                        \n");
    printf("================================================================\n");
    printf("          VEHICULOS ORDENADOS SEGUN MARCA Y PATENTE           \n\n");
    printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
    for(int i = 0; i < tamAutos; i++)
    {
        if (vehiculos[i].isEmpty == 0)
        {
            showCar(vehiculos[i], marcas, tamMarca, color, tamColor);
        }
    }
}

int searchIDCarEnArray(eAuto vehiculos[], int tamAutos, int idParameter)
{
    int index = -1;
    for (int i = 0; i < tamAutos; i++)
    {
        if (vehiculos[i].id == idParameter)
        {
            index = i;
            break;
        }
    }
    return index;
}

int removeCar(eAuto vehiculos[], int tamAutos, eMarcas marcas[], int tamMarca, eColor color[], int tamColor)
{
    system("cls");
    int isFine = 0;
    int indexCar;
    int auxIDAuto;
    char answer;

    printf("=======================================================\n");
    printf("                         BAJA AUTO                     \n");
    printf("=====================================================\n\n");
    showCarS(vehiculos, tamAutos, marcas, tamMarca, color, tamColor);
    printf("Ingrese el ID del vehiculo a remover:\n");//CORREGIDO VALIDA ID
    fflush(stdin);
    scanf("%d", &auxIDAuto);
    indexCar = searchIDCarEnArray(vehiculos, tamAutos, auxIDAuto);
    if(indexCar != -1)
    {
        printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
        showCar(vehiculos[indexCar], marcas, tamMarca, color, tamColor);
        printf("Confirmar remoción (s/n):\n ");
        fflush(stdin);
        scanf("%c", &answer);
        validateOption(&answer);
        if(answer == 's')
        {
            vehiculos[indexCar].isEmpty = 1;
            printf("******REMOVIO EL DATO CORRECTAMENTE*******\n");
            isFine = 1;
        }
        else
        {
            printf("Se ha cancelado la operacion.\n");
        }
    }
    else
    {
        printf("ID del vehiculo no encontrado!\n");
    }
    return isFine;
}

int searchCarPatentInArray(eAuto vehiculos[], int tamAutos, int patentParameter)
{
    int index = -1;
    for (int i = 0; i < tamAutos; i++)
    {
        if (vehiculos[i].patente == patentParameter)
        {
            index = i;
            break;
        }
    }
    return index;
}

void modifyCar(eAuto vehiculos[], int tamAutos, eMarcas marcas[], int tamMarca, eColor color[], int tamColor)
{
    int auxPatente;
    int auxColor;
    int auxMarca;
    int index;
    int option;
    system("cls");

    printf("=======================================================\n");
    printf("                         MODIFICAR                     \n");
    printf("=======================================================\n\n");
    showCarS(vehiculos, tamAutos, marcas, tamMarca, color, tamColor);
    printf("Ingrese la patente del vehiculo: ");
    fflush(stdin);
    scanf("%d", &auxPatente);

    index = searchCarPatentInArray(vehiculos, tamAutos, auxPatente);
    if(index != -1)
    {
        printf("ID AUTO   PATENTE     MARCA      COLOR   MODELO\n\n");
        showCar(vehiculos[index], marcas, tamMarca, color, tamColor);
        // showMenuModify();
        printf("======================================================\n");
        printf("                    MENU DE MODIFICACIONES             \n");
        printf("=====================================================\n\n");
        printf("\n(1) Modificar Color\n");
        printf("(2) Modificar Modelo\n");
        printf("(3) Cancelar operacion\n\n");
        printf("Elija una option: ");
        fflush(stdin);
        scanf("%d", &option);
        switch(option)
        {
        case 1:

            showColorS(color, tamColor);
            printf("Ingrese el ID del nuevo color a modificar: ");
            fflush(stdin);
            scanf("%d", &auxColor);
            if(validateColor(color, tamColor, auxColor))
            {
                vehiculos[index].idColor = auxColor;
                printf("Se ha modificado el color del vehiculo correctamente!\n");
                system("pause");
            }
            else
            {
                printf("ID del color incorrecto! Saliendo del menu..\n");
                system("pause");
            }
            break;
        case 2:

            showBrandS(marcas, tamMarca);
            printf("******Ingrese el ID de la nueva marca*****\n");
            fflush(stdin);
            scanf("%d", &auxMarca);
            if(validateBrand(marcas, tamMarca, auxMarca))
            {
                vehiculos[index].idMarca = auxMarca;
                printf("Se ha modificado la marca del vehiculo correctamente!\n");
                system("pause");
            }
            else
            {
                printf("ID de la marca incorrecta. Reintente...\n");
                system("pause");
            }
            break;
        case 3:
            printf("Se ha cancelado la operacion!!!\n");
            break;
        default:
            printf("Opcion seleccionada incorrecta. Reingrese...\n");
            system("pause");
        }
    }
    else
    {
        printf("Patente del vehiculo no existe en el sistema.\n");
    }
}

void sortCars(eAuto vehiculos[], int tamAutos, eMarcas marcas[], int tamMarca, eColor color[], int tamColor)
{

    eAuto auxVehiculo;
    for (int i = 0; i < tamAutos-1; i++)
    {
        for (int j = i+1; j < tamAutos; j++)
        {
            if(vehiculos[i].idMarca > vehiculos[j].idMarca && !vehiculos[i].isEmpty && !vehiculos[i].isEmpty)
            {
                auxVehiculo = vehiculos[i];
                vehiculos[i] = vehiculos[j];
                vehiculos[j] = auxVehiculo;
            }
            if (vehiculos[i].idMarca == vehiculos[j].idMarca && vehiculos[i].patente > vehiculos[j].patente && !vehiculos[i].isEmpty && !vehiculos[i].isEmpty)
            {
                auxVehiculo = vehiculos[i];
                vehiculos[i] = vehiculos[j];
                vehiculos[j] = auxVehiculo;
            }
        }
    }
}
