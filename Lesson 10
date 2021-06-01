#include <stdio.h>
#include <stdlib.h>
#define true 1==1
#define false 1!=1
typedef int bool;

//=====================TASK 1====================================

bool func(char* str, int n) {
    for (int i = 0; i < n; i++) {
        if (str[i] == ')') {
            for (int j = i - 1; j >= 0; j--) {
                if (str[j] == '(') {
                    str[i] = str[j] = '*';
                    break;
                    func(str, n);
                }
                if (str[j] == '{') {
                    printf("ERROR");
                    return false;
                }
            }
        }
        if (str[i] == '}') {
            for (int j = i - 1; j >= 0; j--) {
                if (str[j] == '{') {
                    str[i] = str[j] = '*';
                    break;
                    func(str, n);
                }
                if (str[j] == '(') {
                    printf("ERROR");
                    return false;
                }
            }
        }
        if (str[i] == ']') {
            for (int j = i - 1; j >= 0; j--) {
                if (str[j] == '[') {
                    str[i] = str[j] = '*';
                    break;
                    func(str, n);
                }
                if (str[j] == '(') {
                    printf("ERROR");
                    return false;
                }
            }
        }
    }
}

//=====================TASK 2====================================
typedef struct Node {
    int dat;
    struct Node *next;
} Node;

typedef struct Node2 {
    int dat2;
    struct Node2 *next2;
} Node2;

typedef struct {
    Node *head;
    int size;
}List;

typedef struct {
    Node2 *head2;
    int size2;
}List2;


void init(List* lst) {
    lst->head = NULL;
    lst->size = 0;
}

void init2(List2* lst) {
    lst->head2 = NULL;
    lst->size2 = 0;
}


void ins (List *lst, int data)
{
    Node *new = (Node*) malloc(sizeof(Node));
    new->dat = data;
    new->next = NULL;

    Node *current = lst->head;
    if (current == NULL) {
        lst->head = new;
        lst->size++;
        return;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}

void ins2 (List2 *lst2, int data)
{
    Node2 *new = (Node2*) malloc(sizeof(Node2));
    new->dat2 = data;
    new->next2 = NULL;

    Node2 *current2 = lst2->head2;
    if (current2 == NULL) {
        lst2->head2 = new;
        lst2->size2++;
        return;
    } else {
        while (current2->next2 != NULL) {
            current2 = current2->next2;
        }
        current2->next2 = new;
        lst2->size2++;
    }
}


Node* rm (List *lst, int data)
{
    Node *current = lst->head;
    Node *parent = NULL;
    if (current == NULL)
        return NULL;
    while (current->next != NULL && current->dat != data) {
        parent = current;
        current = current->next;
    }
    if (current->dat != data)
        return NULL;

    if (current == lst->head)
    {
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    lst->size--;
    return current;
}

void printNode(Node *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf ("[%d] ", n->dat);
}

void printNode2(Node2 *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf ("[%d] ", n->dat2);
}


void printList (List *lst) {
    Node *current = lst->head;
    if (current == NULL) {
        printNode(current);
    } else do {
        printNode(current);
        current = current->next;
    } while (current != NULL);
    printf(" Size: %d \n", lst->size);
}

void printList2 (List2 *lst2) {
    Node2 *current2 = lst2->head2;
    if (current2 == NULL) {
        printNode2(current2);
    } else do {
        printNode2(current2);
        current2 = current2->next2;
    } while (current2 != NULL);
    printf(" Size: %d \n", lst2->size2);
}

//===============================================================
int main()
{
//=====================TASK 1====================================
    printf("Task 1 \n");
    char test[] = "(a[i] if(0) [14[],5] [{}])";
    printf("%s", (func(test, strlen(test))) ? "OK" : "FAIL");

    printf("\n\n\n");
//=====================TASK 2====================================
    printf("Task 2 \n");
    List *lst = (List*) malloc (sizeof(List));
    List2 *lst2 = (List2*) malloc (sizeof(List2));
    init(lst);
    ins(lst, 1);
    ins(lst, 6);
    ins(lst, 1);
    ins(lst, 12);
    printList(lst);
    printNode(rm(lst, 1)); printf("<- removed node\n");
    printList(lst);
    printf("\n");

    printList2(lst);
//===============================================================

    return 0;
}
