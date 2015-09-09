#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int data)
{
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head_ref;

    ptr1->data = data;
    ptr1->next = (*head_ref);

   if (*head_ref != NULL)
   {
       while (temp->next != *head_ref)
           temp = temp->next;
       temp->next = ptr1;
   }
   else
   {
       ptr1->next = ptr1;
   }
   (*head_ref) = ptr1;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    if( head != NULL)
    {
        do
        {
            printf("[%d]->", temp->data);
            temp = temp->next;
        }while( temp != head);
        printf("\n");
    }
}

void reverseCLL(struct Node** head_ref)
{
    struct Node* result = NULL;
    struct Node* current = (*head_ref);
    struct Node* next;
    while (current != NULL)
    {
        next = current->next;
        current->next = result;
        result = current;
        current = next;
        if (current == *head_ref)
        {
            break;
        }
    }
    (*head_ref)->next = result;
    (*head_ref) = result;
}

int main()
{
    struct Node* head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printList(head);
    reverseCLL(&head);
    printList(head);
    
    return 0;
}
