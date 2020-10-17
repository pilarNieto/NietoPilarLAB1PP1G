#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "brand.h"

int harcodearBrand(eMarcas marcas[], int tamMarca, int quantity)
{
    int count = 0;
        eMarcas listaAuxiliar[] = {
            {1000, "Renault"},
            {1001, "Fiat"},
            {1002, "Ford"},
            {1003, "Chevrolet"},
            {1004, "Peugeot"}
            };
    if (quantity <= 5 && tamMarca >= quantity)
    {
        for (int i = 0; i < quantity; i++)
        {
            marcas[i] = listaAuxiliar[i];
            count++;
        }
    }
    return count;
}

void showBrand(eMarcas marca)
{
    printf("  %d      %10s\n", marca.id, marca.descripcion);
}

void showBrandS(eMarcas marca[], int tamMarca)
{
    int i;
    printf("=================================================\n");
    printf("                     MARCAS                      \n");
    printf("================================================\n\n");
    printf(" ID MARCA     DESCRIPCION\n\n");
    for(i = 0; i < tamMarca; i++)
        {
            if (marca != NULL)
            {
                showBrand(marca[i]);
            }
        }
}

int showDescriptionBrand(int id, eMarcas marca[], int tamMarca, char desc[])
{
    int isFine = 0;

    for (int i = 0; i < tamMarca; i++){
        if (id == marca[i].id){
            strcpy(desc, marca[i].descripcion);
            isFine = 1;
            break;
        }
    }
    return isFine;
}

