#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "prestamo.h"
#include "informes.h"
#include "utn.h"

int inicializarClientes(eCliente clientes[], int tamCliente)
{
	int retorno = 1;

	for(int i=0; i<tamCliente; i++)
		{
			clientes[i].isEmpty = 1;
			retorno = 0;
		}

	return retorno;
}

int imprimirClientes(eCliente clientes[], int tamCliente)
{
	int flag = 0;
	int retorno = 1;

	system("cls");

	printf("-------------- Listado de Clientes ---------------------\n");
	printf("  Id     Cuil       Nombre      Apellido      Estado\n\n");

	for(int i=0; i<tamCliente; i++)
	{
		if(clientes[i].isEmpty == 0)
		{
			imprimirCliente(clientes[i], tamCliente);
			retorno = 0;
			flag = 1;
		}
	}
	if(flag==0)
	{
		printf("\n -- No hay clientes que mostrar --\n");
	}

	return retorno;
}

void imprimirCliente(eCliente cliente, int tamCliente)
{
    printf("%4d  %d  %10s   %10s  %10s\n", cliente.id, cliente.cuil, cliente.nombre, cliente.apellido, cliente.estado);
}

int altaCliente(int idC, eCliente clientes[], int tamCliente)
{
	int retorno = -1;
	int indice = buscarLibreCliente(clientes, tamCliente);
	eCliente auxCliente;

	system("cls");

	printf("-------- Alta Cliente --------\n\n");

	if(indice == -1)
	{
		printf("\n**Sistema completo, no hay lugar disponible**\n");
	}
	else
	{
        auxCliente.id = idC;

        utn_getEntero(&auxCliente.cuil, 2, "Ingrese cuil: ", "\nError", 1000000, 50000000);
        utn_getCadena(auxCliente.nombre, 19, 2, "Ingrese nombre: ", "\nError. ");
        utn_getCadena(auxCliente.apellido, 19, 2, "Ingrese apellido: ", "\nError.");

        strcpy(auxCliente.estado, "activo");

        auxCliente.isEmpty = 0;

        clientes[indice] = auxCliente;
        retorno = indice;
	}

	return retorno;
}

int buscarLibreCliente(eCliente clientes[], int tamCliente)
{
	int indice = -1;

	for(int i=0; i<tamCliente; i++)
	{
		if(clientes[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int bajaCliente(eCliente clientes[], int tamCliente)
{
    int retorno = 1;
	int id;
	int indice;
	char respuesta;

	system("cls");

	printf("-------- Baja Cliente --------\n\n");
	imprimirClientes(clientes, tamCliente);
	utn_getEntero(&id, 2, "Ingrese id del cliente: ", "\nError.", 1, 10);

	indice = buscarCliente(id, clientes, tamCliente);

	if(indice == -1 || strcmp(clientes[indice].estado, "Inhabilitado") == 0)
	{
		printf("\n-- No hay ningun cliente con este id o el cliente ya esta deshabilitado --\n");
	}
	else
	{
		printf("Inhabilitar cliente? (s/n): ");
		fflush(stdin);
		scanf("%c", &respuesta);

		if(respuesta == 's')
		{
			strcpy(clientes[indice].estado, "Inhabilitado");
			printf("Se ha realizado la baja con exito marcando el cliente como 'Inhabilitado'\n");
			retorno = 0;
		}
		else
		{
			printf("Se ha cancelado la operacion\n");
		}
	}
	return retorno;
}

int buscarCliente(int id, eCliente clientes[], int tamCliente)
{
	int indice =-1;
	for(int i=0; i<tamCliente; i++)
	{
		if(clientes[i].id == id && clientes[i].isEmpty == 0)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int menuModificar()
{
	int opcion;
	printf("--- Modificaciones ---\n\n");
	printf("1.Nombre\n2.Apellido\n\n");

	utn_getEntero(&opcion, 3, "Ingrese opcion: ", "\nError.", 1, 3);

	return opcion;
}

int modificarCliente(eCliente clientes[], int tamCliente)
{
    int retorno = 1;
    int idCl;
    system("cls");

    printf("-------- Modificar Cliente --------\n\n");

    imprimirClientes(clientes, tamCliente);
    utn_getEntero(&idCl, 2, "Ingrese id del cliente a modificar: ", "\nError.", 1, 10);

	for(int i=0; i<tamCliente; i++)
	{
		if(clientes[i].id == idCl)
		{
			system("cls");
			switch(menuModificar())
			{
			case 1:
			    utn_getCadena(clientes[i].nombre, 19, 2, "Ingrese nuevo nombre: ", "\nError.");
				break;
			case 2:
			    utn_getCadena(clientes[i].apellido, 19, 2, "Ingrese nuevo apellido: ", "\nError.");
				break;

			case 3:

				break;


			}
			retorno = 0;
		}
	}
    return retorno;
}

int altaPrestamo(int id, eCliente clientes[], int tamCliente, ePrestamo prestamos[], int tamPrestamo)
{
	int retorno = -1;
	int indice = buscarLibrePrestamo(prestamos, tamPrestamo);
	ePrestamo aux;

	system("cls");

	printf("--------Alta Prestamo-------\n\n");

	if(indice == -1)
	{
		printf("\n**Sistema completo, no hay lugar disponible**\n");
	}
	else
	{
        aux.idPrestamo = id;

        imprimirClientes(clientes, tamCliente);

        utn_getEntero(&aux.idCliente, 2, "Ingrese id del cliente: ", "\nError.", 1, 10);

        if(buscarCliente(aux.idCliente, clientes, tamCliente) >= 0)
        {

            utn_getEntero(&aux.importe, 2, "Ingrese importe : ", "\nError.", 1, 20000);
            utn_getEntero(&aux.cantidadCuotas, 2, "Ingrese cantidad de cuotas : ", "\nError.", 1, 12);


            strcpy(aux.estado, "activo");

            aux.isEmpty = 0;

            prestamos[indice] = aux;
            retorno = indice;

        imprimirPrestamos(prestamos,tamPrestamo);


        }
        else
        {
            printf("\n**No hay un cliente con ese id**\n");
        }
	}
	return retorno;
}

int buscarLibrePrestamo(ePrestamo prestamoN[], int tamPrestamo)
{
	int indice =-1;

	for(int i=0; i<tamPrestamo; i++)
	{
		if(prestamoN[i].isEmpty)
		{
			indice = i;
			break;
		}
	}

	return indice;
}


int finalizarPrestamo(eCliente clientes[], int tamCliente, ePrestamo prestamo[], int tamPrestamo)
{
    int flag = 0;
    int retorno = 1;
    int idPrestamo;
    int indicePrestamo;
    char respuesta;

    printf("-------- Finalizar alquiler --------\n\n");
    imprimirPrestamos(prestamo, tamPrestamo);
    utn_getEntero(&idPrestamo, 2, "Ingrese id del prestamo a finalizar: ", "\nError.", 1, 30);

    for(int i=0; i<tamCliente; i++)
	{
		if(prestamo[i].idPrestamo== idPrestamo && (strcmp(prestamo[i].estado, "saldado") == 0))
		{
			flag = 1;
		}
	}

	if(!flag)
    {
        printf("\n**Este prestamo  esta finalizado**\n");
    }
    else
    {

        indicePrestamo = buscarPrestamo(idPrestamo, prestamo, tamPrestamo);

        printf("Confima cambio de estado a 'saldado'? (s/n)\n");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's')
        {

            strcpy(prestamo[indicePrestamo].estado, "Finalizado");
            printf("Se ha realizado el cambio con exito\n");
            retorno = 0;
        }
        else
        {
            printf("Se ha cancelado la operacion\n");
        }
    }
    return retorno;
}

int imprimirPrestamos(ePrestamo prestamos[], int tamPrestamos)
{
	int retorno = 1;

	system("cls");

	printf("-------------- Listado de Prestamos ---------------\n\n");
	printf("Id-Alquiler | Id-Cliente |IMPORTE| CUOTA| Id- Estado  \n\n");

	for(int i=0; i<tamPrestamos; i++)
	{
        if(prestamos[i].isEmpty == 0)
        {
            imprimirPrestamo(prestamos[i], tamPrestamos);
        }
	}

	return retorno;
}

void imprimirPrestamo(ePrestamo prestamos, int tamPrestamos)
{


    printf("%d         %10d          %d         %d          %s      \n", prestamos.idPrestamo, prestamos.idCliente,prestamos.importe,prestamos.cantidadCuotas, prestamos.estado);

}

int inicializarPrestamos(ePrestamo prestamoN[], int tamAlquiler)
{
	int retorno = 1;

	for(int i=0; i<tamAlquiler; i++)
		{
			prestamoN[i].isEmpty = 1;
			retorno = 0;
		}

	return retorno;
}

int buscarPrestamo(int idPrestamo, ePrestamo prestamo[], int tamPrestamo)
{
	int indice =-1;
	for(int i=0; i<tamPrestamo; i++)
	{
		if(prestamo[i].idPrestamo == idPrestamo && prestamo[i].isEmpty == 0)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

