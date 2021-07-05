#include <stdio.h>
#include <stdlib.h>

//栈节点
typedef struct stack_node
{
    int data;
    struct stack_node *next;
} StackNode;

//链表栈
typedef struct stack_list
{
    int count;
    StackNode *top;
} StackList;

//创建一个stack
StackList *CreateStackList()
{
    StackList *stack;
    stack = (StackList *)malloc(sizeof(StackList));
    if (!stack)
    {
        printf("分配内存空间失败");
        exit(0);
    }
    stack->count = 0;
    stack->top = NULL;
    return stack;
}

//入栈
int Push(StackList *stack, int value)
{
    if (!stack)
    {
        printf("栈未创建");
        exit(0);
    }
    StackNode *node;
    node = (StackNode *)malloc(sizeof(StackNode));
    if (!node)
    {
        printf("分配内存空间失败");
        exit(0);
    }
    node->data = value;
    node->next = stack->top;
    stack->top = node;
    stack->count++;
    return 0;
}

//出栈
int Pop(StackList *stack)
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
    StackNode *temp;
    temp = stack->top;
    stack->top = temp->next;
    stack->count--;
    free(temp);
    return 0;
}

//遍历
void Display(StackList *stack)
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
    StackNode *temp;
    temp = stack->top;
    while (temp->next != NULL)
    {
        printf("stack.data=%d\n", temp->data);
        temp = temp->next;
    }
    printf("stack.data=%d\n", temp->data);
}

int main(void)
{
    StackList *stack = CreateStackList();
    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);
    Display(stack);
    Pop(stack);
    Display(stack);
}