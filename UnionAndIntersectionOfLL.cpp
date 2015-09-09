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

void PrintList(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
        printf("[%d]->", temp->data);
    printf("[NULL]\n");
}

bool isPresent(struct Node* head, int data)
{
    struct Node* t = head;
    while (t != NULL)
    {
        if(t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}

struct Node* getUnionList(struct Node* head1, struct Node* head2)
{
    struct Node* resultList = NULL;
    struct Node* t1 = head1;
    struct Node* t2 = head2;

    while(t1 != NULL)
    {
        push(&resultList, t1->data);
        t1 = t1->next;
    }

    while( t2 != NULL)
    {
        if( !isPresent(resultList, t2->data))
            push(&resultList, t2->data);
        t2 = t2->next;
    }
    return resultList;
}

struct Node* getInterList(struct Node* head1, struct Node* head2)
{
    struct Node* resultList = NULL;
    struct Node* t1 = head1;
    while (t1 != NULL)
    {
        if (isPresent(head2, t1->data))
            push(&resultList, t1->data);
        t1 = t1->next;
    }
    return resultList;
}

int main()
{
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* uList = NULL;
    struct Node* iList = NULL;

    push(&head1, 10);
    push(&head1, 12);
    push(&head1, 14);
    push(&head1, 16);
    push(&head1, 18);
    push(&head1, 20);
    push(&head1, 22);

    push(&head2, 18);
    push(&head2, 18);
    push(&head2, 20);
    push(&head2, 22);

    uList = getUnionList(head1, head2);
    printf("Union of Lists:\n");
    PrintList(uList);

    iList = getInterList(head1, head2);
    printf("Intersection of Lists:\n");
    PrintList(iList);

    return 0;
}

