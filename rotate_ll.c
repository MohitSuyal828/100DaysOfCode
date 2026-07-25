// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.
#include <stdio.h>
#include <stdlib.h>

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

// Insert node at end
void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Rotate list to the right by k places
struct Node* rotateRight(struct Node *head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node *tail = head;
    int length = 1;

    // Find length and last node
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    k = k % length;
    if (k == 0)
        return head;

    // Make circular list
    tail->next = head;

    // Move to new tail
    int steps = length - k;
    struct Node *newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    // Set new head
    struct Node *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Print linked list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k, value;
    struct Node *head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}