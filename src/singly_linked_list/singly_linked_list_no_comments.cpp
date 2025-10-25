#include <iostream>
#include <stdexcept>

class LinkedList{
private:
  struct Node {
    int data;
    Node* next = nullptr;
  };


  Node* head;
  Node* tail;

public:
  LinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  ~LinkedList() {
    Node* curr = head;
    while (curr != nullptr) {
      Node* next = curr->next;
      delete curr;
      curr = next;
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
    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
      tail = newNode;
    }
  }

  void push_back(int element) {
    Node* newNode = new Node;
    if (head == nullptr) {
      head = newNode;
    } else {
      tail->next = newNode;
    }
    newNode->data = element;
    newNode->next = nullptr;
    tail = newNode;
  }

  void pop_front() {
    if (head == nullptr) {
      throw std::underflow_error("Cannot pop from empty list");
    }
    if (head->next == nullptr) {
      tail = nullptr;
    }
    Node* new_head = head->next;
    delete head;
    head = new_head;
  }

  void pop_back() {
    if (head == nullptr) {
      throw std::underflow_error("Cannot pop from empty list");
    }
    Node* curr = head;
    if (head->next == nullptr) {
      delete curr;
    } else {
      while (curr->next != tail) {
        curr=curr->next;
      }
      delete curr->next;
      curr->next = nullptr;
      tail=curr;
    }
  }
};
