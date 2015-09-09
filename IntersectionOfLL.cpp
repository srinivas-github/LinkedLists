#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* head)
{
    struct Node* current = head;
    for(; current!= NULL; current = current->next)
    {
        printf("[%d]->", current->data);
    }
    printf("[NULL]\n");
}

struct Node* intersectioNode(struct Node* a, struct Node* b)
{
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while( a != NULL && b!= NULL)
    {
        if (a->data == b->data)
        {
            push((&tail->next), a->data);
            tail = tail->next;
            a = a->next;
            b = b->next; 
        }
        else if (a->data < b->data)
        {
            a = a->next;
        }
        else
        {
            b = b->next;
        }
    }
    return (dummy.next);
}

int main()
{
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;
    struct Node* intersectNode = NULL;

    push(&l1, 7);
    push(&l1, 6);
    push(&l1, 5);
    push(&l1, 4);
    push(&l1, 3);
    push(&l1, 2);
    push(&l1, 1);

    printf("List1: \n");
    printList(l1);
   
    push(&l2, 8);
    push(&l2, 6);
    push(&l2, 4);
    push(&l2, 2);
    printf("List2: \n");
    printList(l2);
 
    intersectNode = intersectioNode(l1, l2);

    printf("Intersection of l1 and l2 is:\n");
    printList(intersectNode);
 
    return 0;
}
