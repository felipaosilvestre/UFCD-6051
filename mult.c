// Introduzir o numero 1
// Introduzir o numero 2
// Introduzir a operação

#include <stdio.h>

int main()

{
// Introduzir o numero 1
float x = 0.0f;
printf(" Introduza o primeiro numero:      \t");
scanf("%f", &x);

// Introduzir o numero 2

float y = 0.0f;
printf(" Introduza o segundo numero:      \t");
scanf("%f", &y);

// Introduzir a operação

char operador;
printf(" Introduza a operação (+, -, *, /):      \t");
scanf(" %c", &operador);

// Fazer o cálculo

float resultado = 0.0f;

if(operador == '*')
{
   resultado = x * y; 
}


if(operador == '/')
{
 resultado = x / y;   
}



if(operador == '+')
{
resultado = x + y;    
}



if(operador == '-')
{
resultado = x - y;
}



// Demonstrar o resultado

printf("Resultado: %f", resultado);

}