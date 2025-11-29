//SINGLY LINKEDLISTS AND ITS BASIC OPERATION 

#include <stdio.h>
#include <stdlib.h>
//SLL
// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to display the list
void display() {
    struct node *trav = head;

    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nLinked List: ");

    // SINGLY: while(trav != NULL)
    // CIRCULAR: stop when trav comes back to head

    // ---- CIRCULAR CHANGE ----
    // do {
    //     printf("%d ", trav->data);
    //     trav = trav->next;
    // } while (trav != head);
    // return;
    // -------------------------

    while (trav != NULL) {  // normal singly
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("\n");
}

// Insert at beginning
void insertatbeg() {
    int info;
    printf("Enter element: ");
    scanf("%d", &info);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = info;

    newnode->next = head;

    // ---- CIRCULAR CHANGE ----
    // if (head == NULL)
    //     newnode->next = newnode;  // self loop
    // else {
    //     struct node *last = head;
    //     while (last->next != head)
    //         last = last->next;
    //     last->next = newnode;   // last node now points to new head
    // }
    //--------------------------

    head = newnode;

    display();
}

// Insert at end
void insertatend() {
    int info;
    printf("Enter element: ");
    scanf("%d", &info);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = info;
    newnode->next = NULL;

    // ---- CIRCULAR CHANGE ----
    // newnode->next = head;
    //--------------------------

    if (head == NULL) {
        head = newnode;

        // ---- CIRCULAR CHANGE ----
        // newnode->next = newnode;  // circular self loop
        //---------------------------

        display();
        return;
    }

    struct node *trav = head;

    // SINGLY: while(trav->next != NULL)
    // CIRCULAR: while(trav->next != head)

    // ---- CIRCULAR CHANGE ----
    // while (trav->next != head)
    //---------------------------

    while (trav->next != NULL)
        trav = trav->next;

    trav->next = newnode;

    // ---- CIRCULAR CHANGE ----
    // newnode->next = head;
    //--------------------------

    display();
}

// Insert at given position
void insertatpos() {
    int info, pos;
    printf("Enter element: ");
    scanf("%d", &info);
    printf("Enter position: ");
    scanf("%d", &pos);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = info;
    newnode->next = NULL;

    if (pos == 1) {
        newnode->next = head;

        // ---- CIRCULAR CHANGE ----
        // if (head == NULL)
        //     newnode->next = newnode;
        // else {
        //     struct node *last = head;
        //     while (last->next != head)
        //         last = last->next;
        //     last->next = newnode;
        // }
        //--------------------------

        head = newnode;
        display();
        return;
    }

    struct node *trav = head;
    for (int i = 1; i < pos - 1 && trav != NULL; i++) {
        trav = trav->next;
    }

    if (trav == NULL) {
        printf("Invalid Position!\n");
        free(newnode);
        return;
    }

    newnode->next = trav->next;
    trav->next = newnode;

    display();
}

// Delete from beginning
void deletebeg() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = head;

    // ---- CIRCULAR CHANGE ----
    // if (head->next == head) {  // only one node
    //     free(head);
    //     head = NULL;
    //     display();
    //     return;
    // }
    // struct node *last = head;
    // while (last->next != head)
    //     last = last->next;
    // head = head->next;
    // last->next = head;
    // free(temp);
    // display();
    // return;
    //---------------------------

    head = head->next;
    free(temp);

    display();
}

// Delete from end
void deleteend() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // Only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;

        // ---- CIRCULAR CHANGE ----
        // if (head->next == head)
        //     free and set head = NULL
        //---------------------------

        display();
        return;
    }

    struct node *trav = head;

    // SINGLY: while (trav->next->next != NULL)
    // CIRCULAR: while (trav->next->next != head)

    // ---- CIRCULAR CHANGE ----
    // while (trav->next->next != head)
    //----------------------------

    while (trav->next->next != NULL)
        trav = trav->next;

    struct node *temp = trav->next;
    trav->next = NULL;   // last removed

    // ---- CIRCULAR CHANGE ----
    // trav->next = head;
    //--------------------------

    free(temp);

    display();
}

// Delete at position
void deletepos() {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) {
        deletebeg();
        return;
    }

    struct node *trav = head;
    for (int i = 1; i < pos - 1 && trav != NULL; i++) {
        trav = trav->next;
    }

    if (trav == NULL || trav->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    struct node *temp = trav->next;
    trav->next = temp->next;

    // ---- CIRCULAR CHANGE ----
    // no extra change needed
    //--------------------------

    free(temp);

    display();
}

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertatbeg(); break;
            case 2: insertatend(); break;
            case 3: insertatpos(); break;
            case 4: deletebeg(); break;
            case 5: deleteend(); break;
            case 6: deletepos(); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

