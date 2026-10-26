
#include <stdio.h>
#include <stdlib.h>

// Queue implementation using Linked List
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct QueueLinkedList {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the queue
void initQueueLinkedList(struct QueueLinkedList* queue) {
    queue->front = queue->rear = NULL;
}

// Check if the queue is empty
int isEmptyLinkedList(struct QueueLinkedList* queue) {
    return queue->front == NULL;
}

// Enqueue operation (Insert element at rear)
void enqueueLinkedList(struct QueueLinkedList* queue, int value) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        // If the queue is empty
        queue->front = queue->rear = newNode;
    } else {
        // Add new node at the end
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Enqueued %d\n", value);
}

// Dequeue operation (Remove element from front)
int dequeueLinkedList(struct QueueLinkedList* queue) {
    if (isEmptyLinkedList(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node* temp = queue->front;
    int dequeuedValue = temp->data;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        // If the queue becomes empty
        queue->rear = NULL;
    }

    free(temp);
    return dequeuedValue;
}

// Peek the front element of the queue
int peekLinkedList(struct QueueLinkedList* queue) {
    if (isEmptyLinkedList(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    return queue->front->data;
}

// Display the elements in the queue
void displayQueueLinkedList(struct QueueLinkedList* queue) {
    if (isEmptyLinkedList(queue)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = queue->front;

    printf("Queue elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main() {
    struct QueueLinkedList queue;

    initQueueLinkedList(&queue);

    enqueueLinkedList(&queue, 10);
    enqueueLinkedList(&queue, 20);
    enqueueLinkedList(&queue, 30);

    displayQueueLinkedList(&queue);

    printf("Front element: %d\n", peekLinkedList(&queue));

    printf("Dequeued element: %d\n",
           dequeueLinkedList(&queue));

    displayQueueLinkedList(&queue);

    return 0;
}
