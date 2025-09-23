//CREATING A LINKED LIST (SINGLE NODE)
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;  
};
struct node *newnode,*head=NULL;
int main(){
    newnode=(struct node*)malloc(sizeof(struct node));
    int num;
    printf("enter data");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=NULL;

    head=newnode;

    printf("Linked List:");
    while(newnode!=NULL){
        printf("%d->",newnode->data);
        newnode=newnode->next;
    }
    return 0;
}

