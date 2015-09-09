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

int compareLists(struct node* head1, struct node* head2)
{
    while (1)
    {
        if (head1 == NULL && head2 == NULL)
        {
            return 1;
        }
        if (head1 == NULL && head2 != NULL)
        {
            return 0;
        }
        if (head1 != NULL && head2 == NULL)
        {
            return 0;
        }
        if (head1->data != head2->data)
        {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
}

int main()
{
    struct node* a = NULL;
    struct node* b = NULL;

    push(&a, 1);
    push(&a, 2);
    push(&a, 3);

    push(&b, 1);
    push(&b, 2);
    push(&b, 3);

    int res = compareLists(a, b);
    std::cout<<"Compare res: "<<res<<"\n";
    return 0;
}
