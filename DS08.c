//stack array
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(struct stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack Overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}
int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow");
    }
    else
    {
        int data = s->arr[s->top];
        s->top = s->top - 1;
        return data;
    }
}

int display(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("The Stack is EMPTY");
    }
    else
    {
        printf("\nThe Stack is : ");
        for (int i = 0; i < (s->top) + 1; i++)
        {
            printf("%d, ", s->arr[i]);
        }
    }

}

void main()
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    s1->size = 10;
    s1->top = -1;
    s1->arr = (int *)malloc(s1->size * sizeof(int));
    push(s1, 47);
    push(s1, 44);
    push(s1, 42);
    push(s1, 41);
    push(s1, 4560);
    push(s1, 400456);
    push(s1, 40045);
    push(s1, 40054);
    push(s1, 40045);
    push(s1, 40043);
    pop(s1);
    push(s1, 498);
    display(s1);
}