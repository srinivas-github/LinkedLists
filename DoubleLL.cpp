#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}MyNode;

MyNode *head;

MyNode* getNewNode(int data)
{
    MyNode *newNode = (MyNode*)malloc(sizeof (struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtHead(int data)
{
    MyNode *newNode = getNewNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(int data)
{
    MyNode *newNode = getNewNode(data);
    MyNode *temp = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp; 
}

void printForward()
{
    MyNode *temp = head;
    printf("Forward:");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printReverse()
{
    MyNode *temp = head;
    if (temp == NULL)
        return ;

    while (temp->next != NULL)
        temp = temp->next;

    printf("reverse:");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    insertAtTail(2);
    printForward();
    printReverse();
    insertAtTail(4);
    printForward();
    printReverse();
    insertAtHead(6);
    printForward();
    printReverse();
    insertAtTail(8);
    printForward();
    printReverse();
    return 1;
}
