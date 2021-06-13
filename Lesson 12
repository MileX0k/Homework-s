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
////////////////////////==TASK 1==/////////////////////////////////////////////////////////////////
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

boolean checkBinTree(TreeNode* tree, int n)
{
    if (tree->left == NULL && tree->right == NULL)
    {
        int x = calcElemTree(tree);
        resetSum();
        int nL = calcElemTree(tree->left);
        resetSum();
        int nR = calcElemTree(tree->right);
        resetSum();


        if (tree == NULL)
            return printf("Tree is empty");
        while (tree != NULL)
        {
            if (nL < x / 2 && nR > x / 2 - 1)
            {
                checkBinTree(tree->left, x);
                checkBinTree(tree->right, x);
                return 1;
            }
            else
                return false;
        }
    }
    return false;
}

//========================================================================================================================

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

int main()
{
    TreeNode* tree = treeInsert(NULL, 5);
    for (int i = 0; i < 10; i++)
        treeInsert(tree, rand() % 30 + 1);
    printTree(tree);
    printf("\n");
    calcElemTree(tree);
    printf("Elements: %d \n", sum);
    resetSum();

    int h = 11;
    searchData(tree, h);
    printf("\n");

    //deleteTree(tree, 5);
    //calcElemTree(tree);
    //printTree(tree);
    //printf("\n");
    //printf ("Elements: %d \n", sum);
    //resetSum();

    if (checkBinTree(tree, sum))
    {
        printf("Tree is balansed");
    } else printf("Tree is not balansed");
    printf("\n");
    printf("\n");


    return 0;
}
