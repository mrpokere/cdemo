#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *pNext;
}NODE,*PNODE;

void traverse_list(PNODE pHead)
PNODE create_list(void)

int main(void)
{
    PNODE pHead = NULL;//�ȼ���struct Node *pHead = NULL;
    pHead = create_list();
    traverse_list(pHead);

    return 0;
}

PNODE create_list(void)
{
    int len;
    int i;
    int val;

    PNODE pHead = (PNODE)malloc(sizeof())
    printf("����������Ҫ��������ڵ�ĸ���:len = ");
    scanf("%d";&len);
    for (i=0;i<len;++i)
    {
        printf("�������%d���ڵ��ֵ��",i+1);
        scanf("%d",&val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pNew)
        {
            printf("����ʧ�ܣ�������ֹ\n");
            exit(-1);
        }
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;

    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while(NULL!=p)
    {
        printf("%d",p->data);
        p = p->next;
    }
    printf("\n");
    return;
}
