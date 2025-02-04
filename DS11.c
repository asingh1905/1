//circ queue array
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(struct Queue *q)
{
    return q->front == NULL;
}

void enqueue(struct Queue *q, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Queue Overflow\n");
        return;
    }
    newNode->data = data;

    if (q->rear == NULL) // If the queue is empty
    {
        q->front = q->rear = newNode;
        newNode->next = newNode; // Point to itself to form a circular link
    }
    else
    {
        newNode->next = q->front; // Point new node to front
        q->rear->next = newNode;  // Update rear's next to new node
        q->rear = newNode;        // Update rear to new node
    }
    printf("Enqueued: %d\n", data);
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node *temp = q->front;
    int data = temp->data;

    if (q->front == q->rear) // Only one node in the queue
    {
        q->front = q->rear = NULL;
    }
    else
    {
        q->front = q->front->next; // Move front to next node
        q->rear->next = q->front;  // Update rear's next to the new front
    }

    free(temp);
    return data;
}

void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("The Queue is EMPTY\n");
        return;
    }

    struct Node *temp = q->front;
    printf("The Queue is: ");
    do
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    } while (temp != q->front); // Stop when we loop back to the front
    printf("\n");
}

int main()
{
    struct Queue *q = createQueue();

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