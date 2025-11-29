#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// ==========================
// INSERT NODE
// ==========================
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

// ==========================
// TRAVERSALS
// ==========================
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// ==========================
// COUNT NODES
// ==========================
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// ==========================
// COUNT LEAF NODES
// ==========================
int countLeaf(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

// ==========================
// MIRROR TREE
// ==========================
void mirror(struct Node* root) {
    if (root == NULL) return;

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// ==========================
// HEIGHT OF TREE
// ==========================
int height(struct Node* root) {
    if (root == NULL) return -1; // height of empty tree
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// ==========================
// MAIN MENU-DRIVEN PROGRAM
// ==========================
int main() {
    struct Node* root = NULL;
    int choice, val, n;

    while(1) {
        printf("\n\n===== BST MENU =====\n");
        printf("1. Insert Nodes\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Count Total Nodes\n");
        printf("6. Count Leaf Nodes\n");
        printf("7. Mirror Tree\n");
        printf("8. Height of Tree\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("How many nodes you want to insert? ");
                scanf("%d", &n);
                for(int i=0; i<n; i++) {
                    printf("Enter value %d: ", i+1);
                    scanf("%d", &val);
                    root = insert(root, val);
                }
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                break;

            case 5:
                printf("Total Nodes: %d", countNodes(root));
                break;

            case 6:
                printf("Leaf Nodes: %d", countLeaf(root));
                break;

            case 7:
                mirror(root);
                printf("Tree has been mirrored!");
                break;

            case 8:
                printf("Height of Tree: %d", height(root));
                break;

            case 9:
                printf("Exiting program...");
                exit(0);

            default:
                printf("Invalid choice! Try again.");
        }
    }
    return 0;
}
