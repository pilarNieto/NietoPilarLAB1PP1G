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
 * \param marcas[] eMarcas
 * \param tamMarca int
 * \param quantity int
 * \return int
 *
 */
int harcodearBrand(eMarcas marcas[], int tamMarca, int quantity);
/** \brief Print the one brand passed by parameter on the screen.
 *
 * \param marca eMarcas
 * \return void
 *
 */
void showBrand(eMarcas marca);
/** \brief Print the entire array of Brands passed by parameter on the screen.
 *
 * \param marca[] eMarcas
 * \param tamMarca int
 * \return void
 *
 */
void showBrandS(eMarcas marca[], int tamMarca);
/** \brief Load the Game description.
 *
 * \param id int
 * \param marca[] eMarcas
 * \param tamMarca int
 * \param desc[] char
 * \return int
 *
 */
int showDescriptionBrand(int id, eMarcas marca[], int tamMarca, char desc[]);
