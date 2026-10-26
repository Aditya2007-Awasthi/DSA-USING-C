
#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Queue implementation using Array
struct QueueArray {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueueArray(struct QueueArray* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is full
int isFullArray(struct QueueArray* queue) {
    return queue->rear == MAX - 1;
}

// Check if the queue is empty
int isEmptyArray(struct QueueArray* queue) {
    return queue->front == -1;
}

// Enqueue operation (Insert element at rear)
void enqueueArray(struct QueueArray* queue, int value) {
    if (isFullArray(queue)) {
        printf("Queue Overflow\n");
    } else {
        if (queue->front == -1) {
            // If queue is empty
            queue->front = 0;
        }

        queue->arr[++queue->rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Dequeue operation (Remove element from front)
int dequeueArray(struct QueueArray* queue) {
    if (isEmptyArray(queue)) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int dequeuedValue = queue->arr[queue->front];

        if (queue->front == queue->rear) {
            // If there is only one element
            queue->front = queue->rear = -1;
        } else {
            queue->front++;
        }

        return dequeuedValue;
    }
}

// Peek the front element of the queue
int peekArray(struct QueueArray* queue) {
    if (isEmptyArray(queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return queue->arr[queue->front];
    }
}

// Display the elements in the queue
void displayQueueArray(struct QueueArray* queue) {
    if (isEmptyArray(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");

        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }

        printf("\n");
    }
}


int main() {
    struct QueueArray queue;

    initQueueArray(&queue);

    enqueueArray(&queue, 10);
    enqueueArray(&queue, 20);
    enqueueArray(&queue, 30);

    displayQueueArray(&queue);

    printf("Front element: %d\n", peekArray(&queue));
    printf("Dequeued element: %d\n", dequeueArray(&queue));

    displayQueueArray(&queue);

    return 0;
}