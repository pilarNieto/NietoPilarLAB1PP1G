#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];
    int precio;

}eServicio;

#endif // SERVICE_H_INCLUDED

int harcodearService(eServicio servicios[], int tamService, int quantity);
void showService(eServicio servicio);
void showServiceS(eServicio servicios[], int tamService);
int searchIDService(eServicio servicios[], int tamService, int idParameter);
int showDescriptionService(int id, eServicio servicio[], int tamService, char desc[]);
