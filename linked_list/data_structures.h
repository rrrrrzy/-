#include <iostream>

/**
 * my_node Struct
 */

typedef struct my_node {

    int value;             // Value stored in the node
    struct my_node *next;  // Pointer to the next node in the list

} Node;  // Typedef Node as a pointer to the 'my_node' struct

// Constructor & Destructor
Node *create_my_node(int value);
void delete_my_node(Node *node);

// Interface for retrieving data from a my_node object
int get_value(Node *node);   // Function to get the value of the node
Node *get_next(Node *node);  // Function to get the next node

/**
 * linked_list Class
 */

class linked_list {

    // REPLACE ______ WITH YOUR CODE
    friend std::istream& operator>>(std::istream& input, linked_list& list);
    friend std::ostream& operator<<(std::ostream& cout, linked_list& list);


private:
    Node *head;  // Pointer to the head of the linked list

public:
    // Constructor & Destructor
    linked_list();
    ~linked_list();

    // Methods of linked_list Class
    void insert(int value);  // Function to insert a value into the linked list

    int operator[](int index);  // Overloaded operator to access elements by index

    int find(int value);  // Function to find a value in the linked list and return its index

    bool is_found(int value);  // Function to check if a value is found in the linked list

    void remove(int value);  // Function to remove a value from the linked list

    // ADD MORE METHODS HERE

    int size();  // Function to get the number of the nodes in linked list

    void update(int oldValue, int newValue);  // Function to replace the old value by a new value
};

// Overloaded input stream operator to read 'linked_list' from input
std::istream &operator>>(std::istream &input, linked_list &list);

// Overloaded output stream operator to write 'linked_list' to output
// REPLACE ______ WITH YOUR CODE
std::ostream& operator<<(std::ostream& cout, linked_list& list);
