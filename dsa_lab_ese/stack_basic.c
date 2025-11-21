#include<stdio.h>
#include<stdlib.h>

#define MAX 5 

struct Stack{
    int top;
    int arr[MAX];
};
struct Stack* createStack(){
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    if(!stack){
        printf("memory allocation failed");
        return NULL;
    }   
    stack->top=-1;
    return stack;
}
int isFull(struct Stack* stack){
    return stack->top==MAX-1;
}
int isEmpty(struct Stack* stack){
    return stack->top==-1;
}
void push(struct Stack* stack,int data){
    if(isFull(stack)){
        printf("Stack Overflow");
        return;
    }
    stack->arr[++stack->top]=data;
    printf("%d pushed onto stack",data);
}
int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow");
        return -1;
    }
    return stack->arr[stack->top--];

}
int peek(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->arr[stack->top];

}
void display(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for(int i=stack->top;i>=0;i--){
        printf("%d\n",stack->arr[i]);
    }
}
void freeStack(struct Stack* stack){
    if(stack){
        free(stack);
    }
}
int main(){
    struct Stack* stack=createStack();
    if(!stack){
        printf("Failed to create stack");
        return 1;
    }
    int choice,value;
    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Stack is Full\n");
        printf("5. Check if Stack is Empty\n");
        printf("6. Exit\n");
        printf("7. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;

            case 2:
                value = pop(stack);
                if (value != -1) {
                    printf("%d popped from stack\n", value);
                }
                break;

            case 3:
                value = peek(stack);
                if (value != -1) {
                    printf("Top element is %d\n", value);
                }
                break;

            case 4:
                if (isFull(stack))
                    printf("Stack is Full\n");
                else
                    printf("Stack is Not Full\n");
                break;

            case 5:
                if (isEmpty(stack))
                    printf("Stack is Empty\n");
                else
                    printf("Stack is Not Empty\n");
                break;

            case 6:
                printf("Exiting program.\n");
                break;
            
            case 7:
                display(stack);
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 6);

    freeStack(stack);

    return 0;
}