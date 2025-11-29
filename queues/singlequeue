//Single Queue  using array 

#include <stdio.h>
#define MAX 5
//Single queue
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX-1) {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1) front = 0;
    rear++;
    queue[rear] = x;
    printf("%d enqueued.\n", x);
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d dequeued.\n", queue[front]);
    front++;
}

void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, val;
    while(1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d",&val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
}
