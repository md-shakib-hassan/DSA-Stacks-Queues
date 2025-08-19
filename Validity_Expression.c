#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push element into stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
      exit(1);
    }
    stack[++top] = c;
}

// Function to pop element from stack
char pop() {
    if (top == -1) {
        return '\0'; // stack empty
    }
    return stack[top--];
}

// Function to check validity of parentheses
int isValid(char *expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch); // push left parenthesis
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                return 0; // right parenthesis more than left
            }
            char popped = pop();
            if ((ch == ')' && popped != '(') ||
                (ch == '}' && popped != '{') ||
                (ch == ']' && popped != '[')) {
                return 0; // mismatched parenthesis
            }
        }
    }

    if (top == -1)
        return 1; // stack empty → balanced
    else
        return 0; // left parenthesis more than right
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (isValid(expr))
        printf("Valid Expression: Balanced Parentheses\n");
    else
        printf("Invalid Expression: Unbalanced Parentheses\n");

    return 0;
}
