#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
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
    newNode->prev = temp;
}

void deleteNode(struct Node** head, int value) {
    if (head == NULL || *head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted value %d.\n", value);
}

void traverseForward(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traverseBackward(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
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
    printf("Doubly Linked List Implementation\n");
    printf("Program-3\n");
    struct Node* head = NULL;
    int values[] = {10, 20, 30, 40};

    createList(&head, values, 4);

    printf("Doubly Linked List after creation:\n");
    traverseForward(head);

    insert(&head, 50);
    printf("Doubly Linked List after inserting 50:\n");
    traverseForward(head);

    deleteNode(&head, 20);
    printf("Doubly Linked List after deleting 20:\n");
    traverseForward(head);

    deleteNode(&head, 100);

    printf("Doubly Linked List in reverse order:\n");
    traverseBackward(head);

    printf("Final Doubly Linked List:\n");
    traverseForward(head);

    return 0;
}

