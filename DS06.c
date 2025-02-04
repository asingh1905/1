//single linked
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to traverse the linked list
void traverseList(struct Node *head) {
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Insert at the beginning
struct Node *insertAtBeginning(struct Node *head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Insert at the end
void insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode->data = data;
    newNode->next = NULL;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete from the beginning
struct Node *deleteFromBeginning(struct Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete from the end
void deleteFromEnd(struct Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

// Insert at any position
void insertAtPosition(struct Node *head, int index, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    int i = 0;

    while (i != index - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from any position
void deleteFromPosition(struct Node *head, int index) {
    struct Node *temp = head;
    struct Node *prev = NULL;
    int i = 0;

    while (i != index && temp->next != NULL) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    free(temp);
}

// Main function
int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;
    second->data = 15;
    second->next = third;
    third->data = 20;
    third->next = NULL;

    printf("Initial List:\n");
    traverseList(head);

    head = insertAtBeginning(head, 23);
    printf("After inserting at the beginning:\n");
    traverseList(head);

    insertAtEnd(head, 100);
    printf("After inserting at the end:\n");
    traverseList(head);

    head = deleteFromBeginning(head);
    printf("After deleting from the beginning:\n");
    traverseList(head);

    deleteFromEnd(head);
    printf("After deleting from the end:\n");
    traverseList(head);

    insertAtPosition(head, 2, 22);
    printf("After inserting at position 2:\n");
    traverseList(head);

    deleteFromPosition(head, 1);
    printf("After deleting from position 1:\n");
    traverseList(head);

    return 0;
}
