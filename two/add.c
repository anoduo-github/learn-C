#include <stdio.h>

int main(void)
{
    printf("please input a number:\n");
    printf("input q is exit\n");
    int num, status;
    long res = 0L;
    status = scanf("%d", &num);
    while (status == 1)
    {
        res += (long)num;
        printf("please input a number:");
        status = scanf("%d", &num);
    }
    printf("finally res is %ld\n", res);
    return 0;
}