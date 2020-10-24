#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "service.h"

int harcodearService(eServicio servicios[], int tamService, int quantity)
{
    int count = 0;
        eServicio list[] = {
            {20000, "Lavado", 250},
            {20001, "Pulido", 300},
            {20002, "Encerado", 400},
            {20003, "Completo", 600}
            };
    if (quantity <= 5 && tamService >= quantity)
    {
        for (int i = 0; i < quantity; i++)
        {
            servicios[i] = list[i];
            count++;
        }
    }
    return count;
}

void showService(eServicio servicio)
{
    printf("  %d      %25s        %d\n", servicio.id, servicio.descripcion, servicio.precio);
}

void showServiceS(eServicio servicios[], int tamService)
{
    printf("===================================================\n");
    printf("             LISTA DE SERVICIOS                     \n");
    printf("===================================================\n\n");
    printf("   ID                       DESCRIPCION     PRECIO\n");
    for (int i = 0; i < tamService; i++)
    {
        if (servicios != NULL)
        {
            showService(servicios[i]);
        }
    }
}

int searchIDService(eServicio servicios[], int tamService, int idParameter)
{
    int index = -1;
    for (int i = 0; i < tamService; i++)
    {
        if (servicios[i].id == idParameter)
        {
            index = i;
            break;
        }
    }
    return index;
}

int showDescriptionService(int id, eServicio servicio[], int tamService, char desc[])
{
    int isFine = 0;

    for (int i = 0; i < tamService; i++)
    {
        if (id == servicio[i].id)
        {
            strcpy(desc, servicio[i].descripcion);
            isFine = 1;
            break;
        }
    }
    return isFine;
}
