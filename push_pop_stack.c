// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 20 10
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1)
        return; // Stack Overflow
    stack[++top] = value;
}

// Pop operation
void pop() {
    if (top == -1)
        return; // Stack Underflow
    top--;
}

// Display stack from top to bottom
void display() {
    if (top == -1) {
        printf("Stack is Empty");
        return;
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, value;

    scanf("%d", &n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Number of pop operations
    scanf("%d", &m);

    // Perform m pops
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}