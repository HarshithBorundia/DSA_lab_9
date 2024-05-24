#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
    Color color;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->color = RED; // New node is always red initially
    return newNode;
}

// Function declarations
void insert(TreeNode** root, int value);
void insertFixup(TreeNode** root, TreeNode* node);
void rotateLeft(TreeNode** root, TreeNode* node);
void rotateRight(TreeNode** root, TreeNode* node);
void levelOrderTraversal(TreeNode * root,int n){
    TreeNode* q[3000];
    int j  = 0;
    int cnt = n;
    q[j] = root;
    cnt--;
    int ind = -1;
    printf("%d ",root->value);
    while(cnt){  
        ind++;
        TreeNode * node = q[ind];
        if(node->left){
            j++;
            q[j] = node->left;
            printf("%d ",q[j]->value);
            cnt--;
        }
        else{
            printf("-1 ");
        }
        if(cnt==0)break;
        if(node->right){
            j++;
            q[j] = node->right;
            printf("%d ",q[j]->value);
            cnt--;
        }
        else{
            printf("-1 ");
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(&root, a[i]);
    }
    levelOrderTraversal(root,n);
    return 0;
}

// Insertion of a value into the Red-Black Tree
void insert(TreeNode** root, int value) {
    TreeNode* newNode = createNode(value);
    TreeNode* parent = NULL;
    TreeNode* current = *root;

    // Traverse the tree to find the appropriate position for the new node
    while (current != NULL) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Set the parent of the new node
    newNode->parent = parent;

    // Update the appropriate child pointer of the parent
    if (parent == NULL) {
        *root = newNode; // Tree was empty, so newNode becomes the root
    } else if (value < parent->value) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    // Perform fixup to maintain Red-Black Tree properties
    insertFixup(root, newNode);
}

// Fixup the Red-Black Tree properties after insertion
void insertFixup(TreeNode** root, TreeNode* node) {
    while (node != *root && node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            TreeNode* uncle = node->parent->parent->right;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    rotateLeft(root, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateRight(root, node->parent->parent);
            }
        } else {
            TreeNode* uncle = node->parent->parent->left;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rotateRight(root, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateLeft(root, node->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

// Perform a left rotation at a given node
void rotateLeft(TreeNode** root, TreeNode* node) {
    TreeNode* rightChild = node->right;
    node->right = rightChild->left;
    if (rightChild->left != NULL) {
        rightChild->left->parent = node;
    }
    rightChild->parent = node->parent;
    if (node->parent == NULL) {
        *root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }
    rightChild->left = node;
    node->parent = rightChild;
}

// Perform a right rotation at a given node
void rotateRight(TreeNode** root, TreeNode* node) {
    TreeNode* leftChild = node->left;
    node->left = leftChild->right;
    if (leftChild->right != NULL) {
        leftChild->right->parent = node;
    }
    leftChild->parent = node->parent;
    if (node->parent == NULL) {
        *root = leftChild;
    } else if (node == node->parent->right) {
        node->parent->right = leftChild;
    } else {
        node->parent->left = leftChild;
    }
    leftChild->right = node;
    node->parent = leftChild;
}

