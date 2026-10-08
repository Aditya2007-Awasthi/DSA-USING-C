#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteNode(struct Node** head, int value) {
    if (head == NULL || *head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Deleted value %d.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted value %d.\n", value);
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void createList(struct Node** head, int values[], int size) {
    for (int i = 0; i < size; i++) {
        insert(head, values[i]);
    }
}

int main(void) {
    printf("ADITYA AWASTHI\n");
    printf("2504231530007\n");
    printf("Singly Linked List Implementation\n");
    printf("Program-2\n");
    struct Node* head = NULL;
    int values[] = {10, 20, 30, 40};

    createList(&head, values, 4);

    printf("Linked List after creation:\n");
    traverse(head);

    insert(&head, 50);
    printf("Linked List after inserting 50:\n");
    traverse(head);

    deleteNode(&head, 20);
    printf("Linked List after deleting 20:\n");
    traverse(head);

    deleteNode(&head, 100);

    printf("Final Linked List:\n");
    traverse(head);

    return 0;
}

