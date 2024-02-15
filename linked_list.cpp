#include <iostream>
#include "linked_list.h"

using namespace std;

struct node *build_linked_list(int number_of_nodes) {
    if (number_of_nodes == 0) return nullptr;
    struct node *root = new node{nullptr, nullptr, 1};
    struct node *current = root;
    for (int i = 1; i < number_of_nodes; i++) {
        current->next = new node{nullptr, nullptr, i + 1};
        current = current->next;
    }
    
    current->next = current; 
    struct node *last = current;

    current = root;
    while (current != last) {
        current->jump = last;
        current = current->next;
    }
    last->jump = last; 
    return root;
}

void print_linked_list(struct node *first, int number_of_nodes) {
    struct node *current = first;
    for (int i = 0; i < number_of_nodes; i++) {
        cout << current->data << " ";
        current = current->next;
        if (current == first) { 
            break;
        }
    }
    cout << endl;
}

void delete_linked_list(struct node *first, int number_of_nodes) {
    struct node *current = first;
    struct node *next = nullptr;
    for (int i = 0; i < number_of_nodes; i++) {
        next = current->next;
        delete current;
        current = next;
        if (current == first) {
            break;
        }
    }
}

void pointer_jumping(struct node *first, int number_of_nodes) {
    struct node *last = first;
    while (last->next != last) { 
        last = last->next;
    }
    struct node *current = first;
    do {
        current->jump = last;
        current = current->next;
    } while (current != last); 
    last->jump = last; 
}

void print_linked_list_by_jumpers(struct node *first, int number_of_nodes) {
    if (first == nullptr || number_of_nodes <= 0) {
        cout << "The list is empty or invalid number of nodes." << endl;
        return; 
    }

    struct node *current = first;
    cout << "List with Jumpers: ";
    for (int i = 0; i < number_of_nodes; ++i) {
        cout << current->data << " ";
        if (current->jump == current || current->jump->next == current) { 
            break;
        }
        current = current->jump;
    }
    cout << endl;
}


int print_array_list(struct node **list, const int elements) {
    cout << "print_array_list start" << endl;
    for (int i = 0; i < elements; i++) {
        cout << list[i]->data << " "; 
        cout << "jumper value: " << list[i]->jump->data << " "; 
        cout << endl;
    }
    cout << "print_array_list stop" << endl;
    return elements;
}

int advance_jumpers_double(struct node **array_pts, const int elements) {
    for (int i = 0; i < elements; i++) {
       
        if(array_pts[i]->jump != nullptr && array_pts[i]->jump->jump != nullptr) {
            array_pts[i]->jump = array_pts[i]->jump->jump;
        }
    }
    return elements;
}

node ** array_pts_to_each_element_in_linked_list(node * original_list, const int elements) {
    if(original_list == nullptr || elements <= 0) {
        return nullptr; 
    }

    node **array_of_ptrs = new node*[elements];
    node *current = original_list;
    for (int i = 0; i < elements; i++) {
        array_of_ptrs[i] = current;
        current = current->next;
    }
    return array_of_ptrs; 
}
