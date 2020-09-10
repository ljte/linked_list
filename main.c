#include "stdio.h"
#include "linkedlist.h"


int main(int argc, char const *argv[]) {
    LinkedList list = new_linked_list();

    list = push_back_node(list, 10);
    list = push_back_node(list, 20);
    list = push_front_node(list, 0);
    // list = push_back_node(list, 30);
    // list = push_back_node(list, 40);
    print_linked_list(list);
    list = insert_node(list, 30, 2);
    print_linked_list(list);

    list = clear(list);
    return 0;
}
