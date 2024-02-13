#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"


TEST_CASE("Testing build_linked_list function") {
    node* list = build_linked_list(5);
    node* temp = list;
    for(int i = 1; i <= 5; ++i) {
        CHECK_EQ(temp->data, i);
        temp = temp->next;
    }
    delete_linked_list(list, 5); 
}

TEST_CASE("Testing pointer_jumping function") {
    node* list = build_linked_list(5);
    pointer_jumping(list, 5);
    node* temp = list;
    while(temp->next != list) { 
        temp = temp->next;
    }
    node* last = temp; 
    temp = list;
    do {
        CHECK_EQ(temp->jump, last);
        temp = temp->next;
    } while(temp != list);
    delete_linked_list(list, 5); 
}

TEST_CASE("Testing build_linked_list for circular list property") {
    int size = 3;
    node* list = build_linked_list(size);
    node* temp = list;
   
    for(int i = 1; i < size; ++i) {
        temp = temp->next;
    }
    
    REQUIRE(temp->next == list);
    delete_linked_list(list, size); 
}

TEST_CASE("Testing pointer_jumping with a single-node list") {
    node* list = build_linked_list(1); 
    pointer_jumping(list, 1); 

    REQUIRE(list->jump == list);

    delete_linked_list(list, 1); 
}
