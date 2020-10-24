#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];
    int precio;

}eServicio;

#endif // SERVICE_H_INCLUDED

/** \brief Load four brands with their respective:
 *
 * \param servicios[] eServicio
 * \param tamService int
 * \param quantity int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int harcodearService(eServicio servicios[], int tamService, int quantity);
/** \brief Print the one brand passed by parameter on the screen.
 *
 * \param eServicio struct service
 \param service array
 \param tam array service
 * \return void nothing returns
 */

void showService(eServicio servicio);
/** \brief
 *brief Print the entire array of Clients passed by parameter on the screen.
 * \param servicios[] eServicio
 * \param tamService int
 * \return void nothing returns
 *
 */
void showServiceS(eServicio servicios[], int tamService);
/** \brief
matches the with with the id of the given parameter
 *
 * \param servicios[] eServicio
 * \param tamService int
 * \param idParameter int
 * \return void nothing return
 *
 */
int searchIDService(eServicio servicios[], int tamService, int idParameter);
/** \brief load the description of the service in the id
 *

 * \param id int
 * \param servicio[] eServicio
 * \param tamService int
 * \param desc[] char
 * \return int int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int showDescriptionService(int id, eServicio servicio[], int tamService, char desc[]);
