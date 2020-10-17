#include "colors.h"
#include "brand.h"
#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED

typedef struct
{
    int id;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

}eAuto;

#endif // VEHICULO_H_INCLUDED


int harcodearCars(eAuto vehiculos[], int tamAuto, int cantidad);
/** \brief load six cars whit their respectiveparameters:
 *
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param idAuto int
 * \param marcas[] eMarcas
 * \param tamMarca int
 * \param colores[] eColor
 * \param tamColor int
 * \return int
 *
 */
int addCar(eAuto vehiculos[], int tamAuto, int idAuto, eMarcas marcas[], int tamMarca, eColor colores[], int tamColor);
/** \brief Register a car.
  Check for free space.
  If there is, request the data.
 *
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \return int
 *
 */
int searchFree(eAuto vehiculos[], int tamAuto);
/** \brief Find the first available position of the
            array passed by parameter or informs if it is full.
 *
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \return int
 *
 */
int checkAuto(eAuto vehiculos[], int tamAuto);

 /** \brief indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 *
 * \param Pointer to array of employees
 * \ param len int Array length
 * \ return int Return (1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

eAuto newAuto(int id, int patente, int idMarca, int idColor, int modelo);
/** \brief
 * load data to structure
 * \param vehiculos[] eAuto
 * \param tamAutos int
 * \return void
 *
 */
void initializeCar(eAuto vehiculos[], int tamAutos);
/** \brief Initializes the array of type structure so that the state isEmpty
  * of each position of the array is 1 in all its positions.
 *
 * \param vehiculos eAuto
 * \param marca[] eMarcas
 * \param tamMarca int
 * \param colores[] eColor
 * \param tamColor int
 * \return void
 *
 */
void showCar(eAuto vehiculos, eMarcas marca[], int tamMarca, eColor colores[], int tamColor);
/** \brief It shows on the screen a car passed by parameter.
 *
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param marcas[] eMarcas
 * \param tamMarca int
 * \param color[] eColor
 * \param tamColor int
 * \return void
 *
 */
void showCarS(eAuto vehiculos[], int tamAuto, eMarcas marcas[], int tamMarca, eColor color[], int tamColor);
/** \brief Print on screen the entire array of cars passed by parameter
 *
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param marcas[] eMarcas
 * \param tamMarca int
 * \param color[] eColor
 * \param tamColor int
 * \return void
 *
 */
void sortCars(eAuto vehiculos[], int tamAuto, eMarcas marcas[], int tamMarca, eColor color[], int tamColor);
/** \brief
 * Order the Array of cars by patent and brand
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param idParametro int
 * \return int
 *
 */
int searchIDCarEnArray(eAuto vehiculos[], int tamAuto, int idParametro);
/** \brief
 *   Search in the array of the auto structure type that matches the
  * id passed by parameter.
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param marcas[] eMarcas
 * \param tamMarca int
 * \param color[] eColor
 * \param tamColor int
 * \return int
 *
 */
int removeCar(eAuto vehiculos[], int tamAuto, eMarcas marcas[], int tamMarca, eColor color[], int tamColor);
/** \brief
 * Eliminate the car in a logical way with the Id passed by parameter.
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param patenteParametro int
 * \return int
 *
 */
int searchCarPatentInArray(eAuto vehiculos[], int tamAuto, int patenteParametro);
/** \brief function that goes through the array of vehicles looking for patent matches
 *
 * \param vehiculos[] eAuto array car
 * \param tamAuto int

 * \return int is ok
 */
/** \brief
 *modifies the car data that the user wants
 * \param vehiculos[] eAuto
 * \param tamAuto int
 * \param marcas[] eMarcas
 * \param tamMarca int
 * \param color[] eColor
 * \param tamColor int
 * \return void
 *
 */
void modifyCar(eAuto vehiculos[], int tamAuto, eMarcas marcas[], int tamMarca, eColor color[], int tamColor);




