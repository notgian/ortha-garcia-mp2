#include <stdio.h>

int main()
{
    struct node {
        int data;
        struct node *next;
    };

    struct node root;
    struct node node1;
    struct node node2;

    root.data = 1;
    node1.data = 3;
    node2.data = 5;

    *node1.next = node2;
    *root.next = node1;

    return 0;
}
