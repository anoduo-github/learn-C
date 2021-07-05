#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    /* int num = 1000;
    printf("num=%d, num=%#o, num=%#x\n", num, num, num); */
    int32_t me32 = 45645664;
    printf("%d\n", me32);
    printf("%" PRId32 "\n", me32);
}