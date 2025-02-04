    //queue linked
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
        newNode->next = NULL;

        if (q->rear == NULL) 
        {
            q->front = q->rear = newNode;
        }
        else
        {
            q->rear->next = newNode;
            q->rear = newNode;
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
        q->front = q->front->next;

        if (q->front == NULL) 
        {
            q->rear = NULL;
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
        while (temp != NULL)
        {
            printf("%d, ", temp->data);
            temp = temp->next;
        }
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
