

/**
 * main.c
 */
#include <stdint.h> //Libreria de enteros
//ptr = (uint32_t *)0x400FE608U; // Para apuntar, SYSCTL_RCGGPIO_R
 //U =siempre positiva
int main(void)
{
    int *a,b;
    b=3;
    a = &b; // Direccion de memoria de b

    // Modifica a, se modifica b, porque estan vinculados
    // a = 5, no se puede hacer porque a es una direccion de memoria, no a un valor

    //*(ptr) = 0x1000; // Habilita el PORTN
    *((uint32_t *)0x400FE608U) = 0x1000; // Habilita el PORTN

	while(1U) // Para obtimizacion altos (memoria de programa)
	{

	}
}
