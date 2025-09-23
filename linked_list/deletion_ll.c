#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *temp, *newnode;

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
        printf("\n--- DELETION MENU ---\n");
        printf("1. Deletion at Beginning\n");
        printf("2. Deletion at End\n");
        printf("3. Deletion at Any Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                delete_beg();
                display();
                break;
            case 2:
                delete_end();
                display();
                break;
            case 3:
                delete_anypos();
                display();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice!\n");
        }
    }
    return 0;
}
