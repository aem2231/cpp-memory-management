#include "singly_linked_list.cpp"
#include <stdexcept>

int main() {
  LinkedList list;
  list.push_front(3);
  list.push_front(5);
  list.push_front(8);
  list.print_debug();

  try {
    list.insert(1973, 99);
  } catch (const std::out_of_range& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "Insert\n";
  list.print_debug();

}
