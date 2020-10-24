
#include "vehiculo.h"
#include "brand.h"
#include "colors.h"
#include "service.h"
#include "job.h"
#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#endif // UTN_H_INCLUDED
int esNumerica(char* cadena);
/** \brief
 *This function asks the user for an integer number, shows an error message, validates minimums, maximums and retries
 * \param pResultado int*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
int getFloat(float* pResultado);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int esFlotante(char* cadena);
void strlwrLinux(char* cadena);
int getNombre(char* pResultado, int longitud);
int esNombre(char* cadena,int longitud);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int getString(char* cadena, int longitud);
int getStringTelefono(char *pResultado,
                char *pMensaje,
                char *pMensajeError,
                int minimo,
                int maximo,
                int reintentos);
char getSexo(char *pResultado,
             char *pMensaje,
             char *pMensajeError,
             char minimo,
             char maximo,
             int reintentos);

int isAlphaNumeric(char str[]);

//---------------> VALIDATIONS

/** \brief validates the option entered by the user
 *
 * \param option char*
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int validateOption(char* option);
/** \brief validates the option entered by the user
 *
 * \param marcas[] eMarcas
 * \param tamMarca int
 * \param idParameter int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int validateBrand(eMarcas marcas[], int tamMarca, int idParameter);
/** \brief validates that the car brand is within the valid brands
 *
 * \param colores[] eColor
 * \param tamColor int
 * \param idParameter int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int validateColor(eColor colores[], int tamColor, int idParameter);
/** \brief validates that the color entered by the user is in the valid list
 *
 * \param validateModel int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int validateModel(int validateModel);
/** \brief
 *validate the vehicle model
 * \param patenteParametro int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int validatePatent(int patenteParametro);
/** \brief
validate the car patent in numbers
 *
 * \param dayParameter int
 * \return int
 *
 */
int validateDay(int dayParameter);
/** \brief valdidate date between 1 and 31
 *
 * \param monthParameter int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int validateMonth(int monthParameter);
/** \brief validate month between 1 and 12
 *
 * \param yearParameter int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
/** \brief validate year between 1900 and 2020
 *
 * \param yearParameter int
 * \return intReturns [0] if there was an ERROR - [1] All OK.
 *
 */
int validateYear(int yearParameter);
int validateService(eServicio servicios[], int tamServicio, int servicioParametro);
/** \brief
 * validate id service
 * \param struct service
 * \param array service
 param size array service
 param parameter service
 * \return Returns [0] if there was an ERROR - [1] All OK.
 *
 */

