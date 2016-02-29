#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* getNewNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    rtemp->next = NULL;
    return NULL;
}

void printL(struct Node* head)
{
    struct Node* temp = head;
    for (; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}

void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
    struct Node* current;
    if ( *head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
	*head_ref = new_node;
    }
    else
    {
        current - *head_ref;
	while (current->next != NULL && current->next->data < new_node->data)
	{
	    current = current->next;
	}
	new_node->next = current->next;
	current->next = new_node;
    }
}

int main()
{
    struct Node* head = NULL;
    struct Node* newNode = getNewNode(10);
    sortedInsert(&head, newNode);
    printL(head);

    newNode = getNewNode(8);
    sortedInsert(&head, newNode);
    printL(head);

    newNode = getNewNode(13);
    sortedInsert(&head, newNode);
    printL(head);

    newNode = getNewNode(7);
    sortedInsert(&head, newNode);
    printL(head);

    newNode = getNewNode(16);
    sortedInsert(&head, newNode);
    printL(head);
    
    newNode = getNewNode(11);
    sortedInsert(&head, newNode);
    printL(head);
    return 0;
}
