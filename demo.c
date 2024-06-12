#include <stdio.h>
#include <stdlib.h>

typedef struct singly
{
    int n;
    struct singly *next;
} sll;

void create(sll *p)
{
    sll *temp = p;
    for (int i = 0; i < 5; i++)
    {
        if (p == NULL)
        {
            p = (struct Node *)malloc(sizeof(sll));
            p->n = i + 1;
            temp = p;
        }
        else
        {
            temp->next = (struct Node *)malloc(sizeof(sll));
            temp = temp->next;
            temp->n = i + 1;
        }
    }
}

void pri(int ck)
{
    printf("%d", ck);
}

int main()
{
    sll *top = NULL;
    create(top);
    while (top != NULL)
    {
        printf("%d\n", top->n);
        top = top->next;
    }
    // int num = 10;
    // pri(num);
    return 0;
}