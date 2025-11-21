#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    }
}

int pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return 0;  // safety return
}

int evaluatePrefix(char *arr[], int size) {
    Stack stack;
    initStack(&stack);

    // Process from RIGHT → LEFT
    for (int i = size - 1; i >= 0; i--) {
        char *token = arr[i];

        // If token is number → push it
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        }

        // Else operator → pop two values
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);

            if (strcmp(token, "+") == 0)
                push(&stack, val1 + val2);

            else if (strcmp(token, "-") == 0)
                push(&stack, val1 - val2);

            else if (strcmp(token, "*") == 0)
                push(&stack, val1 * val2);

            else if (strcmp(token, "/") == 0)
                push(&stack, val1 / val2);
        }
    }

    return pop(&stack);
}

int main() {
    // Example Prefix: + * 2 3 - 9 4
    char *arr[] = { "+", "*", "2", "3", "-", "9", "4" };

    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Result: %d\n", evaluatePrefix(arr, size));

    return 0;
}
