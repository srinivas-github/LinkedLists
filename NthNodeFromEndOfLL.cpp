/**
 * Given a LL and number n, get the value of the nth node from end of LL.
 * Algorithm
 * 1. Calculate the length of LL.
 * 2. Print (len -n +1)th node
 */
#include <iostream>
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
    struct node* tmp = head;
    for (; tmp != NULL; tmp = tmp->next)
        std::cout<<"["<<tmp->data<<"]=>";
    std::cout<<"=>[NULL]\n";
}

void NthNodeFromLast(struct node* head, int n)
{
    int len = 0;
    struct node* temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    if ( len < n )
        return ;

    temp = head;
    for( int i = 1; i < (len - n + 1); i++)
    {
        temp = temp->next;
    }
    std::cout<<n<<" th node from Last:"<<temp->data<<"\n";
}

int main()
{
    struct node* head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 6);
    push(&head, 7);
    printList(head);
    NthNodeFromLast(head,4);
    return 0;
}
