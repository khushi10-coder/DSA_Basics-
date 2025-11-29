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

int height(struct Node* root) {
    if (root == NULL) return -1; // height of empty tree
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
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

    printf("Height of BST: %d", height(root));

    return 0;
}
