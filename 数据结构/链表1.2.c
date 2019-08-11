
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node,*pnode;

//创建一个链表
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
            head = p1;//给头结点一个地址
            p2 = p1;//把第一个地址拷贝双份
        }
        else
        {
            p2->next = p1;//把新加入的地址安放在前面的节点
            p2 = p1;//新加入的地址变成尾地址
        }
    }
    p2->next = NULL;
    return head;
}
//输出一个链表
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
//删除一个结点,第二个参数就是要删除的数据
void delete_list(pnode head,int val)
{
    pnode p1,p2;
    p1 = head;
    while(p1->data!=val)
    {
        p2 = p1;//把地址存起来
        p1 = p1->next;//把该地址下一地址更新
    }
    p2->next = p1->next;//忽略当前地址
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
