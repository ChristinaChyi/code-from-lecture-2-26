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

void insertToHeadOfList(LinkedList* h, int value) {
    // create the new node with the given value
    Node *n = new Node;
    n->data = value;

    // set its next pointer
    n->next = h->head;

    // update the head of the list to be the Node we just made
    h->head = n;

    // if the list was empty, we also need to update the tail
    if (h->tail == NULL) {
        h->tail = n;
    }
}

void printList(LinkedList *l) {
    for (Node *n = l->head; n != NULL; n = n->next) {
        cout << n->data << "->";
    }
    cout << "X\n";
}

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

    printList(l);

    insertToHeadOfList(l, 0);

    printList(l);

    return 0;
}