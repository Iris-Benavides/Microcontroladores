/*
 * LED.c
 *
 *  Created on: 25 abr 2022
 *      Author: Dra_Iris
 */
#include "lib/include.h"
//#include <GPIO.h>

extern void Configurar_GPIO_M(void)
{
    // Operacion con bitwise
                      //   M (pines: 0/1/3/4/5/6/7)
    SYSCTL->RCGCGPIO |= (1<<11);
    while((SYSCTL->PRGPIO & 0x00001000) == 0){;}
    // Salidas (=1)
    GPIOM->DIR |= (1<<1);
    // Entradas (=0)
    GPIOM->DIR |= (0<<0);

    GPIOM->PUR |= (1<<0); //Estado alto (PULL UP=1)

    // Funciones alternativas
    GPIOM->AFSEL|=0x00;
    // Tabla con GPIOCTL
    GPIOM->PCTL|=0x00;
    // Habilitarlos como digitales
    GPIOM->DEN |= (1<<1)| (1<<0);

    // Habilitar interrrupciones
    GPIOM->IM |= (0<<0); // | (0<<1);
    GPIOM->IS |= (0<<0); // | (0<<1);
    GPIOM->IBE |= (0<<0); // | (0<<1);
    GPIOM->IEV |= (1<<0); // | (1<<1);
    GPIOM->RIS |= (0<<0); // | (0<<1);
    GPIOM->IM |= (1<<0); // | (1<<1);

    // GPIOM (#interrupcion) es: 72 (pag.118)
    // Prioridad, 72/4 = 18         (pag.161)
    // [4n+3] [4n+2] [4n+1] [4n]    (pag.161)
    // NIVIC_PRI18 - 75/74/73/72    (pag.161)

    NVIC->IP[18] = (NVIC->IP[18] & 0xFFFFFF00) | (0x00000010);
    NVIC->ISER[2] = 0x200;
    // Table 3-8 pag.  Peripherals Register Map 146

}

extern void GPIOM_ISR(void)
{
    uint32_t i;
    GPIOM->DATA = (1<<1); // Led externo M1 prender
    for (i=0;i<1000000;i++){}
    GPIOM->DATA = (0<<1); // Led externo M1 apagar
    for (i=0;i<1000000;i++){}

}
