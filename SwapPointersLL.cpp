#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = *head_ref;
    *head_ref = temp;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    for (; temp != NULL; temp = temp->next)
       printf("[%d]->", temp->data);
    printf("[NULL]\n");
}

void swapPointers(struct Node** head_ref, int x, int y)
{
    if (x == y)
        return ;

    struct Node* prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x)
    {
        prevX = currX;
	currX = currX->next;
    }

    struct Node* prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y)
    {
        prevY = currY;
	currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
        return ;

    if (prevX != NULL)
        prevX->next = currY;
    else
        *head_ref = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        *head_ref = currX;

    struct Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp

}

int main()
{
    struct Node* head = NULL:
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Before Swap: \n");
    printList(head);

    swapPointers(&head, 7, 5);
    printf("After Swap:\n");
    printList(head);
    return 0;
}

