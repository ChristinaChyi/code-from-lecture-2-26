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

int lengthOfList(LinkedList *list) {
    int size = 0;
    for (Node *n = list->head; n != NULL; n = n->next) {
        // the stopping condition for this loop is whether
        // you're at the end of the list
        size++;
    }
    return size;
}

void printList(LinkedList *list) {
    for (Node *n = list->head; n != NULL; n = n->next) {
        cout << n->data << "->";
    }
    cout << "X\n";
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

    printList(l);
    cout << lengthOfList(l) << endl;

    return 0;
}