#include "data_structures.h"

/**
 * my_node Struct
 */

// Constructor
Node *create_my_node(int value) {
    Node* temp = new Node;
    temp->value = value;
    temp->next = NULL;
    return temp;
}

// Destructor
void delete_my_node(Node *node) {
    delete node;
}

// Interface for retrieving data from a my_node object
int get_value(Node *node) {   // Function to get the value of the node
    return node->value;
}

Node *get_next(Node *node) {  // Function to get the next node
    return node->next;
}

/**
 * linked_list Class
 */

// Constructor
linked_list::linked_list() {
    // create a node with value -1
    // this node will be the head of the linked list

    // STEP 1
    head = create_my_node(-1);
    // STEP 2
    head->next = NULL;
}

// Destructor
linked_list::~linked_list() {
    Node *current = head;
    while (current != NULL) {
        Node *next = get_next(current);
        delete_my_node(current);
        current = next;
    }
}

// STEP 2
// Overloaded input stream operator to read 'linked_list' from input
void linked_list::insert(int value) {
    Node *new_node = create_my_node(value);

    Node *current = head;
    while (get_next(current) != NULL) {
        current = get_next(current);
    }
    current->next = new_node;
}
std::istream &operator>>(std::istream &input, linked_list &list) {
    int value;
    for (int i = 0; i < 5; i++) {
        input >> value;
        list.insert(value);
    }
    return input;
}

// Overloaded output stream operator to write 'linked_list' to output
// REPLACE ______ WITH YOUR CODE
std::ostream& operator<<(std::ostream& cout, linked_list& list) {
    int nums = list.size();
    for (int i = 0; i < nums; i++) {
        std::cout << list[i] << " ";
    }
    return cout;
}

// STEP 3
// Overloaded operator to access elements by index
int linked_list::operator[](int index) {
    if (index >= size()) return -2300000;
    int times = -1;
    Node* p = head;
    while (times != index) {
        times++;
        p = get_next(p);
    }
    return get_value(p);
}

// STEP 4
// Function to find a value in the linked list and return its index
int linked_list::find(int value) {
    if (size() == 0) return -2300000;
    Node* p = get_next(head);
    int times = 0;
    while (get_value(p) != value && get_next(p) != NULL) {
        p = get_next(p);
        times++;
    }
    if ((get_next(p) == NULL && get_value(p) == value) || get_next(p) != NULL) {
        return times;
    }
    else {
        return -2300000;
    }
}
// Function to check if a value is found in the linked list
bool linked_list::is_found(int value) {
    if (find(value) != -2300000) return  true;
    else return false;
}

// STEP 5
// Function to remove a value from the linked list
void linked_list::remove(int value) {
    if (find(value) == -2300000) {
        std::cout << "No Element\n";
        return;
    }
    Node* p = head->next;
    Node* j = head;
    int times = 0;
    while (get_value(p) != value) {
        j = p;
        p = get_next(p);
        times++;
    }
    if (get_next(p) != NULL) {
        j->next = get_next(p);
        delete p;
    }
    else if (get_next(p) == NULL) {
        j->next = NULL;
        delete p;
    }
}

// STEP 6
// ***YOUR CODE HERE***
int linked_list::size(){
    int nums = 0;
    Node* p;
    p = head;
    while (get_next(p) != NULL) {
        nums++;
        p = get_next(p);
    }
    return nums;
}
void linked_list::update(int oldValue, int newValue) {
    if (find(oldValue) == -2300000) {
        std::cout << "No Element\n";
        return;
    }
    Node* p = get_next(head);
    while (get_value(p) != oldValue) p = get_next(p);
    p->value = newValue;
}