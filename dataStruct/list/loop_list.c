#include <stdio.h>
#include <stdlib.h>

//循环单链表
typedef struct loop_list
{
    int data;
    struct loop_list *next;
} LoopSingleList;

//初始化循环单链表
LoopSingleList *InitLoopSingleList(int value)
{
    LoopSingleList *list;
    list = (LoopSingleList *)malloc(sizeof(LoopSingleList));
    if (!list)
    {
        printf("分配内存错误");
        exit(0);
    }
    list->data = value;
    list->next = list;
    return list;
}

//输出链表
void Display(LoopSingleList *list)
{
    if (!list)
    {
        printf("链表为空");
        exit(0);
    }
    LoopSingleList *temp;
    LoopSingleList *head;
    head = list;
    temp = list;
    while (1)
    {
        printf("list.data=%d\n", temp->data);
        temp = temp->next;
        if (temp == head)
        {
            break;
        }
    }
}

int main(void)
{
    LoopSingleList *list = InitLoopSingleList(7);
    Display(list);
}