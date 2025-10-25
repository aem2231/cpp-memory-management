#include <stdexcept>
#include <cstddef>

using namespace std;

class DynamicArray {
  private:
  int* arr_start; 
  size_t size; 
  size_t capacity; 

  public:
  DynamicArray(size_t inital_capacity) {
    size = 0; 
    capacity = inital_capacity; 
    arr_start = new int[capacity]; 
  };

  ~DynamicArray() {
    delete[] arr_start; 
    arr_start = nullptr; 
  }

  
  void push_back(int element) {
    if (size < capacity) { 
      arr_start[size] = element;
      size++;
    }
    else if (size == capacity)
    { 
      capacity = capacity*2; 
      int* new_arr_start = new int[capacity]; 
      for(int i = 0; i < size; i++) {
        new_arr_start[i] = arr_start[i]; 
      };
      delete[] arr_start; 
      arr_start = new_arr_start;
      arr_start[size] = element;
      size++;
    };
  };

  void pop_back() {
    if (size == 0) {
      throw out_of_range("Empty array");
    }
    arr_start[size-1] = 0; 
    size--; 
  }

  void insert(int index, int element) {
    if (index > size) {
      throw out_of_range("Index is out of range.");
    }

    if (size == capacity) { 
      capacity = capacity*2; 
      int* new_arr_start = new int[capacity];  
      for (int i = 0; i < size; i++) {  
        new_arr_start[i] = arr_start[i];
      }
      delete[] arr_start; 
      arr_start = new_arr_start;
    }
    for (int i = size; i > index; i--) { 
      arr_start[i] = arr_start[i-1];
    }
    size++; 
    arr_start[index] = element; 
  }

  void erase(int index) {
    if (index > size - 1) {
      throw out_of_range("Index is out of range");
    }
    arr_start[index] = 0;
    for (int i = index; i < size-1; i++) { 
      arr_start[i] = arr_start[i+1]; 
    }
    size--;
    arr_start[size] = 0;
  }

  
  
  

  int& operator[](size_t index) {
    if (index > size-1) {
      throw out_of_range("Index is out of range"); 
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
