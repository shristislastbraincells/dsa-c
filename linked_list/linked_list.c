#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
int main(){
    struct node *temp_head,*newnode;
    int n,num;
    printf("enter number of node:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter %d element of linked list:",i+1);
        scanf("%d",&num);
        newnode->data=num;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp_head=head;
        }
        else{
            temp_head->next=newnode;
            temp_head=newnode;
        }
    }
    printf("Linked List:");
    temp_head=head;
    while(temp_head!=NULL){
        printf("%d -> ",temp_head->data);
        temp_head=temp_head->next;
    }
    return 0;
}