//queue array
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

int isFull(struct Queue *q)
{
    return q->rear == q->size - 1;
}

void enqueue(struct Queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = data;
        printf("Enqueued: %d\n", data);
    }
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        q->front++;
        int data = q->arr[q->front];
        return data;
    }
}

void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("The Queue is EMPTY\n");
    }
    else
    {
        printf("The Queue is: ");
        for (int i = q->front + 1; i <= q->rear; i++)
        {
            printf("%d, ", q->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 10;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    display(q);

    enqueue(q, 60);
    enqueue(q, 70);

    display(q);

    return 0;
}
