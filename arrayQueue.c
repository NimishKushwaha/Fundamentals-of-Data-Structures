#include<stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty(){
    return (front == -1 && rear == -1);
}
int isFull(){
    return (rear == MAX_SIZE -1);
}
void enqueue(int value){
    if (isFull()){
        printf("Queue is Full. Enqueue opeation is failed.\n");
        return;
    }

   else if(isEmpty()){
    front = 0;
    rear = 0;
   }
    else{
    rear++;
    }

   queue[rear] = value;
   printf("%d enqueued sucessfully.\n", value);
}
// Function to dequeue an element from the front of the queue
int dequeue(){
    int value;
    if (isEmpty()){
        printf("Queue is empty. Dequeue operation failed.\n");
        return -1;

    } else {
        value = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        return value;
    }
}
//function to display the elements in the queue
void display(){
    if(isEmpty()){
        printf("Queue is empty.\n");
    }else{
        printf("Queue elements: ");
        for(int i = front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); //Queue elements: 10 20 30

    int dequeudValue = dequeue();
    printf("Dequeued value: %d\n", dequeudValue); //Dequeued value: 10
    return 0;
}