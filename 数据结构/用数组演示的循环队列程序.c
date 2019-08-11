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
        printf("出队成功,内容为: %d\n",val);
    }
    else
    {
        printf("队列为空,出队失败\n");
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
问题：请问在c语言的数据结构的用数组实现队列的遍历操作为什么上面的函数会问题的呢，
下面的函数是正确的
我反复看了几遍发现下面正确的函数是把pQ->front用变量代表了，
本质上不应该是一样的吗
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
