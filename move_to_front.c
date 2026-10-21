#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int             data;
    struct s_list   *next;
}   t_list;

t_list *add_node(int data)
{
    t_list *node = malloc(sizeof(t_list));

    if (!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    return (node);
}

void print_list(t_list *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void move_to_front(t_list **head, t_list *node)
{
    t_list *current;
    current = *head;
    while (current->next && current->next != node)
        current = current->next;
    current->next = node->next;
    node->next = *head;
    *head = node;
}

int main(void)
{
    t_list *head;
    t_list *a;
    t_list *b;
    t_list *c;
    t_list *d;
    a = add_node(10);
    b = add_node(20);
    c = add_node(30);
    d = add_node(40);
    if (!a || !b || !c)
        return (1);

    head = a;
    a->next = b;
    b->next = c;
    c->next = d;
    printf("Before: ");
    print_list(head);

    move_to_front(&head, c);

    printf("After:  ");
    print_list(head);

    free(a);
    free(b);
    free(c);
    return (0);
}
