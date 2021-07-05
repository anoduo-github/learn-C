#include <stdio.h>
#include <stdlib.h>

#define Size 5

//定义顺序表结构体
typedef struct
{
    //动态数组
    int *data;
    //数据长度
    int length;
    //数组大小
    int size;
} Sqlist;

//初始化顺序表
Sqlist InitSqlist()
{
    Sqlist list;
    //分配内存空间
    list.data = (int *)malloc(Size * sizeof(int));
    if (!list.data)
    {
        printf("初始化失败");
        exit(0);
    }
    //初始默认为0
    for (int i = 0; i < Size; i++)
    {
        list.data[i] = 0;
    }
    list.length = 0;
    list.size = Size;
    return list;
}

//插入
void Insert(Sqlist *list, int index, int value)
{
    //判断index是否超过范围
    if (index < 0 || index > list->size - 1)
    {
        printf("超过范围");
        exit(0);
    }
    //判断列表数据是否存满了,满了扩容
    if (list->length == list->size)
    {
        list->data = (int *)realloc(list->data, Size * sizeof(int));
        if (!list->data)
        {
            printf("扩容失败");
            exit(0);
        }
        //增加size
        list->size += Size;
    }
    //执行插入操作
    for (int i = list->size - 2; i >= index; i--)
    {
        list->data[i + 1] = list->data[i];
    }
    list->data[index] = value;
    list->length += 1;
}

//按位置删除
void Delete(Sqlist *list, int index, int *e)
{
    //判断范围
    if (index > list->size - 1 || index < 0)
    {
        printf("超过范围");
        exit(0);
    }
    //执行删除
    (*e) = list->data[index];
    for (int i = index; i < list->size - 2; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    list->length -= 1;
}

//查找指定元素是第几个
int Select(Sqlist *list, int value)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->data[i] == value)
        {
            return i;
        }
    }
    return -1;
}

//输出
void Display(Sqlist list)
{
    for (int i = 0; i < list.size; i++)
    {
        printf("list.data[%d]=%d\n", i, list.data[i]);
    }
}

int main(void)
{
    Sqlist list = InitSqlist();
    //添加值
    for (int i = 0; i < list.size; i++)
    {
        list.data[i] = i;
        list.length++;
    }
    Insert(&list, 3, 44);
    Display(list);
    int e;
    Delete(&list, 6, &e);
    printf("%d\n", e);
    Display(list);
    int index = Select(&list, 2);
    printf("%d\n", index);
    return 0;
}
