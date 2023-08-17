#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data);
struct TreeNode* insert(struct TreeNode* root, int data);
struct TreeNode* delete(struct TreeNode* root, int data);
struct TreeNode* findMin(struct TreeNode* node);
void inorderTraversal(struct TreeNode* root);
void freeTree(struct TreeNode* root);

int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("\nChoose one Operation\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display (Inorder Traversal)\n");
        printf("4. Exit\n");

        printf("Response: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the value to insert: ");
                scanf("%d", &data);

                root = insert(root, data);
                printf("Value %d inserted.\n", data);
                break;
            }

            case 2: {
                printf("Enter the value to delete: ");
                scanf("%d", &data);

                root = delete(root, data);
                break;
            }

            case 3: {
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Inorder Traversal: ");
                    inorderTraversal(root);
                    printf("\n");
                }
                break;
            }

            case 4: {
                freeTree(root);
                printf("Exiting the program.\n");
                exit(0);
            }

            default: {
                printf("Invalid choice. Please choose again.\n");
                break;
            }
        }
    }

    return 0;
}

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

struct TreeNode* delete(struct TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = delete(root->right, temp->data);
    }

    return root;
}

struct TreeNode* findMin(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}