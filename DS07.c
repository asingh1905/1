//d-linked
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to traverse the doubly linked list
void traverseList(struct Node *head) {
    struct Node *ptr = head;
    printf("NULL ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Function to insert a node at any position
struct Node *insertAtPosition(struct Node *head, int position, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (position == 0) { // Insert at the beginning
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }

    struct Node *temp = head;
    for (int i = 0; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to delete a node at any position
struct Node *deleteAtPosition(struct Node *head, int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    struct Node *temp = head;

    if (position == 0) { // Delete the first node
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    for (int i = 0; i < position && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

// Main function to test the doubly linked list
int main() {
    struct Node *head = NULL;

    // Insert elements at different positions
    head = insertAtPosition(head, 0, 10);
    head = insertAtPosition(head, 1, 20);
    head = insertAtPosition(head, 1, 15);
    head = insertAtPosition(head, 3, 25);

    printf("List after insertions:\n");
    traverseList(head);

    // Delete elements at different positions
    head = deleteAtPosition(head, 0);
    printf("List after deleting first element:\n");
    traverseList(head);

    head = deleteAtPosition(head, 1);
    printf("List after deleting element at position 1:\n");
    traverseList(head);

    return 0;
}
