#include "vehiculo.h"
#include "service.h"
#include "brand.h"
#include "colors.h"
#ifndef JOB_H_INCLUDED
#define JOB_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    int patente;
    int idServicio;
    eFecha fechaDeTrabajo;
    int isEmpty;

}eTrabajo;

#endif // JOB_H_INCLUDED


/** \brief this function load ten jobs with they respective parameters
 *
 * \param id job
 * \param id service
 * \param quantity int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int harcodearJob(eTrabajo trabajos[], int tamTrabajo, int quantity);

/** \brief
 **brief Register a new job.
  Check for free space.
  If there is, request the data.
 * \param trabajo[] eTrabajo
 * \param tamTrabajo int
 * \param autos[] eAuto
 * \param tamAuto int
 * \param servicios[] eServicio
 * \param tamService int
 * \param marcas[] eMarcas
 * \param t int
 * \param colores[] eColor
 * \param tamC int
 * \param idTrabajo int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int addJob(eTrabajo trabajo[], int tamTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamService, eMarcas marcas[], int t, eColor colores[], int tamC, int idTrabajo);
eTrabajo cargarTrabajo(int id, int patente, int servicio, eFecha fecha);
/** \brief
 *Initializes the array of type structure so that the state isEmpty
  * of each position of the array is 1 in all its positions.
 * \param trabajos[] eTrabajo
 * \param tamTrabajo int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */

void initializeJob(eTrabajo trabajos[], int tamTrabajo);
/** \brief
 *Initializes the array of type structure so that the state isEmpty
  * of each position of the array is 1 in all its positions.

 * \param trabajos[] eTrabajo
 * \param tamTrabajo int
 * \return void no return nothing
 *
 */
int searchFreeJob(eTrabajo trabajos[], int tamTrabajo);
/** \brief
 *Find the first available position of the
            array passed by parameter or informs if i
 * \param trabajo eTrabajo
 * \param servicios[] eServicio
 * \param tamService int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
void showJob(eTrabajo trabajo, eServicio servicios[], int tamService);
/** \brief
 *Print the one brand passed by parameter on the screen.

 * \param trabajos[] eTrabajo
 * \param tamTrabajo int
 * \param servicios[] eServicio
 * \param tamService int
 * \return void nothing returns
 *
 */
/** \brief
 *Print the entire array of jobs passed by parameter on the screen.
 * \param trabajos[] eTrabajo
 * \param tamTrabajo int
 * \param servicios[] eServicio
 * \param tamService int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int showJobS(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamService);
