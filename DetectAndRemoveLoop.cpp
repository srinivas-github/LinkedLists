#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
   int data;
   struct node* next;
}MyNode;

void printList(MyNode *head)
{
   for (MyNode *temp = head; temp != NULL; temp = temp->next)
   {
       printf("[%d]->", temp->data);
   }
   printf("[NULL]\n\n");
}

MyNode* getLoopNode(MyNode *head)
{
    MyNode *slowPtr = head;
    MyNode *fastPtr = head;

    while (slowPtr->next != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
        {
            return slowPtr;
        }
    }
    return NULL;
}

int getLoopLength(MyNode *loopNode)
{
    int loopLength = 0;
    MyNode *slowPtr = loopNode;
    MyNode *fastPtr = loopNode;

    while (slowPtr->next != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        loopLength += 1;
        if (slowPtr == fastPtr)
        {
            break;
        }
    }
    return loopLength;
}
void removeLoop(MyNode *head)
{
    MyNode *ptr1 = head;
    MyNode *ptr2 = head;
    MyNode *loopNode = getLoopNode(head);

    if (head == NULL || loopNode == NULL)
    {
        return ;
    }
    int loopLen = getLoopLength(loopNode);
    for (int i = 0; i < loopLen; i++)
    {
        ptr2 = ptr2->next;
    }
    while (ptr2->next != NULL)
    {
        if (ptr1->next == ptr2->next)
            break;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr2->next = NULL;
}

int main()
{
    MyNode *head = (MyNode*)malloc(sizeof (MyNode));
    MyNode *first = (MyNode*)malloc(sizeof (MyNode));
    MyNode *second = (MyNode*)malloc(sizeof (MyNode));
    MyNode *third = (MyNode*)malloc(sizeof (MyNode));
    MyNode *fourth = (MyNode*)malloc(sizeof (MyNode));
    MyNode *fifth = (MyNode*)malloc(sizeof (MyNode));
    MyNode *sixth = (MyNode*)malloc(sizeof (MyNode));

    head->data = 1;
    head->next = first;
    
    first->data = 2;
    first->next = second;
    
    second->data = 3;
    second->next = third;
    
    third->data = 4;
    third->next = fourth;
    
    fourth->data = 5;
    fourth->next = fifth;

    fifth->data = 6;
    fifth->next = sixth;

    sixth->data = 7;
    sixth->next = third;

    removeLoop(head);
    printList(head);
    return 0;
}
