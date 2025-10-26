#include <iostream>
#include <stdexcept>

class LinkedList{
private:
  struct Node { // a node class, which will store the data at the node and the memory address of the next node
    int data;
    Node* next = nullptr; // pointer to the next node, set to nullptr as there is no next node upon initalization
  };

  // we need to know where the linked list starts and ends
  Node* head; // first node
  Node* tail; // last node

public:
  LinkedList() {
    head = nullptr; // set to nullptr to initialize a node
    tail = nullptr;
  }

  ~LinkedList() {
    Node* curr = head;
    while (curr != nullptr) { // iterate through nodes until all memory is freed
      Node* next = curr->next; // store next before deleting current
      delete curr; // free memory
      curr = next; // and move to the next node
    }
  }

  void print_debug() const {
    Node* curr = head;
    while(curr != nullptr) {
      if (curr->next != nullptr) {
        std::cout
        << "Node at " << curr
        << " data: " << curr->data
        << " next: " << curr->next->data
        << std::endl;
        curr = curr->next;
      } else {
        std::cout
        << "Node at " << curr
        << " data: " << curr->data
        << " next: " << nullptr
        << std::endl;
        curr = curr->next;
      }
    }
  }

  void push_front(int element) {
    Node* newNode = new Node; // initalize a pointer to memory allocated for Node
    newNode->data = element; // -> is shorthand for derefenerencing a pointer to an object
    newNode->next = head; // in the case we are inserting the first element, next will be null, otherwise it points to the netx element
    head = newNode; // newNode is a pointer, so we assign it to head so that head is pointing to the first node
    if (tail == nullptr) { // when tail is equal to nothing, it means the list was empty before adding an element at the front
      tail = newNode; // so we point tail to newNode, which in this case is the first and last element of the linked list
    }
  }

  void push_back(int element) {
    Node* newNode = new Node;
    if (head == nullptr) {
      head = newNode;
    } else {
      tail->next = newNode; // tail points to what would've been the last node before calling push_back, so we can set the pointer in the previous node using tail
    }
    newNode->data = element;
    newNode->next = nullptr; // last element of the list points to nothing
    tail = newNode; // and finally we update the tail to point to the new last node
  }

  void pop_front() {
    if (head == nullptr) {
      throw std::underflow_error("Cannot pop from empty list");
    }
    if (head->next == nullptr) { // when head->next is null, there is only one element in the list
      delete head;
      tail = nullptr; // so we set tail to null
      head = nullptr; // and head
      return; // and return, nothign left to do
    }
    Node* new_head = head->next; // and store head
    delete head; // and free the memory previously used by the node pointed to by head
    head = new_head; // finally update head
  }

  void pop_back() { // O(n), since we need to traverse the list to pop the last node
    if (head == nullptr) {
      throw std::underflow_error("Cannot pop from empty list");
    }
    Node* curr = head;
    if (head->next == nullptr) {
      delete curr; // we can just delete curr when there is only one element in the list
      head = nullptr; // and finally set head and tail to null to avoid dangling pointers
      tail = nullptr;
      return;
    } else {
      while (curr->next != tail) { // traverse linked list until the next element is equal to tail
        curr=curr->next; // increment curr
      }
      delete curr->next; // delete the last element
      curr->next = nullptr; // set next value of the now final node to null
      tail=curr; // and finally update tail
    }
  }

  void insert(int index, int element) {
    int i = 0; // initialize a varible to track which index we are at
    Node* curr = head;

    if (index < 0) {
      throw std::out_of_range("Index out of range");
    }

    if (index == 0) { // no need to change the value of next in other nodes when we insert at 0
      Node* newNode = new Node;
      Node* old_head = head; // save the old head
      head = newNode; // update the head
      newNode->next = old_head; // old head stll points to old index 0 (now index 1)
      newNode->data = element;
      return;
    }

    // traverse the list until we have reached the index before the one we are inserting at
    // so we can also update node->next of the node before it
    // or we reach the end
    while (i < index-1 && curr != nullptr) {
      curr = curr->next;
      i++;
    }

    if (curr == nullptr) { // if we did reach the end, it means the index is out of range
      throw std::out_of_range("Index out of range"); // so throw an error
    }

    Node* newNode = new Node; // create a new node
    Node* old_next = curr->next; // save the value of curr->next, so we know where newNode->next should point to
    if (old_next == nullptr) {
      tail = newNode; // update tail in the case that  the newNode is at the end of the list
    }
    curr->next = newNode; // point next of the previous node to newNode
    newNode->next = old_next;
    newNode->data = element;
  }

  void erase(int index) {
    int i = 0;
    Node* curr = head;

    if (index < 0) {
      throw std::out_of_range("Index out of range");
    }

    if (index == 0) {
      Node* new_head = head->next;
      delete head;
      head = new_head;
      if (head == nullptr) { // account for the edge case of the list being empty
        tail = nullptr;
      }
      return;
    }

    while (i < index-1 && curr!=nullptr) { // traverse the list unti we reach the index before the one we are looking for
      i++;                                 // or until we reach the end
      curr = curr->next;
    }
    Node* to_erase = curr->next; // create a copy of curr->next

    if (to_erase == nullptr) { // if to_erase (curr->next) is null, the index is out of range
      throw std::out_of_range("Index out of range");
    }

    if (to_erase == tail) {
      tail = curr; // if tail points to to_erase, we need to update tail to curr
    }

    curr->next = to_erase->next; // and assign to_erase->next (curr->next->next) to curr->next
    delete to_erase; // and free the memory used by curr->next
  }
};
