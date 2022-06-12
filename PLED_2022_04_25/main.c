

/**
 * main.c
 */
#include "lib/include.h"

int main(void)
{
    Configurar_GPIO_M();
    GPIOM_ISR();
	while(1U){}
}
