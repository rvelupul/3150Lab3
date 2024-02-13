#include <iostream>
#include "linked_list.h"

using namespace std;

struct node *build_linked_list(int number_of_nodes) {
    if (number_of_nodes == 0) {
        return nullptr;
    } 
    struct node *root = new node{nullptr, nullptr, 1};
    struct node *current = root;
    for (int i = 1; i < number_of_nodes; i++) {
        current->next = new node{nullptr, nullptr, i + 1};
        current = current->next;
    }
    current->next = root; 
    struct node *last = current; 
   
    current = root;
    while (current != last) {
        current->jump = last;
        current = current->next;
    }
    current->jump = last; 
    return root;
}

void print_linked_list(struct node *first, int number_of_nodes) {
    struct node *current = first;
    for (int i = 0; i < number_of_nodes; i++) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void delete_linked_list(struct node *first, int number_of_nodes) {
    struct node *current = first;
    while (number_of_nodes--) {
        struct node *next = current->next;
        delete current;
        current = next;
        if (current == first) {
            break;
        }  
    }
}

void pointer_jumping(struct node *first, int number_of_nodes) {
    struct node *last = first;
    while (last->next != first) { 
        last = last->next;
    }
    struct node *current = first;
    do {
        current->jump = last;
        current = current->next;
    } while (current != first);
}

void print_linked_list_by_jumpers(struct node *first, int number_of_nodes) {
    if (first == nullptr || number_of_nodes <= 0) return; 

    struct node *current = first;
    cout << "List with Jumpers: ";
    for (int i = 0; i < number_of_nodes; i++) {
        cout << current->data << " ";
        if (current->jump == current) { 
            break;
        }
        current = current->jump;
    }
    cout << endl;
}

