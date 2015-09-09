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
    struct node* current=head;
    while (current != NULL)
    {
        printf("[%d]->", current->data);
        current = current->next;
    }
    printf("[NULL]\n");
}

void reverse(struct node** head_ref)
{
    struct node* current = *head_ref;
    struct node* prev = NULL;
    struct node* next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next; 
    }
    *head_ref = prev;
}

int main()
{
    struct node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    printf("Before reverse:\n");
    printList(head);
    reverse(&head);
    printf("After reverse:\n");
    printList(head);
    return 0;
}
