#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* prev;   
    int data;            
    struct Node* next;   
};

struct Node* top = NULL;


void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow.\n");
        return;
    }

    newNode->data = value;
    newNode->prev = top;    
    newNode->next = NULL;   

    if (top != NULL) {
        top->next = newNode; 
    }
    top = newNode;          
}


void pop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;    
    top = top->prev;            
    if (top != NULL) {
        top->next = NULL;       
    }
    free(temp);
}


void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;       
    }
    printf("\n");
}

int main() {
    int choice, value;

    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) return 0;

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            if (scanf("%d", &value) != 1) return 0;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
