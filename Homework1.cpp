#include <stdio.h>


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n, int index) {
    if (index == n - 1) {
        return;
    }

    int minIndex = index;
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    if (minIndex != index) {
        swap(&arr[index], &arr[minIndex]);
    }
    
    selectionSort(arr, n, index + 1);
}

int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n, 0);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int* items;      
    int front;       
    int rear;        
    int maxSize;     
    int size;        
} Queue;


Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->items = (int*)malloc(sizeof(int) * capacity);
    queue->front = 0;
    queue->rear = -1;
    queue->maxSize = capacity;
    queue->size = 0;
    return queue;
}


int isFull(Queue* queue) {
    return queue->size == queue->maxSize;
}


int isEmpty(Queue* queue) {
    return queue->size == 0;
}


void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->maxSize;
    queue->items[queue->rear] = value;
    queue->size++;
    printf("Enqueued: %d\n", value);
}


int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->maxSize;
    queue->size--;
    printf("Dequeued: %d\n", value);
    return value;
}


int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->items[queue->front];
}

int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->items[queue->rear];
}


int main() {
    Queue* queue = createQueue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    dequeue(queue);
    dequeue(queue);

    enqueue(queue, 60);

    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    return 0;
}*/
