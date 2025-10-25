#include <iostream>
#include <stdexcept>

class DoublyLinkedList {
private:
  struct Node {
    int data;
    Node* prev = nullptr;
    Node* next = nullptr;
  };

  Node* head;
  Node* tail;

public:
  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  };

  ~DoublyLinkedList() {
    Node* curr = head;
    while (curr != nullptr) {
      Node* next = curr->next;
      delete curr;
      curr = next;
    }
  };

  void print_debug() const {
    Node* curr = head;
    while(curr != nullptr) {
      if (curr->next != nullptr) {
        std::cout
        << "Node at " << curr
        << " data: " << curr->data
        << " next: " << curr->next->data
        << " prev: " << curr->prev
        << std::endl;
        curr = curr->next;
      } else {
        std::cout
        << "Node at " << curr
        << " data: " << curr->data
        << " next: " << nullptr
        << " prev: " << curr->prev
        << std::endl;
        curr = curr->next;
      }
    }
  }

  void push_front(int element) {
    Node* newNode = new Node; // create a pointer to a node
    if (head == nullptr) { //only one element in the list
      head = newNode; // set head to point to the new node
      tail = newNode; // when there is only one element, tail should point to it too
      newNode->next = nullptr; // when theres only one element, next and prev are null
      newNode->prev = nullptr;
      newNode->data = element; // and put some data int the node
    }
    else {
      newNode->next = head; // if there are already elements in the list, newNode->next is equal to head, since head currently points to the old head
      newNode->prev = nullptr; // since were pushing to the front, there is no prev element, so prev is null
      newNode->data = element;
      head->prev = newNode; // update head->prev (head still points to old head) so we can update prev to point to the new head
      head = newNode; // and finally update head to point to the newly created node
    }
  }

  void push_back(int element) {
    Node* newNode = new Node;
    if (head == nullptr){ // same logic as before
      head = newNode;
      tail = newNode;
      newNode->prev = nullptr;
      newNode->next = nullptr;
      newNode->data = element;
    }
    else {
      newNode->prev = tail; // similarly to push_front, we can use the tail (which stil points to the old tail) to update prev of the node before the new node
      newNode->next = nullptr; // last node, so no next
      newNode->data = element;
      tail->next = newNode; // while tail is still pointing to the old last node, we can update the next value of what is to be the second to last node
      tail = newNode; // and finally update tail
    }
  }

  void pop_front() {
    if (head == nullptr) { // once again, check for the case that the list is empty
      throw std::underflow_error("Cannot pop from empty list"); // throw an error this time though
    }
    if (head->next == nullptr) { // check for the case that there is only one element in the list
      Node* temp = head; // temp points to the same node as head
      tail = nullptr; // since there is only one element we need to update head AND tail to nullptr
      head = nullptr;
      delete temp; // delete temp (a pointer to the first node) so the first node is deleted
      return; // exit the function at this point, we do not want to continue in this case
    }
    Node* new_head = head->next; // declare a pointer to the new_head (-> next of current head)
    delete head; // delete head
    new_head->prev = nullptr; // and update the new head
    head = new_head; // and update the head pointer
  }

  void pop_back() { // essentially the same as in pop_front, except using tail instead of head and that the case outside conditionals is inveresed
    if (head == nullptr) {
      throw std::underflow_error("Cannot pop from empty list");
    }
    if (head->next == nullptr) {
      Node* temp = tail;
      tail = nullptr;
      head = nullptr;
      delete temp;
      return;
    }
    Node* new_tail = tail->prev;
    delete tail;
    new_tail->next = nullptr;
    tail = new_tail;
  }
};
