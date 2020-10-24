#include "utn.h"
#include "vehiculo.h"
#include "brand.h"
#include "colors.h"
#include "service.h"
#include "job.h"

#ifndef SHOWMENUOPTIONE_H_INCLUDED
#define SHOWMENUOPTIONE_H_INCLUDED
#endif // SHOWMENUOPTIONE_H_INCLUDED

/** \brief
 * shows the options menu and returns the option chosen by the user in a character
 * \return char
 *
 */
char showMenuOptions();
/** \brief shoe menu modify
 *
 * \return int char option
 *
 */
int showMenuModify();
/** \brief
  shows the options menu and returns the option chosen by the user in a character
 * \return int returns the option chosen by the user
 *
 */

int showMenuReport();
/** \brief
 *
this is the main menu that contains the switch with the cases of the reports
 * \param struct auto
 * \param array vehículos
 * \param array size auto
 * \param struct color
 * \param array colores
 * \param array size color
  * \param struct marca
 * \param array marcas
 * \param array sizemarca
 * \return void nothing returns
 *
 */

void showPrincipalReports(eAuto vehiculos[]
                          , int tamAutos, eColor colores[]
                          , int tamColor, eMarcas marcas[]
                          , int tamMarca, eTrabajo trabajos[]
                          , int tamTrabajo, eServicio servicios[], int tamServicio);
