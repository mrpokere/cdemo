#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

#define LEN 6

typedef struct Queue
{
    int *pBase;
    int front;
    int rear;
}QUEUE;

void init(QUEUE *pQ);
bool en_que(QUEUE *pQ,int val);
bool full_queue(QUEUE *pQ);
void traverse_queue(QUEUE *pQ);
bool out_queue(QUEUE *pQ,int *pVal);
bool queue_empty(QUEUE *pQ);

int main(void)
{
    QUEUE Q;
    int val;
    init(&Q);

    en_que(&Q,2);
    en_que(&Q,7);
    en_que(&Q,4);
    en_que(&Q,9);
    en_que(&Q,6);
    en_que(&Q,3);
    en_que(&Q,1);
    en_que(&Q,0);

    traverse_queue(&Q);

    if(out_queue(&Q,&val))
    {
        printf("���ӳɹ�,����Ϊ: %d\n",val);
    }
    else
    {
        printf("����Ϊ��,����ʧ��\n");
    }
    traverse_queue(&Q);

    return 0;
}

void init(QUEUE *pQ)
{
    pQ->pBase = (int *)malloc(sizeof(int)*LEN);
    pQ->front = 0;
    pQ->rear = 0;
}

bool en_que(QUEUE *pQ,int val)
{
    if(full_queue(pQ))
    {
        return false;
    }
    else
    {
        pQ->pBase[pQ->rear] = val;
        pQ->rear = (pQ->rear + 1)%LEN;
        return true;
    }
}


bool full_queue(QUEUE *pQ)
{
    if((pQ->rear + 1)%LEN == pQ->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*
void traverse_queue(QUEUE *pQ)
{
    while(pQ->front != pQ->rear)
    {
        printf("%d    ",pQ->pBase[pQ->front]);
        pQ->front = (pQ->front + 1)%LEN;
    }
    printf("\n");
    return;
}
���⣺������c���Ե����ݽṹ��������ʵ�ֶ��еı�������Ϊʲô����ĺ�����������أ�
����ĺ�������ȷ��
�ҷ������˼��鷢��������ȷ�ĺ����ǰ�pQ->front�ñ��������ˣ�
�����ϲ�Ӧ����һ������
*/
void traverse_queue(QUEUE *pQ)
{
    int i = pQ->front;
    while (i != pQ->rear)
    {
        printf("%d    ",pQ->pBase[i]);
        i = (i + 1) % LEN;
    }
    printf("\n");
    return;
}



bool out_queue(QUEUE *pQ,int *pVal)
{
    if(queue_empty(pQ))
    {
        return false;
    }
    else
    {
        *pVal = pQ->pBase[pQ->front];
        pQ->front = (pQ->front + 1) % LEN;
        return true;
    }
}


bool queue_empty(QUEUE *pQ)
{
    if(pQ->front == pQ->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}
