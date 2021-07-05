#include <stdio.h>

int main(void)
{
    printf("int is %zd byte\n", sizeof(int));
    printf("long is %zd byte\n", sizeof(long));
    printf("short is %zd byte\n", sizeof(short));
    printf("float is %zd byte\n", sizeof(float));
    printf("double is %zd byte\n", sizeof(double));
    printf("char is %zd byte\n", sizeof(char));
}