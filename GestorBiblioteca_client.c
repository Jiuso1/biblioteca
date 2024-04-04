/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "GestorBiblioteca.h"
#include <unistd.h>
#include <stdio.h>

int menuPrincipal();
int menuAdministracion();

void gestorbiblioteca_1(char *host)
{
	CLIENT *clnt;
	int *result_1;
	int conexion_1_arg;
	bool_t *result_2;
	int desconexion_1_arg;
	int *result_3;
	TConsulta cargardatos_1_arg;
	bool_t *result_4;
	int guardardatos_1_arg;
	int *result_5;
	TNuevo nuevolibro_1_arg;
	int *result_6;
	TComRet comprar_1_arg;
	int *result_7;
	TComRet retirar_1_arg;
	bool_t *result_8;
	TOrdenacion ordenar_1_arg;
	int *result_9;
	int nlibros_1_arg;
	int *result_10;
	TConsulta buscar_1_arg;
	TLibro *result_11;
	TPosicion descargar_1_arg;
	int *result_12;
	TPosicion prestar_1_arg;
	int *result_13;
	TPosicion devolver_1_arg;

#ifndef DEBUG
	clnt = clnt_create(host, GESTORBIBLIOTECA, GESTORBIBLIOTECA_VER, "udp");
	if (clnt == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
#endif /* DEBUG */
	int opcionElegida = menuPrincipal();
	int contrasenha = 0;
	int idAdministrador = 0;
	Cadena nombreFichero = "";

	switch (opcionElegida)
	{
	case 1:
	{
		printf("Por favor inserte la contraseña de Administracion:\n");
		scanf("%d", &contrasenha);
		conexion_1_arg = contrasenha;
		result_1 = conexion_1(&conexion_1_arg, clnt);
		if (result_1 == (int *)NULL)
		{
			clnt_perror(clnt, "call failed");
		}
		else if (*result_1 == -2)
		{
			printf("ERROR: la contrasenha introducida es incorrecta\n");
		}
		else if (*result_1 == -1)
		{
			printf("ERROR: ya hay un administrador logueado\n");
		}
		else
		{
			idAdministrador = *result_1; // Guardamos el id generado por el servidor en el cliente administrador.
			printf("*** Contraseña correcta, puede acceder al menu de Administracion.**\n");
			printf("Introduzca cualquier numero para continuar.....\n");
			int noImporta = 0;
			scanf("%d", &noImporta);
			opcionElegida = menuAdministracion();
			switch (opcionElegida)
			{
			case 0:
			{
				desconexion_1_arg = idAdministrador;
				result_2 = desconexion_1(&desconexion_1_arg, clnt);
				if (result_2 == (bool_t *)NULL)
				{
					clnt_perror(clnt, "call failed");
				}
				else if (*result_2 == FALSE)
				{
					printf("ERROR: el id administrador no coincide con el del servidor\n");
				}
				else if (*result_2 == TRUE)
				{
					printf("Ha cerrado sesion con exito\n");
				}
				break;
			}
			case 1:
			{
				printf("Introduce el nombre del fichero de datos:\n");
				scanf("%s", nombreFichero);
				strcpy(cargardatos_1_arg.Datos, nombreFichero);
				cargardatos_1_arg.Ida = idAdministrador;
				result_3 = cargardatos_1(&cargardatos_1_arg, clnt);
				break;
			}
			case 8:
			{
				// Pendiente el listado de libros.
				break;
			}
			}
		}
		break;
	}
	}
#ifndef DEBUG
	clnt_destroy(clnt);
#endif /* DEBUG */
}

int main(int argc, char *argv[])
{
	char *host;

	if (argc < 2)
	{
		printf("usage: %s server_host\n", argv[0]);
		exit(1);
	}
	host = argv[1];
	gestorbiblioteca_1(host);
	exit(0);
}
int menuPrincipal()
{
	int opcionElegida = 0;
	do
	{
		system("clear");
		printf("GESTOR BIBLIOTECARIO 1.0 (M. PRINCIPAL)\n");
		printf("***************************************\n");
		printf("\t1.- M. Administración\n");
		printf("\t2.- Consulta de libros\n");
		printf("\t3.- Préstamo de libros\n");
		printf("\t4.- Devolución de libros\n");
		printf("\t0.- Salir\n");
		printf("\n");
		printf("  Elige opción:\n");
		scanf("%d", &opcionElegida);
	} while (opcionElegida < 0 || opcionElegida > 4);
	return opcionElegida;
}

int menuAdministracion()
{
	int opcionElegida = 0;
	do
	{
		system("clear");
		printf("GESTOR BIBLIOTECARIO 1.0 (M. ADMINISTRACION)\n");
		printf("********************************************\n");
		printf("\t1.- Cargar datos Biblioteca\n");
		printf("\t2.- Guardar datos Biblioteca\n");
		printf("\t3.- Nuevo libro\n");
		printf("\t4.- Comprar libros\n");
		printf("\t5.- Retirar libros\n");
		printf("\t6.- Ordenar libros\n");
		printf("\t6.- Ordenar libros\n");
		printf("\t7.- Buscar libros\n");
		printf("\t8.- Listar libros\n");
		printf("\t0.- Salir\n");
		printf("  Elige opción:\n");
		scanf("%d", &opcionElegida);
	} while (opcionElegida < 0 || opcionElegida > 8);
	return opcionElegida;
}