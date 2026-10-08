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
    newNode->next = newNode;
    return newNode;
}

void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    newNode->next = *head;
    temp->next = newNode;
}

void deleteNode(struct Node** head, int value) {
    if (head == NULL || *head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    do {
        if (current->data == value) {
            if (current == *head && current->next == *head) {
                free(current);
                *head = NULL;
                printf("Deleted value %d. List is now empty.\n", value);
                return;
            }

            if (current == *head) {
                previous = *head;
                while (previous->next != *head) {
                    previous = previous->next;
                }
                *head = (*head)->next;
                previous->next = *head;
            } else {
                previous->next = current->next;
            }

            free(current);
            printf("Deleted value %d.\n", value);
            return;
        }

        previous = current;
        current = current->next;
    } while (current != *head);

    printf("Value %d not found in the list.\n", value);
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

void createList(struct Node** head, int values[], int size) {
    for (int i = 0; i < size; i++) {
        insert(head, values[i]);
    }
}

int main(void) {
    printf("ADITYA AWASTHI\n");
    printf("2504231530007\n");
    printf("Circular Linked List Implementation\n");
    printf("Program-4\n");
    struct Node* head = NULL;
    int values[] = {10, 20, 30, 40};

    createList(&head, values, 4);

    printf("Circular Linked List after creation:\n");
    traverse(head);

    insert(&head, 50);
    printf("Circular Linked List after inserting 50:\n");
    traverse(head);

    deleteNode(&head, 20);
    printf("Circular Linked List after deleting 20:\n");
    traverse(head);

    deleteNode(&head, 100);

    printf("Final Circular Linked List:\n");
    traverse(head);

    return 0;
}

