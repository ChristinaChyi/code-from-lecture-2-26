#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct LinkedList {
    Node *head;
    Node *tail;
};

int main(int argc, char *argv[])
{
    // an empty linked list has a NULL head and tail
    LinkedList *l = new LinkedList;
    l->head = NULL;
    l->tail = NULL;

    // if you're only working with Nodes, a NULL pointer to a
    // Node represents an empty list
    Node *n = NULL; // n represents an empty list

    return 0;
}