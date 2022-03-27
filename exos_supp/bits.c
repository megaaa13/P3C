#include <stdint.h>
#include <stdbool.h>

uint8_t get_3_leftmost_bits(uint32_t x)
{
    uint32_t shifted = x >> 29;
    return (uint8_t)shifted;
}

uint8_t get_4_rightmost_bits(uint32_t x)
{
    uint32_t shifted = 0b1111 & x;
    return (uint8_t)shifted;
}

/*
 * @pre 0<= pos < 64
 */
uint64_t set_bit(uint64_t x, int pos, bool value)
{
    if (value)
    {
        return x | (value << pos);
    }
    else
    {
        return x & ~(1 << pos);
    }
}

uint32_t cycle_bits(uint32_t x, uint8_t n)
{
    return ((x << n % 32) + (x >> (32 - n % 32)));
}

uint8_t nbits(uint32_t n)
{
    uint8_t ret = 0;
    for (; n; n = n >> 1)
    {
        if (n & 1)
        {
            ret++;
        }
    }
    return ret;
}

uint32_t reset_highestorder_strong_bit(uint32_t x)
{
    for (short i = 31; i >= 0; i--)
    {
        if (x >> i)
            return x - (1 << i);
    }
    return x;
}