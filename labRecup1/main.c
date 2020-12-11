
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prestamo.h"
#include "utn.h"

#define TAM_CLIENTE 5
#define TAM_PRESTAMO 30


int menu();

int main()
{
    int seguir = 0;
    int seguir2 = 0;
	int idClientes = 1;
	int idPrestamo = 1;
	int flag = 0;
	int flag2 = 0;
	char aux;

	eCliente clientes[TAM_CLIENTE];
	ePrestamo prestamosN[TAM_PRESTAMO];


	inicializarClientes(clientes, TAM_CLIENTE);
	inicializarPrestamos(prestamosN, TAM_PRESTAMO);

    do
	{
		switch(menu())
		{
		case 1:
            if(!(altaCliente(idClientes, clientes, TAM_CLIENTE)))
			{
				idClientes++;
				printf("alta exitosa!\n");
				flag = 1;
			}
			break;

		case 2:
            if(flag)
            {
                modificarCliente(clientes, TAM_CLIENTE);
                printf("modificacion exitosa!\n");
            }
            else
            {
                printf("\n-- Debe dar de alta un cliente primero --\n");
            }
			break;

		case 3:
            if(flag)
            {
                bajaCliente(clientes, TAM_CLIENTE);
            }
            else
            {
                printf("\n-- Debe dar de alta un cliente primero --\n");
            }
			break;

		case 4:
            if(flag)
            {
                if(!altaPrestamo(idPrestamo, clientes, TAM_CLIENTE, prestamosN, TAM_PRESTAMO))
                {
                    idPrestamo++;
                    flag2 = 1;
                }
            }
            else
            {
                printf("\n-- Debe dar de alta un cliente primero --\n");
            }
			break;

		case 5:
            if(flag2)
            {
                finalizarPrestamo(clientes, TAM_CLIENTE, prestamosN, TAM_PRESTAMO);
            }
            else
            {
                printf("\n-- Debe dar de alta un prestamo primero --\n");
            }
			break;



        case 7:
            if(flag)
            {
                imprimirClientes(clientes,TAM_CLIENTE);
            }
            else
            {
                printf("\n-- Debe dar de alta un cliente primero --\n");
            }
			break;



        case 8:
               if(flag2)
            {

                imprimirPrestamos( prestamosN, TAM_PRESTAMO);

            }
            else
            {
                printf("\n-- Debe dar de alta un cliente primero --\n");
            }
			break;



		case 9:
		    if(flag2)
            {
                do
                {
                    switch(menuInformes())
                    {
                        case 1:
                            imprimirClientesPrestamo(clientes, TAM_CLIENTE, prestamosN, TAM_PRESTAMO);
                            break;


                        case 2:
                            informarClienteMasPrestamos(clientes, TAM_CLIENTE, prestamosN, TAM_PRESTAMO);
                            break;
                        case 3:
                            seguir2 = 1;
                            break;
                    }
                    system("pause");
                }while(seguir2 == 0);
            }
            else
            {
                printf("\n-- Debe dar de alta un alquiler primero --\n");
            }
			break;

		case 10:
            printf("Desea salir???\n");
                fflush(stdin);
                scanf("%c", &aux);
                while(aux != 's' && aux != 'n')
                    {
                        printf("Opcion incorrecta. Reingrese 's'(si) o 'n'(no)");
                        printf(" s/n : \n");
                        fflush(stdin);
                        scanf("%c", &aux);
                    }

                if(aux == 's')
                    {
                        printf("Gracias. Vuelva pronto!!!\n");
                        return 0;
                    }
                break;
			}
			system("pause");
		}while(seguir == 0);

    return 0;
}

int menu()
{
	system("cls");
	int opcion;

	printf("-------- MENU --------\n");
	printf("1) Alta cliente\n");
	printf("2) Modificar cliente\n");
	printf("3) Baja cliente\n");
	printf("4) Prestamo  nuevo\n");
	printf("5) Saldar prestamo\n");
    printf("7) Imprimir  cliente\n");
    printf("8) Imprimir  prestamo\n");
	printf("9) Informe\n");
	printf("10) Salir\n");

	utn_getEntero(&opcion, 2, "\nIngrese una opcion : ", "\nError.\n", 1, 7);

	return opcion;
}

