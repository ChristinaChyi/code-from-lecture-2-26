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
    Node *one = new Node;
    one->data = 1;

    Node *two = new Node;
    two->data = 2;

    Node *three = new Node;
    three->data = 3;

    one->next = two; // equivalent to (*one).next = two;
    two->next = three;
    three->next = NULL;

    LinkedList *l = new LinkedList;
    l->head = one;
    l->tail = three;

    return 0;
}