#include <stdexcept>
#include <cstddef>

using namespace std;

class DynamicArray {
  private:
  int* arr_start; // points to the memory address of the element at index 0
  size_t size; // the amount of elements in the array
  size_t capacity; // the amount of memory to be allocated for the array

  public:
  DynamicArray(size_t inital_capacity) {
    size = 0; // array is always empty when initalized, so size is 0
    capacity = inital_capacity; // memory to be allocated
    arr_start = new int[capacity]; // allocates amount of memory given in capacity to the heap
  };

  ~DynamicArray() {
    delete[] arr_start; // free the memory when DynamicArray goes out of scope
    arr_start = nullptr; // ensure we dont have a dangling pointer
  }

  // method to add an element to an array
  void push_back(int element) {
    if (size < capacity) { // if we are not at capacity we can just add the element
      arr_start[size] = element;
      size++;
    }
    else if (size == capacity)
    { // but if we are at capacity we need to resize the array (make more room)
      capacity = capacity*2; // double the capacity (avoid frequent resizing)
      int* new_arr_start = new int[capacity]; // allocate the new capacity to the heap
      for(int i = 0; i < size; i++) {
        new_arr_start[i] = arr_start[i]; // copy elemenets into the new array
      };
      delete[] arr_start; // free old memory
      arr_start = new_arr_start;
      arr_start[size] = element;
      size++;
    };
  };

  void pop_back() {
    if (size == 0) {
      throw out_of_range("Empty array");
    }
    arr_start[size-1] = 0; // set the last element of the array to 0 for debugging purposes
    size--; // decrement size by 1 so the last element is 'invisble'
  }

  void insert(int index, int element) {
    if (index > size) {
      throw out_of_range("Index is out of range.");
    }

    if (size == capacity) { // check if the array is at capacity
      capacity = capacity*2; // if it is we double it
      int* new_arr_start = new int[capacity];  // then a new array
      for (int i = 0; i < size; i++) {  // and copy the old array to the new one
        new_arr_start[i] = arr_start[i];
      }
      delete[] arr_start; // and free the memory from the old array
      arr_start = new_arr_start;
    }
    for (int i = size; i > index; i--) { // iterate through the array from
      arr_start[i] = arr_start[i-1];
    }
    size++; // increment size to account for the new element
    arr_start[index] = element; // finally, insert the new element
  }

  void erase(int index) {
    if (index > size - 1) {
      throw out_of_range("Index is out of range");
    }
    arr_start[index] = 0;
    for (int i = index; i < size-1; i++) { // 2 to so that when we reach that last element
      arr_start[i] = arr_start[i+1]; // we dont try and access an element that doesnt exists
    }
    size--;
    arr_start[size] = 0;
  }

  // '&' allows us to modify the element directly by returning a reference
  // this means we dont have to copy it, so there is less overhead
  // 'operator[]' allows us to overload the [] operator to be used for indexing by our class

  int& operator[](size_t index) {
    if (index > size-1) {
      throw out_of_range("Index is out of range"); // we need to manually throw out of range errors
    }
    return arr_start[index];
  };

  size_t get_size() const {
    return size;
  }

  size_t get_capacity() const {
    return capacity;
  }
};
