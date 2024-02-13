#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
    struct node *linked_list = build_linked_list(5);
    print_linked_list(linked_list, 5);
    pointer_jumping(linked_list, 5); 
    print_linked_list_by_jumpers(linked_list, 5);
    delete_linked_list(linked_list, 5);

    return 0;
}

