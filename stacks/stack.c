#include<stdio.h>
#include<stdlib.h>
#define MAX 5
//structure to define stack 
struct Stack{
    int top;
    int arr[MAX];
};
//function to create stack 
struct Stack* createStack(){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if(!stack){
        return NULL;
    }
    stack->top=-1;
    // if(!stack->arr){
    //     free(stack);
    //     return NULL;
    // }
    return stack;
}
//function to check if stack is full
int isFull(struct Stack* stack){
    return stack->top==MAX-1;
}
//function to check if stack is empty 
int isEmpty(struct Stack* stack){
    return stack->top==-1;
}
//function to push data into stack 
void push(struct Stack* stack,int data){
    if(isFull(stack)){
        printf("Stack Overflow");
        return;
    }
    stack->arr[++stack->top]=data;
    printf("%d pushed onto stack",data);
}
//function to pop data from stack 
int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow");
        return -1;
    }
    return stack->arr[stack->top--];
}
//function to peek into stack 
int peek(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow");
        return -1;
    }
    return stack->arr[stack->top];
}
//function to free stack 
void freeStack(struct Stack* stack){
    if(stack){
        free(stack->arr);
        free(stack);
    }
}
//main function
int main(){
    struct Stack* stack=createStack();
    if(!stack){
        printf("Failed to create stack");
        return 1;
    }
    int choice,val;
    do{
        printf("\nStack Operations:");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peep");
        printf("\n4.isFull");
        printf("\n5.isEmpty");
        printf("\n6.Exit    ");
        printf("\nEnter choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("enter value to push:");
            scanf("%d",&val);
            push(stack,val);
            break;

            case 2:
            val=pop(stack);
            printf("%d popped",val);
            break;

            case 3:
            val=peek(stack);
            printf("Top element is:%d",val);
            break;

            case 4:
            if(isFull(stack))
                printf("Stack is Full");
            else    
                printf("Stack is not Full");
            break;

            case 5:
            if(isEmpty(stack))
                printf("Stack is empty");
            else    
                printf("Stack is not empty");
            break;

            case 6:
            printf("Exiting program");
            break;

        }
    }while(choice!=6);
    freeStack(stack);
    return 0;
}