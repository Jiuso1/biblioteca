/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "GestorBiblioteca.h"

int *
conexion_1_svc(char *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	printf("Server: new client connected\n");

	return &result;
}

bool_t *
desconexion_1_svc(int *argp, struct svc_req *rqstp)
{
	static bool_t  result;

	/*
	 * insert server code here
	 */

	printf("Server: client disconnected\n");

	return &result;
}

int *
cargardatos_1_svc(TConsulta *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

bool_t *
guardardatos_1_svc(int *argp, struct svc_req *rqstp)
{
	static bool_t  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
nuevolibro_1_svc(TNuevo *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
comprar_1_svc(TComRet *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
retirar_1_svc(TComRet *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

bool_t *
ordenar_1_svc(TOrdenacion *argp, struct svc_req *rqstp)
{
	static bool_t  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
nlibros_1_svc(int *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
buscar_1_svc(TConsulta *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

TLibro *
descargar_1_svc(TPosicion *argp, struct svc_req *rqstp)
{
	static TLibro  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
prestar_1_svc(TPosicion *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
devolver_1_svc(TPosicion *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}
