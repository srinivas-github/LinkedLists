#include <iostream>
#include <cstdio>
#include <cstdlib>

struct node
{
   int data;
   struct node* next;
};

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct node* head)
{
    struct node* temp = head;
    for (; temp != NULL; temp = temp->next)
    {
        printf("[%d]->", temp->data);
    }
    printf("[NULL]\n");
}

struct node* deleteNode(struct node* head, int n)
{
    struct node* curr_node = head;
    struct node* prev_node = NULL;

    for (int i = 0; i < n; i++)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    if (n!= 0 )
    {
        prev_node->next = curr_node->next;
    }
    else
    {
        head = head->next;
    }
    free(curr_node);
    return head;
}

int main()
{
    struct node* head = NULL;
    for (int i = 0; i<9; i++)
        push(&head, i);

    printList(head);
    head = deleteNode(head, 7);
    printList(head);

    return 0;
    
    
    
}
