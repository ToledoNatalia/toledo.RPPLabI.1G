#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED

typedef struct
{
	int id;
	int cuil;
	int isEmpty;
	char nombre[20];
	char apellido[20];
	char estado[20];


}eCliente;


typedef struct
{
    int idPrestamo;
	int idCliente;
    char estado[20];
	int cantidadCuotas;
    int importe;
	int isEmpty;

}ePrestamo;




/** \brief Indica que todas las posiciones en el array estan vacias,
* pone la bandera (isEmpty) en TRUE(1) en todas las posiciones del array.
* \param eCliente clientes[]
* \param int tamCliente
* \return int
*/
int inicializarClientes(eCliente clientes[], int tamCliente);

/** \brief Imprime el array de forma encolumnada.
* \param eCliente clientes[]
* \param int tamCliente
* \return no devuelve nada
*/
int imprimirClientes(eCliente clientes[], int tamCliente);

/** \brief Imprime una posicion del array
* \param eCliente cliente
* \param int tamCliente
* \return no devuelve nada
*/
void imprimirCliente(eCliente cliente, int tamCliente);

/** \brief Agrega un cliente
* \param int idC
* \param eCliente clientes[]
* \param int tamCliente
* \return 1 en caso de error, 0 en caso de exito
*/
int altaCliente(int idC, eCliente clientes[], int tamCliente);

/** \brief Busca una posicion libre
* \param eCliente clientes[]
* \param int tamCliente
* \return devuelve el indice libre o -1 si hay error
*/
int buscarLibreCliente(eCliente clientes[], int tamCliente);

/** \brief Inhabilita un cliente
* \param eCliente clientes[]
* \param int tamCliente
* \return no devuelve nada
*/
int bajaCliente(eCliente clientes[], int tamCliente);

/** \brief Busca un cliente recibiendo como parámetro de búsqueda su Id.
* \param int id
* \param eCliente clientes[]
* \param int tamCliente
* \return devuelve el indice del cliente o -1 si hay error
*/
int buscarCliente(int id, eCliente clientes[], int tamCliente);

/** \brief Imprime el menu de modificaciones
 * \return int opcion
 */
int menuModificar();

/** \brief Modifica nombre o apellido de un cliente
* \param eCliente clientes[]
* \param int tamCliente
* \return int
*/
int modificarCliente(eCliente clientes[], int tamCliente);

/** \brief Busca una posicion libre
* \param ePrestamo prestamos[]
* \param int tamPrestamo
* \return devuelve el indice libre o -1 si hay error
*/
int buscarLibrePrestamo(ePrestamo prestamos[], int tamPrestamos);

/** \brief Agrega un prestamo
* \param int idA
* \param eCliente clientes[]
* \param int tamCliente
* \param ePrestamo prestamos[]
* \param int tamPrestamo
* \return 1 en caso de error, 0 en caso de exito
*/
int altaAlquiler(int idA, eCliente clientes[], int tamCliente, ePrestamo prestamos[], int tamPrestamo);

/** \brief Imprime el array de e de forma encolumnada.
* \param eprestamo prestamo[]
* \param int tamprestamo
* \return no devuelve nada
*/

int imprimirPrestamos(ePrestamo prestamos[], int tamPrestamo);

/** \brief Indica que todas las posiciones en el array estan vacias,
* pone la bandera (isEmpty) en TRUE(1) en todas las posiciones del array.
* \param ePrestamo prestamos[]
* \param int tamPrestamo
* \return int
*/
int inicializarPrestamos(ePrestamo prestamosN[], int tamPrestamo);

/** \brief Imprime una posicion del array
* \param ePrestamo a
* \param int tamPrestamo
* \return no devuelve nada
*/
void imprimirPrestamo(ePrestamo prestamo, int tamPrestamo);

/** \brief Carga la descripcion del tipo de equipo
* \param char descripcion[]
* \param int tamPrestamo
* \return 1 en caso de error, 0 en caso de exito
*/

int buscarPrestamo(int idAlquiler, ePrestamo prestamos[], int tamPrestamo);

/** \brief Finaliza un alquiler
* \param eCliente clientes[]
* \param int tamCliente
* \param ePrestamo prestamos[]
* \param int tamPrestamo
*
* \return int
*/
int finalizarPrestamo(eCliente clientes[], int tamCliente, ePrestamo prestamos[], int tamPrestamo);

/** \brief Imprime el menu de informes
 * \return int opcion
 */
int menuInformes();


/** \brief Imprime todos los clientes con todos sus prestamos
 * \param eCliente clientes[]
 * \param int tamCliente
 * \param ePrestamo prestamos[]
 * \param int tamPrestamo

 * \return int
 */
int imprimirClientesAlquileres(eCliente clientes[], int tamCliente, ePrestamo prestamos[], int tamPrestamo);

/** \brief Informa el cliente con mas prestamos
 * \param eCliente clientes[]
 * \param int tamCliente
 * \param ePrestamo prestamos[]
 * \param int tamPrestamo
 * \return void
 */
void informarClienteMasAlquilados(eCliente clientes[], int tamCliente, ePrestamo prestamos[], int tamPrestamo);

#endif // PRESTAMO_H_INCLUDED
