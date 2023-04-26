#include<stdio.h>
#include<stdlib.h>

//Node structure for the linked list
struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL; //Front pointer of the queue
struct Node* rear = NULL; //Rear pointer of the queue

//Function to check if the queue is empty 
int isEmpty(){
    return (front == NULL);
}

//Function to enqueue an element to the rear of the queue
void enqueue(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL){
        front = newNode;
        rear = newNode;
    } else{
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n%d enqueued successfully.", value);
}

//Function to dequeue an element from the front of the queue
int dequeue(){
    if(isEmpty()){
        printf("Queue is empty. Dequeue operation failed.\n");
        return -1;
    } else{
        struct Node* temp = front;
        int value = front->data;
        front = front->next;
        free(temp);

        if(front == NULL){
            rear = NULL;
        }
        return value;
    }
}

//Function to display the elements in the queue
void display(){
    if (isEmpty()){
        printf("Queue is empty.\n");
    } else {
        printf("\nQueue elements: ");
        struct Node* temp = front;
        while (temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); //Queue elements: 10 20 30

    int dequeuedValue = dequeue();
    printf("Dequeued value: %d\n", dequeuedValue); //Dequeued value: 10
    printf("\n");

    return 0;
}