// You are using GCC
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} node;


node* cn(int data){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    return newNode;
}

void append(node** head, int data){
    node* tail = cn(data);
    node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = tail;
    tail->next = NULL;
}


void rem(node** head, int num){
    node* temp = *head;
    while(temp->next->data != num){
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

int main(){
    node* n1 = cn(10);
    node* head;

    head = n1;
    while(head != NULL){
        printf("%d\n", head->data);
        head = head->next;
    }
    
    append(&n1, 100);
    append(&n1, 101);
    append(&n1, 102);
    append(&n1, 103);
    append(&n1, 104);
    append(&n1, 105);
    append(&n1, 106);
    append(&n1, 107);
    
    
    head = n1;
    while(head != NULL){
        printf("%d\n", head->data);
        head = head->next;
    }
    
    printf("\n__________________\n");


    rem(&n1, 104);
    
    head = n1;
    while(head != NULL){
        printf("%d\n", head->data);
        head = head->next;
    }

    return 0;
}