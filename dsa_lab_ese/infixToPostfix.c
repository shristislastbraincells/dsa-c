// infix_to_postfix.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// simple char stack
typedef struct {
    int top;
    char arr[MAX];
} CharStack;

CharStack* createStack() {
    CharStack* s = (CharStack*)malloc(sizeof(CharStack));
    s->top = -1;
    return s;
}
int isEmpty(CharStack* s){ return s->top == -1; }
void push(CharStack* s, char c){ if (s->top < MAX-1) s->arr[++s->top] = c; }
char pop(CharStack* s){ return isEmpty(s) ? '\0' : s->arr[s->top--]; }
char peek(CharStack* s){ return isEmpty(s) ? '\0' : s->arr[s->top]; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

void infixToPostfix(char infix[], char postfix[]) {
    CharStack *st = createStack();
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If operand → directly add to output
        if (isalnum(c)) {
            postfix[k++] = c;
        }

        // If '(' → push
        else if (c == '(') {
            push(st, c);
        }

        // If ')' → pop until '('
        else if (c == ')') {
            while (!isEmpty(st) && peek(st) != '(')
                postfix[k++] = pop(st);

            pop(st); // remove '('
        }

        // Operator
        else {
            while (!isEmpty(st) &&
                   precedence(peek(st)) >= precedence(c) &&
                   peek(st) != '(') {
                postfix[k++] = pop(st);
            }
            push(st, c);
        }
    }

    // Pop remaining stack
    while (!isEmpty(st)) {
        postfix[k++] = pop(st);
    }

    postfix[k] = '\0';
    free(st);
}


int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression (no spaces): ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
