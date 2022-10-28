/* Archivo calculadora.x
Donde generamos una estructura de datos 
Y despues alistamos las funciones que ocuparemos */

struct valores{ 
	float i;
	float j;
};

program CALCULADORA_PROG{
 version CALCULADORA_VERS{
 float SUMA(valores)=1;
 float RESTA(valores)=2;
 float MULTIPLICACION(valores)=3;
 float DIVISION(valores)=4;
} = 1;
} = 0x31111111;
