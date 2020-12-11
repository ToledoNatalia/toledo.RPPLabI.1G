#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "prestamo.h"
#include "informes.h"
#include "utn.h"








int menuInformes()
{
	int opcion;

	system("cls");

	printf("-------- INFORMES --------\n");
	printf("1) Nombre y apellido del cliente con mas prestamo.\n");
    printf("2) listar cliente mas prestamos.\n");
    printf("3) salir");

	utn_getEntero(&opcion, 2, "\nIngrese una opcion : ", "\nError.\n", 1, 5);

	return opcion;
}


int imprimirClientesPrestamo(eCliente clientes[], int tamCliente, ePrestamo prestamo[], int tamPrestamo)
{
	int flag = 0;
	int retorno = 1;

	system("cls");

	printf("--------- Listado de Clientes con sus Alquileres ----------\n");

	for(int i=0; i<tamCliente; i++)
	{
		if(clientes[i].isEmpty == 0)
		{
		    printf("\n----------------- CLIENTE -----------------\n");
            printf("  Id     Cuil       Nombre      Apellido    Estado  \n\n");

			imprimirCliente(clientes[i], tamCliente);
			retorno = 0;

			printf("----------------- Prestamo -----------------\n");
			printf("Id-prestamo  |  Estado  \n\n");

			for(int a=0; a<tamPrestamo; a++)
            {
                if(prestamo[a].idCliente == clientes[i].id)
                {
                   imprimirPrestamos(prestamo, tamPrestamo);
                    printf("\n----------------------------------------\n");
                    flag = 1;
                }
            }

		}
	}
	if(flag==0)
	{
		printf("\n**No hay prestamo que mostrar**\n");
	}

	return retorno;
}

void informarClienteMasPrestamos(eCliente clientes[], int tamCliente, ePrestamo prestamo[], int tamPrestamo)
{
    int auxMax=-1;
    int flagClientes[5]={0,0,0,0,0};

    for(int i=0;i<tamPrestamo;i++)
    {
        if(prestamo[i].isEmpty == 0)
        {
            if(prestamo[i].idCliente==1)
            {
                flagClientes[0]++;
            }
            if(prestamo[i].idCliente==2)
            {
                flagClientes[1]++;
            }
            if(prestamo[i].idCliente==3)
            {
                flagClientes[2]++;
            }
            if(prestamo[i].idCliente==4)
            {
                flagClientes[3]++;
            }
            if(prestamo[i].idCliente==5)
            {
                flagClientes[4]++;
            }
        }
    }

    for(int i=0;i<5;i++)
    {
        if(flagClientes[i]>auxMax)
        {
            auxMax=flagClientes[i];
        }
    }
    printf("\nEl/los clientes con mas prestamo: ");
    printf("\n\n  Id        Nombre     Cantidad\n");
    for(int i=0;i<5;i++)
    {
        if(flagClientes[i]==auxMax)
        {
            printf("%4d%20s     %d\n", clientes[i].id, clientes[i].nombre, auxMax);
        }
    }
    printf("\n");
}


