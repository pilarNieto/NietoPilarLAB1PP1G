#ifndef COLORS_H_INCLUDED
#define COLORS_H_INCLUDED
typedef struct
{
    int id;
    char nombre[20];

}eColor;

#endif // COLORS_H_INCLUDED
/** \brief load five colors in the array with their parameters
 *
 * \param colores[] eColor
 * \param tamColor int
 * \param quantity int
 * \return int
 *
 */
int harcodearColors(eColor colores[], int tamColor, int quantity);
/** \brief print one color of array passed by parameter on the screen.
 *
 * \param col eColor
 * \return void
 *
 */
void showColor(eColor col);
/** \brief
 *Print the entire array of Clients passed by parameter on the screen.
 * \param colores[] eColor
 * \param tamColor int
 * \return void
 *
 */
void showColorS(eColor colores[], int tamColor);
/** \brief
 *Load color description.
 * \param id int
 * \param color[] eColor
 * \param tamColor int
 * \param desc[] char
 * \return int
 *
 */
int showDescriptionColors(int id, eColor color[], int tamColor, char desc[]);
