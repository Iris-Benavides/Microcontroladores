

/**
 * main.c
 */
#include <stdint.h>

int main(void)
{
    int32_t b;
    int16_t c;
    uint16_t i=0;
    uint32_t a; // 0x20001f4 + 0x400FE608
    b = 45;
    c = -10;
    a = b + c;
    uint32_t valor[80];
    uint32_t *ptr;
    valor[3] = 0xEFFFFFFF;
    ptr = (uint32_t *) 0x2003000; //Espacio de memoria (es apuntador)
    *(ptr +1) = valor[3];
    ptr = &a;
    a = 345;
    ptr = &valor[1];
    while(i < 8)
    {
        valor[i] = 0x0000BEEF;
        *(ptr + i++) = 0xBEEF0000;
    }

	return 0;
}
