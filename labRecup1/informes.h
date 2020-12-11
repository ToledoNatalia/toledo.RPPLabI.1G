#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/** \brief Imprime todos los clientes con todos sus prestamos
 * \param eCliente clientes[]
 * \param int tamCliente
 * \param prestamos
 * \param int tamPrestamos

 * \return int
 */

int imprimirClientesPrestamo(eCliente clientes[], int tamCliente, ePrestamo prestamo[], int tamPrestamo);

/** \brief Informa el cliente con mas equipos alquilados
 * \param eCliente clientes[]
 * \param int tamCliente
 * \param ePrestamos prestamos[]
 * \param int tamPrestamos
 * \return void
 */
void informarClienteMasPrestamos(eCliente clientes[], int tamCliente, ePrestamo prestamo[], int tamPrestamo);


#endif // INFORMES_H_INCLUDED
