#include "singly_linked_list.cpp"

int main() {
  LinkedList list;
  list.push_front(3);
  list.push_front(5);
  list.push_front(8);
  list.print_debug();
  std::cout << "Pop back \n";
  list.pop_back();
  list.print_debug();
}
