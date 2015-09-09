#include <cstdio>
#include <cstdlib>
/**
 * 1. Calculate sizes of given two linked lists.
 * 2. If sizes are same, then calculate sum using recursion. 
 *    Hold all nodes in recursion call stack till the rightmost node, 
 *    calculate sum of rightmost nodes and forward carry to left side.
 * 3. If size is not same, then follow below steps:
 *        a. Calculate difference of sizes of two linked lists. Let the difference be diff
 *        b. Move diff nodes ahead in the bigger linked list. Now use step 2 to calculate sum of 
 *           smaller list and right sub-list (of same size) of larger list. Also, store the carry of this sum.
 *        c. Calculate sum of the carry (calculated in previous step) with the remaining left sub-list of larger list. 
 *           Nodes of this sum are added at the beginning of sum list obtained previous step.
 */

struct Node
{
    int data;
    struct Node* next;    
};

void push(struct Node** head_ref, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = (*head_ref);
    (*head_ref) = temp;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
    {
        printf("[%d]->", temp->data);
    }
    printf("[NULL]\n");
}

void swapPointer(struct Node** a, struct Node** b)
{
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

int getSize(struct Node* head)
{
    int sz = 0;
    while (head != NULL)
    {
        head = head->next;
        sz++;
    }
    return sz;
}

struct Node* addSameSize(struct Node* head1, struct Node* head2, int *carry)
{
    if (head1 == NULL)
        return NULL;
    int sum;
    struct Node* result = (struct Node*)malloc(sizeof(struct Node));

    result->next = addSameSize(head1->next, head2->next, carry);

    sum = (head1->data) + (head2->data) + *carry;
    *carry = sum/10;
    sum = sum % 10;
    result->data = sum;
    return result; 
}

void addCarryToRemaining(struct Node* head1, struct Node* cur, int *carry, struct Node** result)
{
    int sum;
    if (head1 != cur)
    {
        addCarryToRemaining(head1->next, cur, carry, result);
        sum = head1->data + *carry;
        *carry = sum /10;
        sum = sum % 10;
        push(result, sum);
    }
}

void addList(struct Node* head1, struct Node* head2, struct Node** result)
{
    struct Node* cur;
    if (head1 == NULL)
    {
        *result = head2;
        return ;
    }
    else if(head2 == NULL)
    {
        *result = head1;
        return;
    }

    int sz1 = getSize(head1);
    int sz2 = getSize(head2);
    int carry = 0;
    if (sz1 == sz2)
    {
        *result = addSameSize(head1, head2, &carry);
    }
    else
    {
        int diff = abs(sz1 - sz2);
        if (sz1 < sz2)
            swapPointer(&head1, &head2);

        for(cur = head1; diff--; cur = cur->next);
        *result = addSameSize(cur, head2, &carry);
        addCarryToRemaining(head1, cur, &carry, result); 
    }
    if (carry)
        push(result, carry);
}

int main()
{
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* result = NULL;
    int arr1[] = {9,8,7};
    int sz1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {8, 7};
    int sz2 = sizeof(arr2)/sizeof(arr2[0]);
    int i;
    for(i = sz1-1; i>=0; i--)
        push(&head1, arr1[i]);

    for(i = sz2-1; i>=0; i--)
        push(&head2, arr2[i]);

    addList(head1, head2, &result);
    printList(result);
    return 0;
}
