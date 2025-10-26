#include "singly_linked_list.cpp"
#include <stdexcept>

int main() {
    LinkedList list;

    // Build initial list
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    std::cout << "=== Initial list ===\n";
    list.print_debug();

    // Test erase first
    std::cout << "\n=== Erase index 0 ===\n";
    list.erase(0);
    list.print_debug();

    // Test erase middle
    std::cout << "\n=== Erase index 1 (middle) ===\n";
    list.erase(1);
    list.print_debug();

    // Test erase last
    std::cout << "\n=== Erase last element ===\n";
    list.erase(1);  // Should now be last
    list.print_debug();

    // Test push after erasing last
    std::cout << "\n=== Push after erasing last ===\n";
    list.push_back(50);
    list.print_debug();

    return 0;
}
