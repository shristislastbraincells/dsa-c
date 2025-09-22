//Infix To Prefix 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define CHAR_ARR_SIZE 50
struct Stack{
    int top;
    unsigned size;
    char *arr;
};
struct Stack* createStack(unsigned size){
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    if(!stack)
        return NULL;
    stack->top=-1;
    stack->size=size;
    stack->arr=(char*)malloc(stack->size * sizeof(char));
    return stack;
}
bool isFull(struct Stack* stack){
    if(stack->top==stack->size-1)
        return true;
    return false;
}
bool isEmpty(struct Stack* stack){
    if(stack->top==-1)
        return true;
    return false;
}
void push(struct Stack* stack,char element){
    if(isFull(stack)){
        printf("Stack Overflow");
    }
    stack->arr[++stack->top]=element;
}
char pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow");
    }
    return stack->arr[stack->top--];
}
char peek(struct Stack* stack){
    return stack->arr[stack->top];
}
bool isAlphanumeric(char ch){
    if((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
        return true;
    return false;
}
bool isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='^'||ch=='$')
        return true;
    return false;
}
int getPrecedence(char op){
    switch(op){
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
        case '%':
                return 2;
        case '^':
        case '$':
                return 3;
    }
    return -1;
}
void toPrefix(struct Stack* stack,char arr[CHAR_ARR_SIZE],char prefix[CHAR_ARR_SIZE]){
    char ch, temp;
    int j = 0, size = strlen(arr);
    for (int i = size - 1; i >= 0; i--)
    {
        ch = arr[i];
        // Ignore spaces
        if (ch == ' ')
            continue;

        // If current element is a character/number, display it to output ie. append it to prefix string
        if (isAlphanumeric(ch))
            prefix[j++] = ch;
        // Directly push '(' into the stack
        else if (ch == ')')
            push(stack, ch);
        else if (ch == '(')
        {
            // Pop all operators till corresponding opening parenthesis is reached or stack is empty
            while (peek(stack) != ')' && !isEmpty(stack))
            {
                ch = pop(stack);
                prefix[j++] = ch;
            }
            pop(stack); // Pop corresponding opening parenthesis
        }
        else if (isOperator(ch))
        {
            // For operators having higher than/equal precedence to current operator,
            // Pop them and display it to output till the condition if false or
            // opening parenthesis is reached or stack is empty
            while (peek(stack) != ')' && !isEmpty(stack) && getPrecedence(ch) < getPrecedence(peek(stack)))
            {
                temp = pop(stack);
                prefix[j++] = temp;
            }
            push(stack, ch);
        }
    }
    // Pop all remaining operators and display it to output
    while (!isEmpty(stack))
    {
        ch = pop(stack);
        prefix[j++] = ch;
    }
    prefix[j] = '\0';
    strrev(prefix);
}
int main(){
    char arr[CHAR_ARR_SIZE],prefix[CHAR_ARR_SIZE];
    printf("Enter prefix expression:");
    fgets(arr,sizeof(arr),stdin);
    struct Stack* stack=createStack(strlen(arr));
    toPrefix(stack,arr,prefix);
    printf("\nInfix Expression:   %s", arr);
    printf("Prefix Expression: %s\n", prefix);
    free(stack->arr);
    free(stack);
    return 0;
}