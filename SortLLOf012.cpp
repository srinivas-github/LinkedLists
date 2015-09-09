/**
 * Sort a linked list of 0s, 1s and 2s
 * Given a linked list of 0s, 1s and 2s, sort it.
 * Following steps can be used to sort the given linked list.
 * 1) Traverse the list and count the number of 0s, 1s and 2s. Let the counts be n1, n2 and n3 respectively.
 * 2) Traverse the list again, fill the first n1 nodes with 0, then n2 nodes with 1 and finally n3 nodes with 2.
 */

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

void sortList(struct node* head)
{
    int count[3] = {0,0,0};
    struct node* ptr = head;
    while (ptr != NULL)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }
    int i = 0;
    ptr = head;

    while (ptr != NULL)
    {
        if (count[i] == 0)
        {
            ++i;
        }
        else
        {
            ptr->data = i;
            --count[i];
            ptr= ptr->next;
        }
    }
}

int main()
{
    struct node* head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 2);
    push(&head, 0);
    push(&head, 2);
    push(&head, 0);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    printList(head);
    sortList(head);
    printList(head);
    return 0;
}
