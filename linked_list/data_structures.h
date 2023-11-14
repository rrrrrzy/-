#include <iostream>

/**
 * my_node Struct
 */

typedef struct my_node {

    int value;             // Value stored in the node
    struct my_node* next;  // Pointer to the next node in the list

} Node;  // Typedef Node as a pointer to the 'my_node' struct

// Constructor & Destructor
Node* create_my_node(int value) {
    Node* temp = new Node;
    temp->value = value;
    temp->next = NULL;
    return temp;
}
void delete_my_node(Node* node) {
    delete node->next;
    node->next = NULL;
}

// Interface for retrieving data from a my_node object
int get_value(Node* node) {   // Function to get the value of the node
    return node->value;
}
Node* get_next(Node* node) {  // Function to get the next node
    return node->next;
}

/**
 * linked_list Class
 */

class linked_list {

    // REPLACE ______ WITH YOUR CODE
    friend std::istream& operator>>(std::istream& input, linked_list& list);
    friend std::ostream& operator<<(std::ostream& cout, linked_list& list);

private:
    Node* head;  // Pointer to the head of the linked list
    // Notice: head doesn't store any data except the pointer
public:
    // Constructor & Destructor
    linked_list() {
        head = create_my_node(-1);
        head->next = NULL;
    }
    ~linked_list() {
        delete_all_node(head);
    }

    // Methods of linked_list Class
    void insert(int value) {  // Function to insert a value into the linked list
        Node* p;
        p = head;
        while (get_next(p) != NULL) {
            p = get_next(p);
        }
        p->next = create_my_node(value);
    }
    
    int operator[](int index) {  // Overloaded operator to access elements by index
        if (index >= size()) return -2300000;
        int times = -1;
        Node* p = head;
        while (times != index) {
            times++;
            p = get_next(p);
        }
        return get_value(p);
    }

    int find(int value) {  // Function to find a value in the linked list and return its index
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

    bool is_found(int value) {  // Function to check if a value is found in the linked list
        if (find(value) != -2300000) return  true;
        else return false;
    }

    void remove(int value) {  // Function to remove a value from the linked list
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

    // ADD MORE METHODS HERE
    int size(){
        int nums = 0;
        Node* p;
        p = head;
        while (get_next(p) != NULL) {
            nums++;
            p = get_next(p);
        }
        return nums;
    }
    void update(int oldValue, int newValue) {
        if (find(oldValue) == -2300000) {
            std::cout << "No Element\n";
            return;
        }
        Node* p = get_next(head);
        while (get_value(p) != oldValue) p = get_next(p);
        p->value = newValue;
    }

private:
    void delete_all_node(Node* node) {
        if (node->next == NULL) return;
        delete_all_node(node->next);
        delete node;
    }
};

// Overloaded input stream operator to read 'linked_list' from input
std::istream& operator>>(std::istream& input, linked_list& list) {
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
