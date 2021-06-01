#include <stdio.h>
#include <stdlib.h>

//==================TASK 1=============================

#define SZ 10

typedef struct {
    int pr;
    int dat;
}Node;

Node* arr[SZ];
int head;
int tail;
int items;

void init()
{
    for(int i = 0; i < SZ; ++i)
        arr[i] = NULL;
    head = 0;
    tail = -1;
    items = 0;
}

void ins (int pr, int dat)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;

    if (items == SZ)
        printf ("%s \n", "Queue is full ");

    arr[++tail] = node;
    tail %= SZ;

    for (int i = 0; i < SZ; i++)
    {

        if (arr[i] == NULL)
            arr[i] = node;

    }
        if (tail == SZ - 1)
        {
           tail = -2;
        }

        items++;
        head++;

}
//==================================
Node* rem()
{
    Node *tmp = (Node*) malloc(sizeof(Node));

    tmp->pr = 1000;

    if (items == 0){return NULL;}
    else if (items <= SZ)
    {
                for (int k = 0; k < SZ; k++)
                {
                    if (arr[k]->pr < tmp->pr)
                    {
                        tmp->pr = arr[k]->pr;
                    }
                }
                for (int i = 0; i < SZ; i++)
                {
                    if (tmp->pr == arr[i]->pr)
                        {
                            arr[i] = NULL;
                            items--;
                        }
                 }
                for (int i = 0; i < SZ - 1; i++)
                {
                    if (arr[i] == NULL)
                    {
                        arr[i] = arr[i+1];
                        arr[i+1] = NULL;
                    }
                }
    }
}


void printQueue()
{
    printf("[ ");
    for (int i = 0; i < SZ; i++)
    {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else printf("[%d, %d]", arr[i]->pr , arr[i]->dat);
    }
    printf(" ] \n");
}



//=====================================================

//==================TASK 2=============================




#define T int
#define SIZE 1000
#define TRUE 1==1
#define FALSE !TRUE


typedef int boolean;
int cursor = -1;
T Stack[SIZE];

boolean push (T data)
{
    if (cursor < SIZE) {
        for (int i = 0; data != 0;)
        {
            i = data%2;
            data = data/2;
            Stack[++cursor] = i;
        }
        return TRUE;
    } else {printf("%s \n", "Stack overflow");
    return FALSE;
    }
}

T pop() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
    printf("%s \n", "Stack is empty");
    return -1;
    }
}

//=====================================================


int main() {
//==================TASK 1=============================
    init();
    ins (5, 70);
    ins (2, 100);
    ins (3, 90);
    ins (8, 40);
    ins (6, 110);
    ins (10, 20);
    ins (4, 80);
    ins (4, 80);
    ins (7, 50);
    ins (9, 30);
    printQueue();

    rem();
    printQueue();

    ins (6, 60);
    ins (4, 80);
    printQueue();


//==================TASK 2=============================
    push (90);
    while (cursor != -1) {
        printf("%d ", pop());
    }

    return 0;

}

