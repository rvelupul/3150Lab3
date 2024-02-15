#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
   
    struct node *linked_list = build_linked_list(10);
    print_linked_list(linked_list, 10);

    pointer_jumping(linked_list, 10);
    print_linked_list_by_jumpers(linked_list, 10);

    node **array_of_ptrs = array_pts_to_each_element_in_linked_list(linked_list, 10);
    if (array_of_ptrs != nullptr) {
       
        advance_jumpers_double(array_of_ptrs, 10);
        print_array_list(array_of_ptrs, 10);

        delete[] array_of_ptrs;
    }

    delete_linked_list(linked_list, 10);

    return 0;
}

