#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* front = NULL;   
struct Node* rear = NULL;    

void enqueue(int data); 
void dequeue();         
void display();

int main() {
    int choice, data;
    
    printf("1. Dequeue\n");
    printf("2. Enqueue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                dequeue();
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}


void enqueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = rear;  

    if (rear == NULL) { 
        
        front = rear = newNode;
    } else {
        rear->next = newNode;  
        rear = newNode;        
    }
}


void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued: %d\n", temp->data);

    front = front->next;   
    if (front != NULL) {
        front->prev = NULL;
    } else {
        rear = NULL;      
    }

    free(temp);
}


void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
