#include "calculadora.h"


void
calculadora_prog_1(char *host,float i, float j)
{
	CLIENT *clnt;
	float  *result_1;
	valores  suma_1_arg;
	valores  resta_1_arg;
	valores  multiplicacion_1_arg;
	valores  division_1_arg;
	int menuop;
	suma_1_arg.i=i;
	suma_1_arg.j=j;
	resta_1_arg.i=i;
	resta_1_arg.j=j;
	multiplicacion_1_arg.i=i;
	multiplicacion_1_arg.j=j;
	division_1_arg.i=i;
	division_1_arg.j=j;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA_PROG, CALCULADORA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	//Proponemos el menu
	do{
		
		printf("1.-SUMA\n");
		printf("2.-RESTA\n");
		printf("3.-MULTIPLICACION\n");
		printf("4.-DIVISION\n");
		printf("5.-SALIR\n");
		printf("Elige el numero:");
		scanf("%d",&menuop);
		switch (menuop)
		{
			case 1:
				result_1 = suma_1(&suma_1_arg, clnt);
					if (result_1 == (float *) NULL) {
						clnt_perror (clnt, "call failed");
					}
			break;

			case 2:
				result_1 = resta_1(&resta_1_arg, clnt);
					if (result_1 == (float *) NULL) {
						clnt_perror (clnt, "call failed");
					}
			break;

			case 3:
				result_1 = multiplicacion_1(&multiplicacion_1_arg, clnt);
					if (result_1 == (float *) NULL) {
						clnt_perror (clnt, "call failed");
					}
			break;

			case 4:
				result_1 = division_1(&division_1_arg, clnt);
					if (result_1 == (float *) NULL) {
						clnt_perror (clnt, "call failed");
					}
			break;
		}
		printf("\n Operacion Exitosa\n");
		printf("Valor obtenido: %f\n",*result_1);
	}
	while(menuop<5&&menuop>0);


#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}

int
main (int argc, char *argv[])
{
	char *host;
	float i2;
	float j2;
	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	i2=atof(argv[2]);
	j2=atof(argv[3]);
	calculadora_prog_1 (host,i2,j2);
	exit (0);
}
