#include <iostream>
#include <cstdio>
#include <cstdlib>

struct node
{
    int data;
    struct node* next;
};

void push(struct node** head_ref, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct node* head)
{
    struct node* temp = head;
    for(; temp != NULL; temp = temp->next)
    {
        printf("[%d]->", temp->data);
    }
    printf("[NULL]\n");
}

void middleNode(struct node* head)
{
    struct node* slowPtr = head;
    struct node* fastPtr = head;
    if (head != NULL)
    {
        while (fastPtr != NULL && fastPtr->next != NULL)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        printf("The Middle element is: %d\n\n", slowPtr->data);
    }
}

int main()
{
    struct node* head = NULL;
    for( int i =5; i>0; i--)
    {
        push(&head, i);
        printList(head);
        middleNode(head);
    }
    return 0;
}
