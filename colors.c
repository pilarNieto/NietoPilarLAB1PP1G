#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

int harcodearColors(eColor colores[], int tamColor, int quantity)
{
    int count = 0;
        eColor list[] = {
            {5000, "Blanco"},
            {5001, "Negro"},
            {5002, "Rojo"},
            {5003, "Gris"},
            {5004, "Azul"}
            };
    if (quantity <= 5 && tamColor >= quantity)
    {
        for (int i = 0; i < quantity; i++)
        {
            colores[i] = list[i];
            count++;
        }
    }
    return count;
}

void showColor(eColor col)
{
    printf("  %d    %10s\n", col.id, col.nombre);
}

void showColorS(eColor colores[], int tamColor)
{

    printf("================================================\n");
    printf("            LISTA DE COLORES                    \n");
    printf("===============================================\n\n");
    printf("ID COLOR     DESCRIPCION\n\n");
    for(int i = 0; i < tamColor; i++)
        {
            if (colores != NULL)
            {
                showColor(colores[i]);
            }
        }
    printf("\n");
}

int showDescriptionColors(int id, eColor color[], int tamColor, char desc[])
{
    int isFine = 0;

    for (int i = 0; i < tamColor; i++){
        if (id == color[i].id){
            strcpy(desc, color[i].nombre);
            isFine = 1;
            break;
        }
    }
    return isFine;
}
