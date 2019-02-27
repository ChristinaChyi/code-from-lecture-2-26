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

LinkedList* arrayToLinkedList(int a[], int size) {
    // start out with an empty list

    LinkedList *l = new LinkedList;
    l->head = l->tail = NULL;

    // iterate through the list BACKWARDS
    for (int i = size - 1; i >= 0; i--) {
        // add a[i] to the head of l
        insertToHeadOfList(l, a[i]);
    }

    return l;
}

int lengthOfList(LinkedList *list) {
    Node *n = list->head;
    int count = 0;
    while (n != NULL) {
        count++;
        n = n->next;
    }
    // n will NULL when we get there
    return count;
}

void freeLinkedList(LinkedList *list) {
    /* it's undefined to do:
        delete list;
        delete list->head;
       you can't use something after you delete it
    */

    // delete the nodes first
    Node *n = list->head;
    while (n != NULL) {
        // BEFORE I touch n, I better save its next pointer
        // on the stack so that I can use it without running
        // into undefined behavior
        Node *next = n->next;
        delete n;
        n = next;
    }

    delete list;
    list = NULL;
    // at least by doing this if you try to 
    // use list (when you shouldn't have), you'll
    // get a segfault
}

int main(int argc, char *argv[])
{
    int arr[] = {1,2,3};
    LinkedList *l = arrayToLinkedList(arr, 3);
    freeLinkedList(l);

    return 0;
}