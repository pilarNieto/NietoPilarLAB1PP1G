#ifndef BRAND_H_INCLUDED
#define BRAND_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];

}eMarcas;

#endif // BRAND_H_INCLUDED

/** \brief / * Load five brands with their respective:
 *
 * \param marcas[] eMarcas struct and array
 * \param tamMarca int tam array
 * \param quantity int
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
int harcodearBrand(eMarcas marcas[], int tamMarca, int quantity);
/** \brief Print the one brand passed by parameter on the screen.
 *
 * \param marca eMarcas
 \param marca eMarcas
 \param marca eMarcas
 * \return int Returns [0] if there was an ERROR - [1] All OK.
 *
 */
void showBrand(eMarcas marca);
/** \brief Print the entire array of Brands passed by parameter on the screen.
 *
 * \param marca[] eMarcas
 * \param tamMarca int
 * \return void nothing returns
 *
 */
void showBrandS(eMarcas marca[], int tamMarca);
/** \brief Load the description in the id for show.
 *
 * \param id int
 * \param marca[] eMarcas
 * \param tamMarca int
 * \param desc[] char
 * \return int  Returns [0] if there was an ERROR - [1] All OK.
 */
int showDescriptionBrand(int id, eMarcas marca[], int tamMarca, char desc[]);
