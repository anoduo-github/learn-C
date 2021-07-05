/* 
    错误
*/

#include <stdio.h>
#include <stdlib.h>

//定义双链表
typedef struct double_list
{
    int data;
    struct double_list *pre;
    struct double_list *next;
} DoubleList;

//初始化并赋初值
DoubleList *InitDoubleList(int value)
{
    DoubleList *list;
    list = (DoubleList *)malloc(sizeof(DoubleList));
    if (!list)
    {
        printf("分配内存空间失败");
        exit(0);
    }
    list->data = value;
    list->pre = NULL;
    list->next = NULL;
    return list;
}

//输出
void Display(DoubleList *list)
{
    DoubleList *temp;
    while (temp->next != NULL)
    {
        printf("temp.data=%d\n", temp->data);
        temp = temp->next;
    }
    printf("temp.data=%d\n", temp->data);
}

//添加
int Add(DoubleList *list, int value)
{
    DoubleList *temp;
    temp = list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    DoubleList *node;
    node = (DoubleList *)malloc(sizeof(DoubleList));
    if (!node)
    {
        printf("分配内存空间失败");
        exit(0);
    }
    node->data = value;
    node->pre = temp;
    node->next = NULL;
    temp->next = node;
    return 0;
}

//插入
int Insert(DoubleList *list, int index, int value)
{
    DoubleList *temp;
    temp = list;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
        //表示位置超过了双链表最大长度
        if (temp == NULL && i < index - 1)
        {
            return -1;
        }
    }
    DoubleList *node;
    node = (DoubleList *)malloc(sizeof(DoubleList));
    node->data = value;
    node->next = temp->next;
    node->pre = temp;
    temp->next = node;
    return 0;
}

//修改
int Update(DoubleList *list, int index, int value)
{
    DoubleList *temp;
    temp = list;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
        //表示位置超过了双链表最大长度
        if (temp == NULL && i < index - 1)
        {
            return -1;
        }
    }
    temp->data = value;
    return 0;
}

//删除
int Delete(DoubleList *list, int index, int *old)
{
    DoubleList *temp;
    temp = list;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
        //表示位置超过了双链表最大长度
        if (temp == NULL && i < index - 1)
        {
            return -1;
        }
    }
    (*old) = temp->data;
    temp->pre->next = temp->next;
    temp->next->pre = temp->pre;
    free(temp);
    return 0;
}

int main(void)
{
    DoubleList *list;
    list = InitDoubleList(0);
    Add(list, 1);
    Insert(list, 1, 5);
    Insert(list, 2, 6);
    Insert(list, 3, 7);
    /* Add(list, 2);
    Add(list, 3);
    Add(list, 4);
    Add(list, 5);
    Add(list, 6); */
    Display(list);
}
