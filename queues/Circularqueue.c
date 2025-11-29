///Circular queue 
#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if((front == 0 && rear == MAX-1) || (rear+1 == front)) { printf("Queue Overflow\n"); return; }
    if(front == -1) front = rear = 0;
    else if(rear == MAX-1) rear = 0;
    else rear++;
    cq[rear] = x;
    printf("%d enqueued.\n", x);
}

void dequeue() {
    if(front == -1) { printf("Queue Underflow\n"); return; }
    printf("%d dequeued.\n", cq[front]);
    if(front == rear) front = rear = -1;
    else if(front == MAX-1) front = 0;
    else front++;
}

void display() {
    if(front == -1) { printf("Queue empty\n"); return; }
    printf("Queue: ");
    int i = front;
    while(1) {
        printf("%d ", cq[i]);
        if(i == rear) break;
        i = (i+1)%MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while(1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d",&val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
