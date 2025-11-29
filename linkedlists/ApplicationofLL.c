//REPRESENTING STUDENT DATABASE USING LINKEDLISTS 



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float marks;
    struct Student* prev;
    struct Student* next;
};

struct Student* head = NULL;

// Function to create a new student node
struct Student* createStudent() {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter ID: ");
    scanf("%d", &newStudent->id);
    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent->name); // reads string with spaces
    printf("Enter Marks: ");
    scanf("%f", &newStudent->marks);
    newStudent->prev = newStudent->next = NULL;
    return newStudent;
}

// Insert at beginning
void insertAtBeginning() {
    struct Student* newStudent = createStudent();
    if(head == NULL) {
        head = newStudent;
    } else {
        newStudent->next = head;
        head->prev = newStudent;
        head = newStudent;
    }
    printf("Inserted at beginning.\n");
}

// Insert at end
void insertAtEnd() {
    struct Student* newStudent = createStudent();
    if(head == NULL) {
        head = newStudent;
    } else {
        struct Student* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newStudent;
        newStudent->prev = temp;
    }
    printf("Inserted at end.\n");
}

// Insert at a specific position (1-based)
void insertAtPosition() {
    int pos, i=1;
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    struct Student* newStudent = createStudent();

    if(pos == 1) {
        newStudent->next = head;
        if(head != NULL) head->prev = newStudent;
        head = newStudent;
        printf("Inserted at position %d.\n", pos);
        return;
    }

    struct Student* temp = head;
    while(temp != NULL && i < pos-1) {
        temp = temp->next;
        i++;
    }

    if(temp == NULL) {
        printf("Invalid position!\n");
        free(newStudent);
        return;
    }

    newStudent->next = temp->next;
    if(temp->next != NULL) temp->next->prev = newStudent;
    temp->next = newStudent;
    newStudent->prev = temp;

    printf("Inserted at position %d.\n", pos);
}

// Display all students
void display() {
    if(head == NULL) {
        printf("No records found.\n");
        return;
    }
    struct Student* temp = head;
    printf("\n--- Student Records ---\n");
    while(temp != NULL) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", temp->id, temp->name, temp->marks);
        temp = temp->next;
    }
}

// Display in reverse order
void displayReverse() {
    if(head == NULL) {
        printf("No records found.\n");
        return;
    }
    struct Student* temp = head;
    while(temp->next != NULL) temp = temp->next; // go to last node

    printf("\n--- Student Records (Reverse) ---\n");
    while(temp != NULL) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", temp->id, temp->name, temp->marks);
        temp = temp->prev;
    }
}

// Delete by ID
void deleteByID() {
    if(head == NULL) {
        printf("No records to delete.\n");
        return;
    }
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    struct Student* temp = head;

    while(temp != NULL && temp->id != id)
        temp = temp->next;

    if(temp == NULL) {
        printf("Student not found!\n");
        return;
    }

    if(temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next; // deleting first node

    if(temp->next != NULL) temp->next->prev = temp->prev;

    free(temp);
    printf("Student record deleted.\n");
}

// Main menu
int main() {
    int choice;
    while(1) {
        printf("\n--- Student Database (Doubly Linked List) ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Display All Students\n5. Display in Reverse Order\n6. Delete Student\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: display(); break;
            case 5: displayReverse(); break;
            case 6: deleteByID(); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}








/// Using circular 
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float marks;
    struct Student* next;
};

struct Student* tail = NULL; // circular linked list tail

// Create a new student node
struct Student* createStudent() {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter ID: ");
    scanf("%d", &newStudent->id);
    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent->name);
    printf("Enter Marks: ");
    scanf("%f", &newStudent->marks);
    newStudent->next = NULL;
    return newStudent;
}

// Insert at beginning
void insertAtBeginning() {
    struct Student* newStudent = createStudent();
    if(tail == NULL) {
        tail = newStudent;
        newStudent->next = newStudent; // points to itself
    } else {
        newStudent->next = tail->next;
        tail->next = newStudent;
    }
    printf("Inserted at beginning.\n");
}

// Insert at end
void insertAtEnd() {
    struct Student* newStudent = createStudent();
    if(tail == NULL) {
        tail = newStudent;
        newStudent->next = newStudent;
    } else {
        newStudent->next = tail->next;
        tail->next = newStudent;
        tail = newStudent;
    }
    printf("Inserted at end.\n");
}

// Insert at specific position (1-based)
void insertAtPosition() {
    int pos, i = 1;
    printf("Enter position to insert: ");
    scanf("%d", &pos);

    struct Student* newStudent = createStudent();
    if(tail == NULL || pos == 1) {
        insertAtBeginning();
        return;
    }

    struct Student* temp = tail->next; // first node
    while(i < pos-1 && temp != tail) {
        temp = temp->next;
        i++;
    }

    newStudent->next = temp->next;
    temp->next = newStudent;

    if(temp == tail) tail = newStudent;

    printf("Inserted at position %d.\n", pos);
}

// Display all students
void display() {
    if(tail == NULL) {
        printf("No records found.\n");
        return;
    }
    struct Student* temp = tail->next;
    printf("\n--- Student Records ---\n");
    do {
        printf("ID: %d, Name: %s, Marks: %.2f\n", temp->id, temp->name, temp->marks);
        temp = temp->next;
    } while(temp != tail->next);
}

// Display in reverse order (using temporary array)
void displayReverse() {
    if(tail == NULL) {
        printf("No records found.\n");
        return;
    }

    struct Student* temp = tail->next;
    int count = 0;
    struct Student* arr[100]; // temporary array to store nodes
    do {
        arr[count++] = temp;
        temp = temp->next;
    } while(temp != tail->next);

    printf("\n--- Student Records (Reverse) ---\n");
    for(int i = count-1; i >= 0; i--) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", arr[i]->id, arr[i]->name, arr[i]->marks);
    }
}

// Delete first student
void deleteFirst() {
    if(tail == NULL) return;
    struct Student* temp = tail->next;
    if(tail == tail->next) { // only one node
        free(temp);
        tail = NULL;
    } else {
        tail->next = temp->next;
        free(temp);
    }
    printf("Deleted first student.\n");
}

// Delete middle student (approx middle)
void deleteMiddle() {
    if(tail == NULL || tail->next == tail) {
        printf("Not enough records to delete middle.\n");
        return;
    }
    struct Student* slow = tail->next;
    struct Student* prev = tail;
    struct Student* fast = tail->next;

    while(fast != tail && fast->next != tail) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    if(slow == tail) tail = prev;
    free(slow);
    printf("Deleted middle student.\n");
}

// Menu
int main() {
    int choice;
    while(1) {
        printf("\n--- Student Database (Circular Linked List) ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Display All Students\n5. Display in Reverse Order\n6. Delete First Student\n");
        printf("7. Delete Middle Student\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: display(); break;
            case 5: displayReverse(); break;
            case 6: deleteFirst(); break;
            case 7: deleteMiddle(); break;
            case 8: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
*/
