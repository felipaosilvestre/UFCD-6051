#include <stdio.h>

int main ()
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

float resultado = 0.0f;

switch (operador)
{

    case '*':
    resultado = x * y;
    break; 

case '-':
resultado = x - y;
break;

case '+':
resultado = x + y;
break;

case '/':
resultado = x / y;
break;

default:
printf("Operador Inválido");
break;

}

printf("Resultado: %.2f", resultado);

return 0;
}