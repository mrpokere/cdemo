#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node,*pnode;

void main()
{
    pnode p1,p2,head;
    int i;
    head = NULL;

    for (i=1;i<=5;i++)
    {
        p1 = (pnode)malloc(sizeof(node));
        p1->data = i;
        if(head == NULL)
        {
            head = p1;
            p2 = p1;
        }
        else
        {
            p2->next = p1;
            p2 = p1;
        }
    }
    p2->next = NULL;
    //ɾ����������
    p1 = head;
    while (p1->data!=2)
    {
        p2 = p1;
        p1 = p1->next;
    }
    p2->next = p1->next;
    free(p1);
    //�����������
    pnode p;
    p = head;
    printf("�����ϸ�����Ϊ:\n");
    int k = 0,data;
    while(p!=NULL)
    {
        printf("show %d��  ",++k);
        data = p->data;
        printf("%d\n",data);
        p = p->next;
    }
}
