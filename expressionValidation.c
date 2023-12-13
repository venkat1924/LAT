#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

char* inputMathExpression();
int push(char item);
char pop();
int checkExpression(char* expression);

int main() {
    char* expression = inputMathExpression();
    
    if (checkExpression(expression))
        printf("Parentheses make sense.\n");
    else
        printf("Parentheses do not make sense.\n");
        
    free(expression); // Free dynamically allocated memory

    return 0;
}

char *inputMathExpression() {
    printf("Enter a mathematical expression: ");

    char *expression = NULL;
    int size = 0;
    int index = 0;
    char ch;

    while ((ch = getchar()) != '\n') {
        if (index >= size) {
            size += 10;
            expression = realloc(expression, size * sizeof(char));

            if (expression == NULL) {
                printf("Memory allocation failed.\n");
                return NULL;
            }
        }

        expression[index++] = ch;
    }

    if (index < size) {
        expression[index] = '\0';
    } else {
        size++;
        expression = realloc(expression, size * sizeof(char));

        if (expression == NULL) {
            printf("Memory allocation failed.\n");
            return NULL;
        }

        expression[index] = '\0';
    }

    return expression;
}

int push(char item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return 0;
    }
    top++;
    stack[top] = item;
    return 1;
}

char pop() {
    if (top == -1) {
        return '\0'; // Return null character to indicate an empty stack
    }
    char item = stack[top];
    top--;
    return item;
}

int checkExpression(char* expression) {
    int size = strlen(expression);
    for (int i = 0; i < size; i++) {
        if (expression[i] == '(') {
            push(expression[i]);
        } else if (expression[i] == ')') {
            char popped = pop();
            if (popped != '(') {
                return 0; // Mismatched parentheses
            }
        }
    }
    if (top == -1) {
        return 1; // All parentheses matched
    } else {
        return 0; // Unmatched opening parentheses
    }
}
