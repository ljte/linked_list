#ifndef LINKED_LIST
#define LINKED_LIST

#include "stdlib.h"

typedef struct Node {
    int cargo;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    unsigned size;
} LinkedList;

Node* new_node(const int val, Node* next);
LinkedList new_linked_list(void);
void print_linked_list(LinkedList list);
LinkedList push_back_node(LinkedList list, const int val);
LinkedList push_front_node(LinkedList list, const int val);
LinkedList pop_back_node(LinkedList list);
LinkedList pop_front_node(LinkedList list);
LinkedList remove_node(LinkedList list, const unsigned index);
LinkedList insert_node(LinkedList list, const int val, const unsigned index);
LinkedList clear(LinkedList list);

#endif
