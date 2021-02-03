#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
 
static uint32_t table[256];
 
 
//bit-rev
static uint32_t bitrev(uint32_t input, int bw)
{
    int i;
    uint32_t var;
    var = 0;
    for(i=0; i<bw; i++)
    {
        if(input & 0x01)
        {
            var |= 1<<(bw - 1 - i);
        }
        input >>= 1;
    }
    return var;
}
 
 
//CRC32 table initial
void crc32_init(uint32_t poly)
{
    int i;
    int j;
    uint32_t c;
 
 
    poly = bitrev(poly, 32);

    //uint32_t remainder;
    //uint8_t b = 0;
    //do {
    //    // Start with the data byte
    //    remainder = b;
    //    for (uint32_t bit = 8; bit > 0; --bit) {
    //        if (remainder & 1)
    //            remainder = (remainder >> 1) ^ poly;
    //        else
    //            remainder = (remainder >> 1);
    //    }
    //    table[(size_t)b] = remainder;
    //} while(0 != ++b);

    for(i=0; i<256; i++)
    {
        c = i;
        for (j=0; j<8; j++)
        {
            c = (c & 1) ? (poly ^ (c >> 1)) : (c >> 1);
        }
        table[i] = c;
    }
}
 
 
//Calculate CRC
uint32_t crc32(uint32_t crc, uint32_t *input, int len)
{
    int i;
    uint8_t index;
    uint8_t *p;
    p = (uint8_t*)input;
    for(i=0; i<len; i++)
    {
        index = *p ^ (crc &0xFF);
        crc = (crc >> 8) ^ table[index];
        p++;
    }
    return crc;
}
 
 
//Testcase
int main()
{
    uint32_t crc;
    uint32_t in = 0x0;
    crc32_init(0x04C11DB7);
    crc = crc32(0xFFFFFFFF, &in, 4);
    printf("reversed num = 0x%08X\n", bitrev(0x04C11DB7,32));
    printf("CRC32 = 0x%08X\n", crc ^ 0xFFFFFFFF);
    system("pause");
}