// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the circular linked list elements starting from head, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
#include <stdio.h>
#include <stdlib.h>

// Structure for Circular Linked List Node
struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end
void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    struct Node *temp = *head;

    // Move to the last node
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
}

// Traverse circular linked list
void traverse(struct Node *head) {
    if (head == NULL)
        return;

    struct Node *temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n, value;
    struct Node *head = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input node values
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    // Print the circular linked list
    traverse(head);

    return 0;
}