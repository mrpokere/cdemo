
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
struct Arr
{
    int * pBase; //储存的是数组第一个元素的地址
    int len; //数组所能容纳的最大元素的个数
    int cnt; //当前数组有效元素的个数
};

void init_arr(struct Arr * pArr,int length);

bool append_arr();
bool insert_arr();
bool delete_arr();
int get();
bool is_full();
void sort_arr();
void inversion_arr();

void show_arr(struct Arr * pArr);
bool is_empty(struct Arr * pArr);
int main(void)
{
    struct Arr arr;
    init_arr(&arr,6);
    show_arr(&arr);
    return 0;
}

void init_arr(struct Arr * pArr,int length)
{

    pArr->pBase = (int*)malloc(sizeof(int)*length);
    if (NULL == pArr->pBase)
    {
        printf("动态内存分配失败!\n");
        exit(-1);
    }
    else
    {
        pArr->len = length;
        pArr->cnt = 0;
        printf("动态内存分配成功！\n");
    }
    return;
}

bool is_empty(struct Arr * pArr)
{
    if (0 == pArr->cnt)
        return true;
    else
        return false;
}

void show_arr(struct Arr * pArr)
{
    if (is_empty(pArr))
    {
        printf("数组为空");
    }
    else
    {
        for(int i = 0;i<pArr->cnt;i++)
        {
            printf("%d",(pArr->pBase)[i]);
        }
    }
}

