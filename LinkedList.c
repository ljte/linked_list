#include "linkedlist.h"
#include "stdio.h"

Node* new_node(const int val, Node* next) {
    Node* newNode = (Node*)malloc(sizeof(newNode));

    newNode->next = next;
    newNode->cargo = val;

    return newNode;
}

LinkedList new_linked_list(void) {
    LinkedList list;

    list.head = NULL;
    list.size = 0;

    return list;
}

void print_linked_list(LinkedList list) {
    if (!list.head) {
        printf("Empty list");
    }
    else {
        Node* temp =  list.head;
        while(temp) {
            printf("%d ", temp->cargo);
            temp = temp->next;
        }
    }
    printf("\n");
}

LinkedList push_back_node(LinkedList list, const int val) {
    if (!list.head) {
        list.head = new_node(val, NULL);
    }
    else {
        Node* temp = list.head;
        while(temp->next) {
            temp = temp->next;
        }

        temp->next = new_node(val, NULL);
    }
    list.size++;
    return list;
}

LinkedList push_front_node(LinkedList list, const int val) {
    list.head = new_node(val, list.head);
    list.size++;
    return list;
}

LinkedList pop_back_node(LinkedList list) {
    if (!list.head->next) {
        free(list.head);
        list.head = NULL;
    }
    else {
        Node* temp = list.head;
        while(temp->next->next) {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
    list.size--;
    return list;
}

LinkedList pop_front_node(LinkedList list) {
    if (!list.head->next) {
        free(list.head);
        list.head = NULL;
    }
    else {
        Node* temp = list.head;
        list.head = list.head->next;

        free(temp);
        temp = NULL;
    }
    list.size--;
    return list;
}

LinkedList remove_node(LinkedList list, const unsigned index) {
    if (index == 0) {
        list = pop_front_node(list);
    }
    else if (index == list.size - 1) {
        list = pop_back_node(list);
    }
    else {
        Node* temp = list.head;
        for (unsigned i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        // toDelete is the node that will be removed
        Node* toDelete = temp->next;
        temp->next = toDelete->next;

        free(toDelete);
        toDelete = NULL;
    }
    list.size--;
    return list;
}

LinkedList insert_node(LinkedList list, const int val, const unsigned index) {
    if (index == 0) {
        list = push_front_node(list, val);
    }
    else if (index == list.size - 1) {
        list = push_back_node(list, val);
    }
    else {
        Node* temp = list.head;
        for (unsigned i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }

        Node* AfterIndserted = temp->next;
        temp->next = new_node(val, AfterIndserted);
    }
    list.size++;
    return list;
}

LinkedList clear(LinkedList list) {
    while(list.head) {
        list = pop_front_node(list);
    }
    return list;
}
