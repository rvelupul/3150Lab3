#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

TEST_CASE("build_linked_list function") {
    struct node* list = build_linked_list(5);
    REQUIRE(list != nullptr); 
    node* temp = list;
    for(int i = 1; i <= 5; ++i) {
        CHECK_EQ(temp->data, i); 
        temp = temp->next;
    }
    delete_linked_list(list, 5);
}

TEST_CASE("pointer_jumping function") {
    node* list = build_linked_list(5);
    pointer_jumping(list, 5);
    node* temp = list;
    while(temp->next != temp) { 
        CHECK_EQ(temp->jump->data, 5); 
        temp = temp->next;
    }
    delete_linked_list(list, 5);
}

TEST_CASE("advance_jumpers_double function") {
    node* list = build_linked_list(5);
    pointer_jumping(list, 5); 
    node** array = array_pts_to_each_element_in_linked_list(list, 5);
    advance_jumpers_double(array, 5);
  
    for (int i = 0; i < 5; ++i) {
        CHECK_EQ(array[i]->jump->data, 5);
    }
    delete[] array;
    delete_linked_list(list, 5);
}

TEST_CASE("array_pts_to_each_element_in_linked_list function") {
    node* list = build_linked_list(3);
    node** array = array_pts_to_each_element_in_linked_list(list, 3);
    REQUIRE(array != nullptr);
    for (int i = 0; i < 3; ++i) {
        CHECK_EQ(array[i]->data, i + 1); 
    }
    delete[] array;
    delete_linked_list(list, 3);
}
