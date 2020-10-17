#include <stdio.h>
#include "showMenuOptione.h"

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
    printf("(Z) SALIR\n\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%c", &option);
    option = tolower(option);

    return option;
}

int showMenuModify()
{
    int option;
    system("cls");
    printf("======================================================\n");
    printf("                    MENU DE MODIFICACIONES             \n");
    printf("=====================================================\n\n");
    printf("\n (1) Modificar Color\n");
    printf("    (2) Modificar Modelo\n");
    printf("    (3) Cancelar operacion\n\n");
    printf("Elija una opcion: ");
    scanf("%d", &option);
}

