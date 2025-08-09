#include<stdio.h>
#include<stdlib.h>

#define Max 100
int arr[Max];
int top = -1;

void push(int data);
void pop();
void peek();
void print();
void isempty();
void size();

int main(){
    printf("Push Enter 1 . \n");
    printf("Pop Enter 2 . \n");
    printf("Peek Enter 3 . \n");
    printf("Print Enter 4 . \n");
    printf("Empty Check Enter 5 . \n");
    printf("Size Check Enter 6 . \n");
    printf("Exit Enter 7 . \n");

    while(1){
        printf("\nEnter a number for Operation : ");
        int number;
        scanf("%d", &number);

        switch(number){
            case 1:
                printf("Enter data to Push: ");
                int data;
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                print();
                break;

            case 5:
                isempty();
                break;

                case 6:
                    size();
                    break;

                    case 7:
                        exit(0);
                        break;

            default:
                printf("You entered an invalid number.\n");
        }
    }
}

void push(int data){
    if(top == Max-1){
        printf("Stack overflow.\n");
        return;
    }
    top++;
    arr[top] = data;
    printf("%d pushed to stack.\n", data);
}

void pop(){
    if(top == -1){
        printf("Stack Empty.\n");
        return;
    }
    printf("Popped: %d\n", arr[top]);
    top--;
}

void peek(){
    if(top == -1){
        printf("Stack Empty.\n");
        return;
    }
    printf("Stack peek: %d\n", arr[top]);
}

void print(){
    if(top == -1){
        printf("Stack Empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for(int i = 0; i <= top; i++){
        printf("%d\n", arr[i]);
    }
}

void isempty(){
    if(top!=-1){
        printf("It Not Empty.\n");
    
    }
    else{
        printf("It Empty.\n");
    }
}

void size(){
    printf("Size of Stacks is %d ",top+1);
}
