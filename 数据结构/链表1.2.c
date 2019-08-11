
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node,*pnode;

//����һ������
int create_list()
{
    pnode head,p1,p2;
    int i;
    head = 0;

    for (i=1;i<=5;i++)
    {
        p1 = (pnode)malloc(sizeof(node));
        p1->data = i;
        if(head == 0)
        {
            head = p1;//��ͷ���һ����ַ
            p2 = p1;//�ѵ�һ����ַ����˫��
        }
        else
        {
            p2->next = p1;//���¼���ĵ�ַ������ǰ��Ľڵ�
            p2 = p1;//�¼���ĵ�ַ���β��ַ
        }
    }
    p2->next = NULL;
    return head;
}
//���һ������
void show(pnode head)
{
    pnode p1;
    p1 = head;
    while(p1!=NULL)
    {

        printf(" %d ",p1->data);
        p1 = p1->next;
    }
}
//ɾ��һ�����,�ڶ�����������Ҫɾ��������
void delete_list(pnode head,int val)
{
    pnode p1,p2;
    p1 = head;
    while(p1->data!=val)
    {
        p2 = p1;//�ѵ�ַ������
        p1 = p1->next;//�Ѹõ�ַ��һ��ַ����
    }
    p2->next = p1->next;//���Ե�ǰ��ַ
    free(p1);
}
void main()
{
    int *head;
    head = create_list();
    show(head);
    delete_list(head,3);
    show(head);
}
