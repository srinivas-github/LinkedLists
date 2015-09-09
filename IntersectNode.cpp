#include <cstdio>
#include <cstdlib>

struct Node
{
    int data;
    struct Node* next;
};

int getCount(struct Node* head)
{
    int cnt = 0;
    struct Node* current = head;
    while (current != NULL)
    {
        cnt++;
        current = current->next;
    }
    return cnt;
}

int _getIntersectNode(int d, struct Node* head1, struct Node* head2)
{
    struct Node* curr1 = head1;
    struct Node* curr2 = head2;
    for (int i = 0; i < d; i++)
    {
        if (curr1 == NULL)
        {
            return -1;
        }
        curr1 = curr1->next;
    }
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1 == curr2)
            return curr1->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
}

int getIntersectNode(struct Node* h1, struct Node* h2)
{
    int l1 = getCount(h1);
    int l2 = getCount(h2);
    int d = 0;
    if (l1 > l2)
    {
        d = l1 - l2;
        return _getIntersectNode(d, h1, h2);
    }
    else
    {
        d = l2 - l1;
        return _getIntersectNode(d, h2, h1);
    }
}

int main()
{
    struct Node* newNode;
    struct Node* head1 =
            (struct Node*) malloc(sizeof(struct Node));
    head1->data  = 10;
 
    struct Node* head2 =
            (struct Node*) malloc(sizeof(struct Node));
    head2->data  = 3;
 
    newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode->data = 6;
    head2->next = newNode;
 
    newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode->data = 9;
    head2->next->next = newNode;
 
    newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next  = newNode;
 
    newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode->data = 30;
    head1->next->next= newNode;
 
    head1->next->next->next = NULL;
 
    printf("\n The node of intersection is %d \n",
          getIntersectNode(head1, head2)); 
    return 0;
}

