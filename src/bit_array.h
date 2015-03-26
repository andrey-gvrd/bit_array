/*
    This library allows to save an array of binary values in the most efficient way possible
    using macros on a conventional array of a known type.

    Use the array type appropriate for your system for optimal performace, or use
    a byte-sized type for minimising wasted space.

    Andrey Goverdovsky, 2015
*/

#ifndef __BIT_ARRAY_H__
#define __BIT_ARRAY_H__

/* Size of chosen array type in bits */
#define WRD_SZ 32

/* Number of bytes needed to store 'bit_count' bits via binary array of type with the size 'WRD_SZ' */
#define BYTE_SIZE(bit_count) \
    (((bit_count) / WRD_SZ) + (((bit_count) % WRD_SZ) ? 1 : 0))

/* Get bit number 'bit_number' from exisiting binary array */
#define GET_BIT(array, bit_number) \
    ((array[((bit_number) / WRD_SZ)] >> (WRD_SZ - (bit_number) - 1)) & 0x01)

/* Set bit to '1' if condition is true, otherwise set to '0' */
#define SET_BIT_COND(array, bit_number, condition)      \
    do {                                                \
        if (condition) SET_BIT_HIGH(array, bit_number); \
        else           SET_BIT_LOW(array, bit_number);  \
    } while (0)

/* Set bit number 'bit_number' of an exisiting binary array to '1' */
#define SET_BIT_HIGH(array, bit_number) \
    array[((bit_number) / WRD_SZ)] |= (0x01 << (WRD_SZ - (bit_number % WRD_SZ) - 1))

/* Set bit number 'bit_number' of an exisiting binary array to '0' */
#define SET_BIT_LOW(array, bit_number) \
    array[((bit_number) / WRD_SZ)] &= (0x01 << (WRD_SZ - (bit_number % WRD_SZ) - 1))

#endif // __BIT_ARRAY_H__
