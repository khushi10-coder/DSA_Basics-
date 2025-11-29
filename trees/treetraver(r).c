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

   

    return 0;
}
