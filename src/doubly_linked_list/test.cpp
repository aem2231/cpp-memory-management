#include "doubly_linked_list.cpp"

int main() {
  DoublyLinkedList list;
  list.push_front(3);
  list.push_front(5);
  list.push_front(8);

  list.print_debug();
  std::cout << "______________\n";
  list.pop_back();
  list.print_debug();
}
