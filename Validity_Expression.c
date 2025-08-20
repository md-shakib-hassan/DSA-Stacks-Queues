#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
     return;
    }
    stack[++top] = c;
}


char pop() {
    if (top == -1) {
        return '\0'; 
    }
    return stack[top--];
}


int isValid(char *expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch); 
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                return 0; 
            }
            char popped = pop();
            if ((ch == ')' && popped != '(') ||
                (ch == '}' && popped != '{') ||
                (ch == ']' && popped != '[')) {
                return 0; 
            }
        }
    }

    if (top == -1)
        return 1; 
    else
        return 0; 
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (isValid(expr))
        printf("Valid Expression.\n");
    else
        printf("Invalid Expression.\n");

    return 0;
}
