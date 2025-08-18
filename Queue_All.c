#include <stdio.h>
#define Max 10

int arr[Max];
int front = -1;
int rear = -1;

void enqueue(int data); 
void dequeue();          
void display();

int main() {
    int choice, data;
        
        printf("1. Dequeue.\n");
        printf("2. Enqueue.\n");
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
    if (rear == Max - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    arr[rear] = data;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued: %d\n", arr[front]);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
