
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
struct Arr
{
    int * pBase; //������������һ��Ԫ�صĵ�ַ
    int len; //�����������ɵ����Ԫ�صĸ���
    int cnt; //��ǰ������ЧԪ�صĸ���
};

void init_arr(struct Arr * pArr,int length);

bool append_arr(struct Arr * pArr,int val);
bool insert_arr(struct Arr * pArr,int pos,int val);
bool delete_arr();
int get();
bool is_full(struct Arr * pArr);
void sort_arr();
void inversion_arr();

void show_arr(struct Arr * pArr);
bool is_empty(struct Arr * pArr);
int main(void)
{
    struct Arr arr;
    init_arr(&arr,6);
    show_arr(&arr);
    append_arr(&arr,2);
    append_arr(&arr,9);
    append_arr(&arr,4);
    append_arr(&arr,8);
    append_arr(&arr,7);
    show_arr(&arr);
    insert_arr(&arr,1,10);
    show_arr(&arr);

    return 0;
}

void init_arr(struct Arr * pArr,int length)
{

    pArr->pBase = (int*)malloc(sizeof(int)*length);
    if (NULL == pArr->pBase)
    {
        printf("��̬�ڴ����ʧ��!\n");
        exit(-1);
    }
    else
    {
        pArr->len = length;
        pArr->cnt = 0;
        printf("��̬�ڴ����ɹ���\n");
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
        printf("����Ϊ��\n");
    }
    else
    {
        for(int i = 0;i<pArr->cnt;i++)
        {
            printf("%d    ",(pArr->pBase)[i]);

        }
    }printf("\n");
}

bool is_full(struct Arr * pArr)
{
    if(pArr->cnt==pArr->len)
        return true;
    else
        return false;
}

bool append_arr(struct Arr * pArr,int val)
{
    if(is_full(pArr))
        return false;//���򷵻�false
    else
    {
        pArr->pBase[pArr->cnt] = val;
        (pArr->cnt)++;
    }
}
bool insert_arr(struct Arr * pArr,int pos,int val)
{
    int i;
    if (is_full(pArr))
        return false;
    if (pos<1 || pos>pArr->cnt+1)
        return false;
    for (i=pArr->cnt-1;i>pos-1;--i)
    {
        pArr->pBase[i+1] = pArr->pBase[i];
    }
    pArr->pBase[pos-1] = val;
    (pArr->cnt)++;
    return true;
}
