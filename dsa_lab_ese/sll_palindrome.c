#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// Insert at end of list
Node* insertEnd(Node* head, int x) {
    Node* newNode = createNode(x);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Reverse a linked list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse pointer
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }
    return prev;  // new head
}

// Check if list is palindrome
int isPalindrome(Node* head) {

    // 0 or 1 element → always palindrome
    if (head == NULL || head->next == NULL)
        return 1;

    Node *slow = head, *fast = head;

    // Find the middle of list
    // fast moves 2 steps, slow moves 1 step
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half of list
    Node* secondHalf = reverse(slow->next);

    // Compare first half and reversed second half
    Node* firstHalf = head;
    Node* temp = secondHalf;

    while (temp != NULL) {
        if (firstHalf->data != temp->data)
            return 0;   // Not palindrome

        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    return 1;  // Palindrome
}

// Print list
void display(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {

    Node* head = NULL;

    // Example: 1 → 2 → 1
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 2);
    head = insertEnd(head, 1);

    display(head);

    if (isPalindrome(head))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
