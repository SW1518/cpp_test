#include <stdint.h>
#include <stdio.h>

int main(){
    const uint16_t maskB = (0x00f8);
    const uint16_t maskG = (0x00fc);
    const uint8_t r = 0x2;
    const uint8_t g = 0x4;
    const uint8_t b = 0x6;

    int o1 = r >> 3;
    int o2 = (g & maskG) << 3;
    int o3 = (b & maskB) << 8;

    uint16_t out = (r >> 3) | ((g & maskG)<<3) | ((b & maskB)<<8);
    printf("output value is: 0x%08X",out);

    return 0;
}