#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

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

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void mirror(struct Node* root) {
    if (root == NULL) return;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, val;

    printf("How many nodes you want to insert? ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Enter value %d: ", i+1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Inorder before mirroring: ");
    inorder(root);

    mirror(root);

    printf("\nInorder after mirroring: ");
    inorder(root);

    return 0;
}
