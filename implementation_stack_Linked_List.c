#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
//PUSH OPERATION
void push(int value) {
    struct Node*newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}
//POP OPERATION
void pop()
{
    struct Node* temp;
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    temp = top;
    printf("%d popped from stack\n", temp->data);
    top = top->next;
    free(temp);
}
//PEEK OPERATION
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    }
    else{
    printf("Top element is %d\n", top->data);
    }
}
//DISPLAY OPERATION
void display() {
    struct Node* temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    printf("ADITYA AWASTHI\n");
    printf("Roll No: 2504231530007\n");
    printf("Stack implementation using linked list\n");
    printf("Program-5=>2\n");
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    while (top != NULL) {
        pop();
    }
    return 0;
}