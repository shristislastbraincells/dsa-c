//1.Insert after a given position
//2.Insert at end
//3.Sort the list
//4.Concatenate two lists
//5.Display
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

// Create new node
Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

// Insert at end
void insertEnd(Node** head, int data) {
    Node* n = createNode(data);

    if (*head == NULL) {
        *head = n;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

// Insert after given position
void insertAfterPosition(Node** head, int pos, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    Node* n = createNode(data);
    
    n->next = temp->next;
    n->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;
}

// Display list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Sort list (ascending)
void sortList(Node** head) {
    if (*head == NULL) return;

    Node* i;
    Node* j;

    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Concatenate two doubly linked lists
Node* concatenate(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    head2->prev = temp;

    return head1;
}

// Main driver
int main() {
    Node *list1 = NULL, *list2 = NULL;

    int choice, data, pos;

    while (1) {
        printf("\n==== Doubly Linked List Menu ====\n");
        printf("1. Insert at end (List 1)\n");
        printf("2. Insert after position (List 1)\n");
        printf("3. Sort List 1\n");
        printf("4. Display List 1\n");
        printf("5. Insert at end (List 2)\n");
        printf("6. Concatenate List1 + List2\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(&list1, data);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data: ");
                scanf("%d", &data);
                insertAfterPosition(&list1, pos, data);
                break;

            case 3:
                sortList(&list1);
                break;

            case 4:
                display(list1);
                break;

            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(&list2, data);
                break;

            case 6:
                list1 = concatenate(list1, list2);
                printf("Concatenated List: ");
                display(list1);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
