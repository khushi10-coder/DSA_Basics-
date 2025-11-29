//DOUBLYLINKEDLISTS & ITS BASIC OPERATIONS 
#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Display from start to end
void displayForward() {
    struct node *trav = head;

    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nList (Forward): ");

    // ---- DOUBLY CIRCULAR CHANGE ----
    // do {
    //     printf("%d ", trav->data);
    //     trav = trav->next;
    // } while (trav != head);
    // return;
    // ---------------------------------

    while (trav != NULL) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("\n");
}

// Display from end to start
void displayBackward() {
    struct node *trav = head;

    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    // Go to last node
    while (trav->next != NULL)
        trav = trav->next;

    // ---- DOUBLY CIRCULAR CHANGE ----
    // In circular list:
    // while (trav->next != head)
    //      trav = trav->next;
    // Now trav = last node
    // And loop backward until trav == head again
    // ------------------------------------------

    printf("\nList (Backward): ");
    while (trav != NULL) {
        printf("%d ", trav->data);
        trav = trav->prev;
    }
    printf("\n");
}

// Insert at beginning
void insertBeg() {
    int info;
    printf("Enter element: ");
    scanf("%d", &info);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = info;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    // ---- DOUBLY CIRCULAR CHANGE ----
    // if (head == NULL) {
    //     newnode->next = newnode;
    //     newnode->prev = newnode;
    // } else {
    //     struct node *last = head->prev;
    //     newnode->next = head;
    //     newnode->prev = last;
    //     head->prev = newnode;
    //     last->next = newnode;
    // }
    // ---------------------------------

    head = newnode;

    displayForward();
}

// Insert at end
void insertEnd() {
    int info;
    printf("Enter element: ");
    scanf("%d", &info);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = info;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;

        // ---- DOUBLY CIRCULAR CHANGE ----
        // newnode->next = newnode;
        // newnode->prev = newnode;
        // ---------------------------------

        displayForward();
        return;
    }

    struct node *trav = head;
    while (trav->next != NULL)
        trav = trav->next;

    trav->next = newnode;
    newnode->prev = trav;

    // ---- DOUBLY CIRCULAR CHANGE ----
    // newnode->next = head;
    // head->prev = newnode;
    // ---------------------------------

    displayForward();
}

// Insert at position
void insertPos() {
    int info, pos;
    printf("Enter element: ");
    scanf("%d", &info);
    printf("Enter position: ");
    scanf("%d", &pos);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = info;

    if (pos == 1) {
        newnode->prev = NULL;
        newnode->next = head;

        if (head != NULL)
            head->prev = newnode;

        // ---- DOUBLY CIRCULAR CHANGE ----
        // if (head == NULL) {
        //     newnode->next = newnode;
        //     newnode->prev = newnode;
        // } else {
        //     struct node *last = head->prev;
        //     newnode->next = head;
        //     newnode->prev = last;
        //     last->next = newnode;
        //     head->prev = newnode;
        // }
        // ---------------------------------

        head = newnode;
        displayForward();
        return;
    }

    struct node *trav = head;
    for (int i = 1; i < pos - 1 && trav != NULL; i++)
        trav = trav->next;

    if (trav == NULL) {
        printf("Invalid Position!\n");
        free(newnode);
        return;
    }

    newnode->next = trav->next;
    newnode->prev = trav;

    if (trav->next != NULL)
        trav->next->prev = newnode;

    // ---- DOUBLY CIRCULAR CHANGE ----
    // No special change here
    // Because prev and next both update normally
    // ---------------------------------

    trav->next = newnode;

    displayForward();
}

// Delete from beginning
void deleteBeg() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = head;

    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    // ---- DOUBLY CIRCULAR CHANGE ----
    // if (head->next == head) {
    //     free(head);
    //     head = NULL;
    //     return;
    // }
    // struct node *last = head->prev;
    // head = head->next;
    // head->prev = last;
    // last->next = head;
    // ---------------------------------

    free(temp);

    displayForward();
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;

        // ---- DOUBLY CIRCULAR CHANGE ----
        // If only one node:
        // free(head);
        // head = NULL;
        // ---------------------------------

        displayForward();
        return;
    }

    struct node *trav = head;
    while (trav->next != NULL)
        trav = trav->next;

    trav->prev->next = NULL;

    // ---- DOUBLY CIRCULAR CHANGE ----
    // trav->prev->next = head;
    // head->prev = trav->prev;
    // ---------------------------------

    free(trav);

    displayForward();
}

// Delete at position
void deletePos() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) {
        deleteBeg();
        return;
    }

    struct node *trav = head;
    for (int i = 1; i < pos && trav != NULL; i++)
        trav = trav->next;

    if (trav == NULL) {
        printf("Invalid Position!\n");
        return;
    }

    if (trav->next != NULL)
        trav->next->prev = trav->prev;

    trav->prev->next = trav->next;

    // ---- DOUBLY CIRCULAR CHANGE ----
    // No major changes needed
    // Just ensure head->prev and last->next remain circular
    // ---------------------------------

    free(trav);

    displayForward();
}

// Menu-driven main
int main() {
    int choice;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: insertPos(); break;
            case 4: deleteBeg(); break;
            case 5: deleteEnd(); break;
            case 6: deletePos(); break;
            case 7: displayForward(); break;
            case 8: displayBackward(); break;
            case 9: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
