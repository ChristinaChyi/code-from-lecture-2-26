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

void freeLinkedList(LinkedList *list) {
    /* Free all the memory that was created on the heap*/

    /* 
    You can't do something like this:
    delete list;
    delete list->head;
    using list after deleting list is undefined behavior
    */

    // so, let's delete all the nodes before the list itself
    Node *n = list->head; 
    while (n != NULL) {
        Node *next = n->next;
        delete n;
        n = next;
    }

    delete list;
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

    freeLinkedList(l);

    return 0;
}