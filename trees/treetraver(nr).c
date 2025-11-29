#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// ------------------ INSERT (BST) ------------------
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = val;
        root->left = root->right = NULL;
        return root;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// ------------------ RECURSIVE TRAVERSALS ------------------
void inorderR(struct Node* root) {
    if (root == NULL) return;
    inorderR(root->left);
    printf("%d ", root->data);
    inorderR(root->right);
}
void preorderR(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderR(root->left);
    preorderR(root->right);
}
void postorderR(struct Node* root) {
    if (root == NULL) return;
    postorderR(root->left);
    postorderR(root->right);
    printf("%d ", root->data);
}

// ------------------ STACK FOR NON-RECURSIVE ------------------
struct Node* stack[100];
int top = -1;

void push(struct Node* n) { stack[++top] = n; }
struct Node* pop() { return stack[top--]; }
int empty() { return top == -1; }

// ------------------ NON-RECURSIVE INORDER ------------------
void inorderNR(struct Node* root) {
    struct Node* curr = root;
    while (curr != NULL || !empty()) {
        while (curr != NULL) {
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

// ------------------ NON-RECURSIVE PREORDER ------------------
void preorderNR(struct Node* root) {
    if (root == NULL) return;
    push(root);
    while (!empty()) {
        struct Node* temp = pop();
        printf("%d ", temp->data);
        if (temp->right) push(temp->right);
        if (temp->left)  push(temp->left);
    }
}

// ------------------ NON-RECURSIVE POSTORDER ------------------
void postorderNR(struct Node* root) {
    struct Node *last = NULL, *curr = root;
    while (curr != NULL || !empty()) {
        if (curr != NULL) {
            push(curr);
            curr = curr->left;
        } else {
            struct Node* peek = stack[top];
            if (peek->right != NULL && last != peek->right) {
                curr = peek->right;
            } else {
                printf("%d ", peek->data);
                last = pop();
            }
        }
    }
}

// ------------------ MAIN ------------------
int main() {
    struct Node* root = NULL;
    int n, val;

    printf("How many nodes you want to insert? ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nRecursive Inorder: ");
    inorderR(root);

    printf("\nRecursive Preorder: ");
    preorderR(root);

    printf("\nRecursive Postorder: ");
    postorderR(root);

    printf("\n\nNon-Recursive Inorder: ");
    inorderNR(root);

    printf("\nNon-Recursive Preorder: ");
    preorderNR(root);

    printf("\nNon-Recursive Postorder: ");
    postorderNR(root);

    return 0;
}
