//double ended queue

#include <stdio.h>
#define MAX 5

int dq[MAX];
int front = -1, rear = -1;

void insertRear(int x) {
    if((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Queue Overflow\n"); return;
    }
    if(front == -1) front = rear = 0;
    else if(rear == MAX-1) rear = 0;
    else rear++;
    dq[rear] = x;
    printf("%d inserted at rear.\n", x);
}

void deleteFront() {
    if(front == -1) { printf("Queue Underflow\n"); return; }
    printf("%d deleted from front.\n", dq[front]);
    if(front == rear) front = rear = -1;
    else if(front == MAX-1) front = 0;
    else front++;
}

void deleteRear() {
    if(front == -1) { printf("Queue Underflow\n"); return; }
    printf("%d deleted from rear.\n", dq[rear]);
    if(front == rear) front = rear = -1;
    else if(rear == 0) rear = MAX-1;
    else rear--;
}

void display() {
    if(front == -1) { printf("Queue empty\n"); return; }
    printf("Queue: ");
    int i = front;
    while(1) {
        printf("%d ", dq[i]);
        if(i == rear) break;
        i = (i+1)%MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while(1) {
        printf("\n1.Insert Rear 2.Delete Front 3.Delete Rear 4.Display 5.Exit\nChoice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter value: "); 
                    scanf("%d",&val); 
                    insertRear(val); break;
            case 2: deleteFront(); break;
            case 3: deleteRear(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
