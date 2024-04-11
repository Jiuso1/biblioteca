/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "GestorBiblioteca.h"

// Estructuras de datos para la práctica 1.
TLibro *Biblioteca = NULL; // Vector dinámico de libros
int NumLibros = 0;
// Número de libros almacenados en el vector dinámico.
int Tama = 0;
// Tamaño del vector dinámico. El incremento será por bloques de 4 libros.
int IdAdmin = -1;
// Copia del Identificador de Administración enviado al usuario.
Cadena NomFichero = "";
// Copia del nombre del último fichero binario que se ha cargado en memoria.
int CampoOrdenacion = 0;
// Copia del último campo de ordenación realizado.

int *conexion_1_svc(int *argp, struct svc_req *rqstp)
{
	static int result;
	int contrasenha = *argp;

	if (contrasenha != 1234)
	{
		result = -2;
	}
	else if (IdAdmin != -1)
	{ // Si IdAdmin es igual a -1, no hay ningún administrador conectado entonces.
		result = -1;
	}
	else
	{
		// Como todo está correcto, podemos entrar como administradores:
		IdAdmin = 1 + rand() % RAND_MAX;
		result = IdAdmin;
	}

	return &result;
}

bool_t *
desconexion_1_svc(int *argp, struct svc_req *rqstp)
{
	static bool_t result;
	int idAdminCliente = *argp;

	if (IdAdmin != idAdminCliente)
	{
		result = FALSE;
	}
	else
	{
		IdAdmin = -1; // idAdmin pasa a ser -1 porque ya no hay ningún administrador conectado.
		result = TRUE;
	}

	return &result;
}

int *cargardatos_1_svc(TConsulta *argp, struct svc_req *rqstp)
{
	static int result;
	Cadena nombreFichero = "";
	const int idAdminCliente = argp->Ida;
	FILE *ficheroDatos = NULL;
	TLibro libro = {};

	strcpy(nombreFichero, argp->Datos);

	if (IdAdmin != idAdminCliente)
	{
		result = -1;
	}
	else
	{
		ficheroDatos = fopen(nombreFichero, "rb"); // Abrimos el fichero en modo lectura y modo binario.
		if (ficheroDatos == NULL)
		{
			result = 0;
		}
		else
		{
			// El id administrador coincide y además hemos conseguido abrir el fichero.
			fread(&NumLibros, sizeof(NumLibros), 1, ficheroDatos);
			Biblioteca = (TLibro *)malloc(sizeof(TLibro) * NumLibros); // Reservamos memoria a la Biblioteca, justo la necesaria para cargar exactamente el nº de libros del archivo.
			if (Biblioteca == NULL)
			{
				printf("ERROR: no se ha conseguido reservar memoria dinamica para los libros\n");
			}
			else
			{
				fread(Biblioteca, sizeof(libro) * NumLibros, NumLibros, ficheroDatos); // Leemos tantos libros como NumLibros diga. Los guardamos en Biblioteca.
			}
			fclose(ficheroDatos); // Cerramos el fichero.
		}
	}

	return &result;
}

bool_t *
guardardatos_1_svc(int *argp, struct svc_req *rqstp)
{
	static bool_t result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *nuevolibro_1_svc(TNuevo *argp, struct svc_req *rqstp)
{
	static int result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *comprar_1_svc(TComRet *argp, struct svc_req *rqstp)
{
	static int result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *retirar_1_svc(TComRet *argp, struct svc_req *rqstp)
{
	static int result;

	/*
	 * insert server code here
	 */

	return &result;
}

bool_t *
ordenar_1_svc(TOrdenacion *argp, struct svc_req *rqstp)
{
	static bool_t result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *nlibros_1_svc(int *argp, struct svc_req *rqstp)
{
	static int result;

	result = NumLibros; // Solo queremos retornar el número de libros.

	return &result;
}

int *buscar_1_svc(TConsulta *argp, struct svc_req *rqstp)
{
	static int result;

	/*
	 * insert server code here
	 */

	return &result;
}

TLibro *
descargar_1_svc(TPosicion *argp, struct svc_req *rqstp)
{
	static TLibro result;
	const int i = argp->Pos; // Índice del libro pedido.

	result = Biblioteca[i];

	return &result;
}

int *prestar_1_svc(TPosicion *argp, struct svc_req *rqstp)
{
	static int result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *devolver_1_svc(TPosicion *argp, struct svc_req *rqstp)
{
	static int result;

	/*
	 * insert server code here
	 */

	return &result;
}
