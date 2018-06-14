#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
} List;


int isEqual(int data);
List *makeEvenList(List *list);

void printList(Node *curNode);

void freeList(List *list);

int main()
{
    List list = {NULL};
    List *newList = NULL;
    Node *newNode = NULL;
    int i=0;

    for (i=0; i<1000; i++)
    {
        newNode = (Node *) malloc (sizeof(Node));
        newNode->next = list.head;
        newNode->data = i;
        list.head = newNode;
    }

    newList = makeEvenList(&list);
    printList(newList->head);
    freeList(&list);
    freeList(newList);
    return 0;
}

void freeList(List *list)
{
    Node *toDelete = NULL;

    while (list->head)
    {
        toDelete = list->head;
        list->head = toDelete->next;
        free(toDelete);
    }
}

void printList(Node *curNode)
{
    if (curNode == NULL)
    {
        return;
    }

    printf("%d\n",curNode->data);
    printList(curNode->next);
}

List *makeEvenList(List *list)
{
    List *newList = NULL;
    Node *curNode = NULL;
    Node *newNode = NULL;

    if (!list)
    {
        return NULL;
    }

    newList = (List*) malloc (sizeof(List));
    newList->head = NULL;

    curNode = list->head;

    while (curNode != NULL)
    {
        if (isEqual(curNode->data))
        {
            newNode = (Node *) malloc (sizeof(Node));
            newNode->data = curNode->data;

            newNode->next = newList->head;  //new node points to what head is
            newList->head = newNode;        //head is now new node
        }
        curNode = curNode->next;
    }

    return newList;
}

int isEqual(int data) {
    return data%2 == 0;
}



