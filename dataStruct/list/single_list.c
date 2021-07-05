#include <stdlib.h>
#include <stdio.h>

//定义单链表
typedef struct Node
{
    int data;
    struct Node *next;
} SingleNode;

//初始化
SingleNode *InitSingleNode()
{
    SingleNode *node;
    node = (SingleNode *)malloc(sizeof(SingleNode));
    node->next = NULL;
    return node;
}

//添加值(尾插法)
int Add(SingleNode *node, int value)
{
    SingleNode *temp;
    temp = node;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    SingleNode *temp2;
    temp2 = (SingleNode *)malloc(sizeof(SingleNode));
    temp2->data = value;
    temp2->next = NULL;
    temp->next = temp2;
    return 0;
}

//插入
int Insert(SingleNode *node, int index, int value)
{
    if (index < 0)
    {
        return -1;
    }
    //上一个
    SingleNode *pre = node;
    //计数
    int count = 0;
    for (int i = 0; i < index; i++)
    {
        pre = pre->next;
        count++;
        if (pre == NULL && count != index)
        {
            //表示index超过了链表长度
            return -1;
        }
    }
    SingleNode *temp;
    temp = (SingleNode *)malloc(sizeof(SingleNode));
    temp->data = value;
    temp->next = pre->next;
    pre->next = temp;
    return 0;
}

//修改
int Update(SingleNode *node, int old, int new)
{
    //定义临时指针
    SingleNode *temp;
    temp = node;
    while (temp->next != NULL)
    {
        if (temp->data == old)
        {
            //赋值
            temp->data = new;
            return 0;
        }
        else
        {
            temp = temp->next;
        }
    }
    return -1;
}

//删除指定值
int DeleteByValue(SingleNode *node, int value)
{
    SingleNode *temp = node;
    SingleNode *p;
    while (temp->next != NULL)
    {
        //当当前节点的下一个节点的值等于被删值时
        if (temp->next->data == value)
        {
            //获取这个节点
            p = temp->next;
            //让当前节点指向下下个节点
            temp->next = temp->next->next;
            //释放这个节点
            free(p);
            return 0;
        }
    }
    return -1;
}

//输出
void Display(SingleNode *node)
{
    SingleNode *temp = node->next;
    if (temp == NULL)
    {
        printf("链表没有节点");
        return;
    }
    while (temp->next != NULL)
    {
        printf("temp->data=%d\n", temp->data);
        temp = temp->next;
    }
    printf("temp->data=%d\n", temp->data);
}

int main()
{
    SingleNode *node = InitSingleNode();
    Add(node, 1);
    Add(node, 2);
    Add(node, 3);
    Insert(node, 2, 9);
    Update(node, 2, 5);
    Display(node);
    DeleteByValue(node, 1);
    Display(node);
}