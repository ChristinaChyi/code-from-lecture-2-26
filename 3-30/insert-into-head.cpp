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

void insertToHeadOfList(LinkedList* h, int value) {
    // make a new Node to hold the value
    Node *n = new Node;
    n->data = value;

    // set that Node's next pointer to be the old head
    n->next = h->head;

    // set h's head to be that new Node
    h->head = n;

    // if we started with an empty list, we better also
    // set the tail
    if (h->tail == NULL) {
        h->tail = n; 
        // now n is *both* the first and last element of the list
        // (because there's only one element)
    }
}

int main(int argc, char *argv[])
{
    // let's make a linked list with 1, 2, and 3 in it!
    Node *one = new Node;
    one->data = 1; // equivalent to (*one).data = 1;

    Node *two = new Node;
    two->data = 2; 

    Node *three = new Node;
    three->data = 3;

    one->next = two;
    two->next = three;
    three->next = NULL;

    LinkedList *l = new LinkedList;
    l->head = one;
    l->tail = three;

    // let's add 0 to the front of our list l
    insertToHeadOfList(l, 0);

    return 0;
}