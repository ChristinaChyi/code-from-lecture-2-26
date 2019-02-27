#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct LinkedList {
    Node *head; // the first Node in the list
    Node *tail; // the last Node in the list
};

int main(int argc, char *argv[])
{
    // empty lists involve lots of NULLs

    LinkedList *l = new LinkedList;
    l->head = NULL;
    l->tail = NULL;

    // if you only were using Nodes to represent a linked list,
    // you'd set your head Node pointer to NULL
    Node *head = NULL;

    return 0;
}