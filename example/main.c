#include "../src/bit_array.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define ARRAY_BIT_SIZE 100

void main(void)
{
    uint32_t bit_count = ARRAY_BIT_SIZE;
    uint32_t byte_count = BYTE_SIZE(bit_count);
    printf("Bit-array takes %d bytes to store %d bits using a %d bit base type.\n", 
        byte_count, bit_count, WRD_SZ);
    printf("\n");

    uint32_t array[BYTE_SIZE(ARRAY_BIT_SIZE)] = {0};

    SET_BIT_HIGH(array, 0);
    SET_BIT_HIGH(array, 31);
    SET_BIT_HIGH(array, 32);
    SET_BIT_HIGH(array, 33);
    SET_BIT_HIGH(array, 37);
    SET_BIT_HIGH(array, 13);

    SET_BIT_HIGH(array, 64);
    SET_BIT_LOW(array, 64);

    SET_BIT_COND(array, 1, true);

    printf("Array:\n");
    for (uint32_t i = 0; i < byte_count; i++)
    {
        printf("%d: 0b", i);
        for (uint32_t j = 0; j < WRD_SZ; j++)
        {
            if (GET_BIT(array, i * WRD_SZ + j)) printf("1");
            else                                printf("0");
        }
        printf(", \t");
        printf("0x%04x\n", array[i]);
    }
}
