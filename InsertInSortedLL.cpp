#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node* head)
{
    struct Node* current = head;
    for(; current != NULL; current = current->next)
    {
        printf("[%d]->", current->data);
    }
    printf("[NULL]\n");
}

struct Node* newNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertIntoLL(struct Node** head_ref, struct Node* new_Node)
{
    struct Node* current;
    if ( (*head_ref) == NULL || (*head_ref)->data >= new_Node->data)
    {
        new_Node->next = (*head_ref);
        (*head_ref) = new_Node;
    }
    else
    {
        current = *head_ref;
        while (current->next != NULL &&
               current->next->data < new_Node->data)
        {
            current = current->next;
        }
        new_Node->next = current->next;
        current->next = new_Node;
    } 
}

int main()
{
    struct Node*  head = NULL;
    struct Node* n1 = newNode(5);
    insertIntoLL(&head, n1);

    n1 = newNode(10);
    insertIntoLL(&head, n1);

    n1 = newNode(1);
    insertIntoLL(&head, n1);

    n1 = newNode(4);
    insertIntoLL(&head, n1);
    
    n1 = newNode(6);
    insertIntoLL(&head, n1);

    n1 = newNode(5);
    insertIntoLL(&head, n1);

    printList(head);
    return 0;
}
