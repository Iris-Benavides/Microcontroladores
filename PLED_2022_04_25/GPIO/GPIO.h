/*
 * GPIO.h
 *
 *  Created on: Oct 10, 2021
 *      Author: Dell E6430
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

typedef union
{
    struct
    {
        uint32_t   DATA_R [256];
        uint32_t    DIR_R;
        uint32_t     IS_R;
        uint32_t    IBE_R;
        uint32_t    IEV_R;
        uint32_t     IM_R;
        uint32_t    RIS_R;
        uint32_t    MIS_R;
        uint32_t    ICR_R;
        uint32_t AFSEL_R [56];
        uint32_t   DR2R_R;
        uint32_t   DR4R_R;
        uint32_t   DR8R_R;
        uint32_t    ODR_R;
        uint32_t    PUR_R;
        uint32_t    PDR_R;
        uint32_t    SLR_R;
        uint32_t    DEN_R;
        uint32_t   LOCK_R;
        uint32_t     CR_R;
        uint32_t  AMSEL_R;
        uint32_t   PCTL_R;
    }GPIO; //etiquetamos para poder crear un objeto
}REG_;

extern void Configurar_GPIO_M(void);//prototipo de fucion //no me regresa nada void es vacio
extern void GPIOM_ISR(void);

// extern void NVIC_GPIO_Init(void);
// extern void habilitar_IntGPIO(void);

#endif /* GPIO_GPIO_H_ */
