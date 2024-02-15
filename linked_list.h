#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

struct node {
    node *next;
    node *jump;
    int data;
};

struct node *build_linked_list(int total_elements);
void print_linked_list(struct node *first, int number_of_nodes);
void delete_linked_list(struct node *first, int number_of_nodes);
void pointer_jumping(struct node *first, int number_of_nodes);
void print_linked_list_by_jumpers(struct node *first, int number_of_nodes);
int print_array_list(struct node **list, const int elements);
int advance_jumpers_double(struct node **array_pts, const int elements);
node **array_pts_to_each_element_in_linked_list(node *original_list, const int elements);

#endif 
