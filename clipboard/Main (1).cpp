// You are using GCC
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to create a new node
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the linked list
void append(node** head, int data) {
    node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to add a node at the beginning of the linked list
void prepend(node** head, int data) {
    node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to remove a node by value
void removeNode(node** head, int data) {
    if (*head == NULL) {
        printf("List is empty, nothing to remove\n");
        return;
    }

    node* temp = *head;
    node* prev = NULL;

    // If the node to be removed is the head
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the node to be removed
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found
    if (temp == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(node* head) {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    node* head = NULL;

    // Add elements to the linked list
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    prepend(&head, 5);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Remove an element from the linked list
    removeNode(&head, 20);
    printf("Linked List after removing 20: ");
    printList(head);

    // Free the linked list
    freeList(head);

    return 0;
}