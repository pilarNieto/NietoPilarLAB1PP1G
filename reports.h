#ifndef REPORTS_H_INCLUDED
#define REPORTS_H_INCLUDED

#include "vehiculo.h"
#include "colors.h"
#include "brand.h"
#include "job.h"
#include "service.h"

#endif // REPORTS_H_INCLUDED

/** \brief Show cars of the color selected by the user.
 *
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param colores[] eColor
 * \param tamColor int
 * \param marcas[] eMarcas
 * \param tamMarca int
 * \param idColor int
 * \return int is ok!
 *
 */
int reportCarColors(eAuto vehiculos[], int tamAuto, eColor colores[], int tamColor, eMarcas marcas[], int tamMarca, int idColor);
/** \brief Show cars of a selected brand.
 *
 struct auto
 array vehiculo
 param tam array vehiculo
 param struct color
 param array color
 param tam array color
 param struct brand
 param array brand
 param tam array brand
 param id color
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */

int reportCarBrand(eAuto vehiculos[], int tamAuto, eColor colores[], int tamColor, eMarcas marcas[], int tamMarca, int idMarca);

/** \brief Show a list of cars separated by brand.
 *
 struct auto
 array vehiculo
 param tam array vehiculo
 param struct color
 param array color
 param tam array color
 param struct brand
 param array brand
 param tam array brand
 param id brand
 *return int Returns [0] if there was an ERROR - [1] All OK.
 */
/** \brief Inform the oldest car (s).
 *
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param colores[] eColor
 * \param tamColor int
 * \param marcas[] eMarcas
 * \param tamMarca int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int reportOldCars(eAuto vehiculos[], int tamAuto, eColor colores[], int tamColor, eMarcas marcas[], int tamMarca);

/** \brief show older cars
 *
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param colores[] eColor
 * \param tamColor int
 * \param marcas[] eMarcas
 * \param tamMarca int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 */
int reportSelectBrand(eAuto vehiculos[], int tamAuto, eColor colores[], int tamColor, eMarcas marcas[], int tamMarca);

/** \brief Show a list of cars separated by brand.
 *
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param colores[] eColor
 * \param tamColor int
 * \param marcas[] eMarcas
 * \param tamMarca int
 * \param idMarca int
 * \param idColor int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int reportQuantitySelectColorAndBrand(eAuto vehiculos[], int tamAuto, eColor colores[], int tamColor, eMarcas marcas[], int tamMarca, int idMarca, int idColor);

/** \brief Choose a color and a brand and count how many
There are cars of that color and that brand
 *
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param colores[] eColor
 * \param tamColor int
 * \param marcas[] eMarcas
 * \param tamMarca int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
void reportMostChosenBrands(eAuto vehiculos[], int tamAuto, eColor colores[], int tamColor, eMarcas marcas[], int tamMarca);

/** \brief Show the brand or brands most chosen by customers
 *
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param trabajos[] eTrabajo
 * \param tamTrabajo int
 * \param idAuto int
 * \param servicios[] eServicio
 * \param tamService int
 * \return void nothing returns
 *
 */
int reportJobEachCar(eAuto vehiculos[], int tamAuto, eTrabajo trabajos[], int tamTrabajo, int idAuto, eServicio servicios[], int tamService);

/** \brief Order a car and show all the jobs that were done to it
 *
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param trabajos[] eTrabajo
 * \param tamTrabajo int
 * \param idAuto int
 * \param servicios[] eServicio
 * \param tamService int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
/** \brief Order a car and report the sum of the amounts that They were made to the same.
 *
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param trabajos[] eTrabajo
 * \param tamTrabajo int
 * \param idAuto int
 * \param servicios[] eServicio
 * \param tamService int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int reportAddService(eAuto vehiculos[], int tamAuto, eTrabajo trabajos[], int tamTrabajo, int idAuto, eServicio servicios[], int tamService);

int reportServicePerformance(eAuto vehiculos[], int tamAuto, eTrabajo trabajos[], int tamTrabajo, int idServicio, eServicio servicios[], int tamService);
/** \brief Request a service and show the cars to which that service was performed and the date.
 *
 *array vehiculo
 param tam array vehiculo
 param struct color
 param array color
 param tam array color
 param struct brand
 param array brand
 param tam array brand
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 */

int reportServiceDate(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamService, eFecha fechaParametro);
/** \brief Request a date and show all services performed on it.
 *
 * array vehiculo
 param tam array vehiculo
 param struct color
 param array color
 param tam array color
 param struct brand
 param array brand
 param tam array brand
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */


