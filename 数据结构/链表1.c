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
    PNODE pHead = NULL;//等价于struct Node *pHead = NULL;
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
    printf("请输入您需要生成链表节点的个数:len = ");
    scanf("%d";&len);
    for (i=0;i<len;++i)
    {
        printf("请输入第%d个节点的值：",i+1);
        scanf("%d",&val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pNew)
        {
            printf("分配失败，程序终止\n");
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
