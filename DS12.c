//circ queue linked
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

// Check if the queue is empty
int isEmpty(struct queue *q)
{
    return (q->front == q->rear);
}

// Check if the queue is full
int isFull(struct queue *q)
{
    return ((q->rear + 1) % q->size == q->front);
}

// Enqueue operation
void enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size; // Move rear circularly
        q->arr[q->rear] = data;
        printf("Enqueued: %d\n", data);
    }
}

// Dequeue operation
int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow!\n");
        return -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size; // Move front circularly
        int temp = q->arr[q->front];
        printf("Dequeued: %d\n", temp);
        return temp;
    }
}

// Display the elements of the queue
void display(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is EMPTY!\n");
    }
    else
    {
        printf("Queue elements: ");
        int i = (q->front + 1) % q->size;
        while (i != (q->rear + 1) % q->size)
        {
            printf("%d ", q->arr[i]);
            i = (i + 1) % q->size;
        }
        printf("\n");
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;  // Array size
    q->front = q->rear = 0; // Initialize front and rear
    q->arr = (int *)malloc(q->size * sizeof(int)); // Allocate memory for the queue

    dequeue(q); // Test dequeue on empty queue
    display(q); // Display empty queue

    // Enqueue elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 80);
    enqueue(q, 90);

    display(q); // Display queue

    enqueue(q, 100); // Attempt to enqueue when queue is full

    // Dequeue elements
    dequeue(q);
    dequeue(q);
    dequeue(q);

    display(q); // Display after dequeues

    enqueue(q, 110);
    enqueue(q, 120);

    display(q); // Display final state

    return 0;
}