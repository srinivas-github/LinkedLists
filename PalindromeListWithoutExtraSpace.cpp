#include <cstdio>
#include <cstdlib>

struct Node
{
    char data;
    struct Node* next;
};

void push(struct Node** head_ref, char c)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = c;
    temp->next = (*head_ref);
    (*head_ref)= temp;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    for(; temp != NULL; temp = temp->next)
    {
        printf("[%c]->", temp->data);
    }
    printf("[NULL]\n");
}

bool isPalinUtil(struct Node** left, struct Node* right)
{
    if (right == NULL)
        return true;

    bool isp = isPalinUtil(left, right->next);
    if (isp == false)
        return false;

    bool isp1 = (right->data == (*left)->data);
    *left = (*left)->next;
    return isp1;
}

bool isPalindrome(struct Node* head)
{
    return isPalinUtil(&head, head);
}

int main()
{
    struct Node* head = NULL;
    char str[] = "abacabaa";
    for(int i = 0; str[i] != '\0'; i++)
    {
        push(&head, str[i]);
    }
    printList(head);
    isPalindrome(head)?printf("Is Palindrom\n"):printf("Not a Palindrome\n");
    return 0;
}
