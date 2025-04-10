
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

// Queue implementation
char queue[MAX];
int front = 0, rear = -1;

void enqueue(char c) {
    if (rear < MAX - 1)
        queue[++rear] = c;
}

char dequeue() {
    if (front <= rear)
        return queue[front++];
    return '\0';
}

// Palindrome checking function
int isPalindrome(char str[]) {
    // Reset pointers
    top = -1;
    front = 0;
    rear = -1;

    // Normalize input: remove non-alphanumeric and convert to lowercase
    char cleaned[MAX];
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            cleaned[len++] = tolower(str[i]);
        }
    }
    cleaned[len] = '\0';

    // Fill stack and queue
    for (int i = 0; i < len; i++) {
        push(cleaned[i]);
        enqueue(cleaned[i]);
    }

    // Compare stack and queue
    for (int i = 0; i < len; i++) {
        if (pop() != dequeue())
            return 0; // Not a palindrome
    }
    return 1; // Palindrome
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove newline if present
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str))
        printf("\"%s\" is a palindrome.\n", str);
    else
        printf("\"%s\" is not a palindrome.\n", str);

    return 0;
}
