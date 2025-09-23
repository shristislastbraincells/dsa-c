#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;

void insert_beg() {
    int num;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &num);
    newnode->data = num;
    newnode->next = head; // works for both empty & non-empty
    head = newnode;
    /*
    if(head==NULL){
            head=newnode;
            temp_head=head;
        }
        else{
            temp_head->next=newnode;
            temp_head=newnode;
        }
    */
}

void insert_end() {
    int num;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &num);
    newnode->data = num;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode; // attach at end
    }
}

void insert_anypos() {
    int pos, num, i = 1;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &num);
    newnode->data = num;

    if (pos == 1) {  // inserting at head
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_beg() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {   // only one node
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        newnode = temp->next;
        printf("Deleted element: %d\n", newnode->data);
        free(newnode);
        temp->next = NULL;
    }
}

void delete_anypos() {
    int pos, i = 1;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {  // deleting first node
        temp = head;
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }

    temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    newnode = temp->next;
    temp->next = newnode->next;
    printf("Deleted element: %d\n", newnode->data);
    free(newnode);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        printf("Linked List: ");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- INSERTION MENU ---\n");
        printf("1. Insertion at Beginning\n");
        printf("2. Insertion at End\n");
        printf("3. Insertion at Any Position\n");
        printf("4. Deletion at Beginning\n");
        printf("5. Deletion at End\n");
        printf("6. Deletion at Any Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_beg();
                display();
                break;
            case 2:
                insert_end();
                display();
                break;
            case 3:
                insert_anypos();
                display();
                break;
            case 4:
                delete_beg();
                display();
                break;
            case 5:
                delete_end();
                display();
                break;
            case 6:
                delete_anypos();
                display();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Wrong choice!\n");
        }
    }
    return 0;
}