#include <iostream>
#include <stdexcept>
#include "dynamic_array.cpp" // include your implementation file

using namespace std;

int main() {
  cout << "=== DynamicArray Test ===" << endl;

  // Create a small dynamic array
  DynamicArray arr(3);
  cout << "Initial capacity: " << arr.get_capacity() << ", size: " << arr.get_size() << endl;

  // Add elements to fill it
  arr.push_back(10);
  arr.push_back(20);
  arr.push_back(30);
  cout << "After push_back 3 elements:" << endl;
  for (size_t i = 0; i < arr.get_size(); ++i) cout << arr[i] << " ";
  cout << " | size: " << arr.get_size() << ", capacity: " << arr.get_capacity() << endl;

  // Insert in the middle
  arr.insert(1, 99);
  cout << "After insert(1, 99):" << endl;
  for (size_t i = 0; i < arr.get_size(); ++i) cout << arr[i] << " ";
  cout << " | size: " << arr.get_size() << ", capacity: " << arr.get_capacity() << endl;

  // Insert at the front
  arr.insert(0, 77);
  cout << "After insert(0, 77):" << endl;
  for (size_t i = 0; i < arr.get_size(); ++i) cout << arr[i] << " ";
  cout << " | size: " << arr.get_size() << ", capacity: " << arr.get_capacity() << endl;

  // Insert at the end
  arr.insert(arr.get_size(), 88);
  cout << "After insert(end, 88):" << endl;
  for (size_t i = 0; i < arr.get_size(); ++i) cout << arr[i] << " ";
  cout << " | size: " << arr.get_size() << ", capacity: " << arr.get_capacity() << endl;

  // Erase first element
  arr.erase(0);
  cout << "After erase(0):" << endl;
  for (size_t i = 0; i < arr.get_size(); ++i) cout << arr[i] << " ";
  cout << " | size: " << arr.get_size() << ", capacity: " << arr.get_capacity() << endl;

  // Erase middle element
  arr.erase(2);
  cout << "After erase(2):" << endl;
  for (size_t i = 0; i < arr.get_size(); ++i) cout << arr[i] << " ";
  cout << " | size: " << arr.get_size() << ", capacity: " << arr.get_capacity() << endl;

  cout << "=== Test Completed ===" << endl;
  return 0;
}
