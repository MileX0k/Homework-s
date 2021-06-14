#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
}TreeNode;

TreeNode* treeInsert(TreeNode* t, int data)
{
    TreeNode* newNode;
    newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode* current = t;
    TreeNode* parent = t;
    if (t == NULL) {
        t = newNode;
    }
    else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            }
            else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void printTree(TreeNode* root)
{
    if (root)
    {
        printf("%d", root->key);
        if (root->left || root->right)
        {
            printf("(");
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(", ");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

TreeNode* getSuccessor(TreeNode* node)
{
    TreeNode* current = node->right;
    TreeNode* parent = node;
    TreeNode* s = node;

    while (current != NULL)
    {
        parent = s;
        s = current;
        current = current->left;
    }
    if (s != node->right)
    {
        parent->left = s->right;
        s->right = node->right;
    }
    return s;

}

boolean deleteTree(TreeNode* root, int key)
{
    TreeNode* current = root;
    TreeNode* parent = root;
    boolean isLeftChild = true;

    while (current->key != key)
    {
        parent = current;
        if (key < current->key)
        {
            current = current->left;
            isLeftChild = true;
        }
        else
        {
            current = current->right;
            isLeftChild = false;
        }
        if (current == NULL)
            return false;
    }

    if (current->left == NULL && current->right == NULL)
    {
        if (current == root)
            root = NULL;
        else if (isLeftChild)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else if (current->right == NULL)
    {
        if (isLeftChild)
            parent->left = current->left;
        else parent->right = current->left;

    }
    else if (current->left == NULL)
    {
        if (isLeftChild)
            parent->left = current->right;
        else parent->right = current->right;
    }
    else
    {
        TreeNode* successor = getSuccessor(current);
        if (current == root)
            root = successor;
        else if (isLeftChild)
            parent->left = successor;
        else
            parent->right = successor;
        successor->left = current->left;
    }
    return true;
}

int sum = 0;
int calcElemTree(TreeNode* tree)
{
    if (tree == NULL)
        return sum;
    else
    {
        sum++;
        calcElemTree(tree->left);
        calcElemTree(tree->right);
    }
}

void resetSum()
{
    sum = 0;
}

////////////////////////==TASK 4==/////////////////////////////////////////////////////////////////

boolean searchData(TreeNode* root, int data)
{
    if (root)
    {
        if (root->key == data)
        {
            printf("Data found: %d", data);
            return true;
        }
        else
        {
            searchData(root->left, data);
            searchData(root->right, data);
        }

    }
    else return -1;
}

////////////////////////==TASK 1==/////////////////////////////////////////////////////////////////

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(TreeNode* tree)
{
    if (tree == NULL)
        return 0;
    return 1 + max(height(tree->left), height(tree->right));
}

boolean isBalanced(TreeNode* root)

{
    int lh;
    int rh;

    if (root == NULL)
        return 1;
    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;

}

////////////////////////==TASK 2==/////////////////////////////////////////////////////////////////

int r = 1;
int createRoot()
{
    TreeNode* tr = treeInsert(NULL, rand() % 100 + 1);
    for (int j = 0; j < 10; j++)
        treeInsert(tr, rand() % 40 + 1);
    printTree(tr);
    printf("\n");
    calcElemTree(tr);
    printf("Elements: %d \n", sum);
    resetSum();
    if (isBalanced(tr))
    {
        printf("Tree is balanced");
        r++;
    }
    else
        printf("Tree is not balanced");
    printf("\n");

    return 0;
}

int main()
{
    TreeNode* tree = treeInsert(NULL, 5);
    for (int i = 0; i < 10; i++)
        treeInsert(tree, rand() % 100 + 1);
    printTree(tree);
    printf("\n");
    calcElemTree(tree);
    printf("Elements: %d \n", sum);
    resetSum();
    ////////////////////////==TASK 4==/////////////////////////////////////////////////////////////////
    int h = 11;
    searchData(tree, h);
    printf("\n");

    ////////////////////////==TASK 1==/////////////////////////////////////////////////////////////////
    if (isBalanced(tree))
        printf("Tree is balanced");
    else
        printf("Tree is not balanced");
    printf("\n");
    ////////////////////////==TASK 2==/////////////////////////////////////////////////////////////////
    unsigned int arrayTree[10];
    for (size_t i = 0; i < 10; i++)
    {
        arrayTree[i] = (unsigned int)malloc(50 * sizeof(unsigned int));
    }

    for (size_t i = 0; i < 10; i++)
    {
        arrayTree[i] = createRoot();
    }
    ////////////////////////==TASK 3==/////////////////////////////////////////////////////////////////
   
    //float ye;

    //ye = r/0,1;

    //printf("Persent: %f", ye);
    


    return 0;
}
