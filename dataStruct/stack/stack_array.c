#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MaxSize 100

//栈数组
typedef struct stack_array
{
    int data[MaxSize];
    int count;
} StackArray;

//创建一个栈数组
StackArray *CreateStackArray()
{
    StackArray *stack;
    stack = (StackArray *)malloc(sizeof(StackArray));
    if (!stack)
    {
        printf("分配内存失败");
        exit(0);
    }
    memset(stack->data, 0, sizeof(stack->data));
    //memset操作来自于库文件string.h，其表示将整个空间进行初始化
    //不理解可以查阅百度百科https://baike.baidu.com/item/memset/4747579?fr=aladdin
    stack->count = 0;
    return stack;
}

//入栈
int Push(StackArray *stack, int value)
{
    if (!stack)
    {
        printf("栈未创建");
        exit(0);
    }
    stack->data[stack->count] = value;
    stack->count++;
    return 0;
}

//出栈
int Pop(StackArray *stack)
{
    if (!stack)
    {
        printf("栈未创建");
        exit(0);
    }
    if (stack->count == 0)
    {
        printf("栈为空");
        exit(0);
    }
    stack->count--;
    return stack->data[stack->count];
}

//遍历
void Display(StackArray *stack)
{
    if (!stack)
    {
        printf("栈未创建");
        exit(0);
    }
    if (stack->count == 0)
    {
        printf("栈为空");
        exit(0);
    }
    for (int i = 0; i < stack->count; i++)
    {
        printf("data[%d]=%d\n", i, stack->data[i]);
    }
}

int main(void)
{
    StackArray *stack = CreateStackArray();
    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);
    Display(stack);
    int temp = Pop(stack);
    Display(stack);
    printf("pop is %d\n", temp);
}