#include <cstdio>
#include <cstdlib>

struct Node
{
    char c;
    struct Node* next;
};

struct Node* newNode(char c)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->c = c;
    temp->next = NULL;
}

int compare(struct Node* list1, struct Node* list2)
{
    while (list1 && list2 && list1->c == list2->c)
    {
        list1 = list1->next;
	list2 = list2->next;
    }

    if (list1 && list2)
        return (list1->c > list2->c) ? 1 : -1;

    if (list1 && !list2)
        return 1;

    if (list2 && !list1)
        return -1;


    return 0;
}

int main()
{
    Node *list1 = newNode('s');
    list1->next = newNode('a');
    list1->next->next = newNode('m');
    list1->next->next->next = newNode('p');
    list1->next->next->next->next = newNode('e');
    list1->next->next->next->next->next = newNode('e');
			 
    Node *list2 = newNode('s');
    list2->next = newNode('a');
    list2->next->next = newNode('m');
    list2->next->next->next = newNode('p');
    list2->next->next->next->next = newNode('e');
    list2->next->next->next->next->next = newNode('a');
			  
    printf("%d\n", compare(list1, list2));
    return 0;
}
