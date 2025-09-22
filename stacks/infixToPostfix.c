//Infix to Postffix 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define CHAR_ARR_SIZE 50

typedef struct Stack{
    int top;
    unsigned size;
    char *arr;
};
struct Stack* createStack(unsigned size){
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->top=-1;
    stack->size=size;
    stack->arr = (char*)malloc(stack->size * sizeof(char));
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
void toPostfix(struct Stack* stack, char arr[CHAR_ARR_SIZE],char postfix[CHAR_ARR_SIZE]){
    char ch,temp;
    int j=0,size=strlen(arr);
    for(int i=0;i<size;i++){
        ch=arr[i];

        if(ch==' ')
            continue;
        
        if(isAlphanumeric(ch)){
            postfix[j++]=ch;
        }
        else if(ch=='('){
            push(stack,ch);
        }
        else if(ch==')'){
            while(!isEmpty(stack)&&peek(stack)!='('){
                postfix[j++]=pop(stack);
            }
            pop(stack);
        }
        else if(isOperator(ch)){
            while(!isEmpty(stack)&&peek(stack)!='('&&getPrecedence(ch)<=getPrecedence(peek(stack))){
                temp=pop(stack);
                postfix[j++]=temp;
            }
            push(stack,ch);
        }
    }
    while(!isEmpty(stack)){
        postfix[j++]=pop(stack);
    }
    postfix[j]='\0';
}
int main(){
    char arr[CHAR_ARR_SIZE],postfix[CHAR_ARR_SIZE];
    printf("Enter infix expression:");
    fgets(arr,sizeof(arr),stdin);
    struct Stack* stack=createStack(strlen(arr));
    toPostfix(stack,arr,postfix);
    printf("\nInfix Expression:   %s", arr);
    printf("Postfix Expression: %s\n", postfix);
    free(stack->arr);
    free(stack);
    return 0;
}
