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

LinkedList* arrayToLinkedList(int a[], int size) {
    // let's build up our final answer
    Node *list_so_far = NULL; // I haven't made anything yet

    for (int i = size-1; i >= 0; i--) {
        // make a new node
        Node *n = new Node;
        n->data = a[i];
        // set its next pointer to be the list I've made
        // so far    
        n->next = list_so_far;
        // the list I've made so far is bigger now
        list_so_far = n;
    }

    // at the end, list so far is the head of the list
    LinkedList *l = new LinkedList;
    l->head = list_so_far;

    // we need to find the tail
    if (l->head == NULL) {
        l->tail = NULL;
    } else {
        Node *n = l->head;
        // keep going while we haven't reached the end
        while (n->next != NULL) {
            // iterate further
            n = n->next;
        }
        // now, n is at the tail
        l->tail = n;
    }
    // we could have set the tail to be the first node we ever
    // made

    return l;
}

void printList(LinkedList *list) {
    for (Node *n = list->head; n != NULL; n = n->next) {
        cout << n->data << "->";
    }
    cout << "X\n";
}

// alternatively, you could have used the insertToHeadOfList
// function for each element of your array

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3};

    LinkedList *arr_as_list = arrayToLinkedList(arr, 3);

    printList(arr_as_list);

    return 0;
}