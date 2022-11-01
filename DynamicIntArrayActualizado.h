#include <iostream>

class DynamicIntArray {
        int size;
        int *data;
    public:
      DynamicIntArray() {
        this->size = 0;
        data = new int[0];
      }

      DynamicIntArray(const int arr[], int size){
        this->size = size;
        data = new int[size];
        for(int i = 0; i < size; i++)
          data[i] = arr[i];
      }

      DynamicIntArray(const DynamicIntArray &o) {
        this->size = o.size;
        this->data = new int[o.size];
        for(int i = 0; i < size; i++)
          data[i] = o.data[i];
      }

      int getSize() const {
        return size;
      }

      void print() const {
        std::cout << "[ ";
        for(int i = 0; i < size; i++)
          std::cout << data[i] << " ";
        std::cout << "]" << std::endl;
      }

      void push_back(int elem) {
        int *tmp = new int[size + 1];
        for(int i = 0; i < size; i++)
          tmp[i] = data[i];
        tmp[size] = elem;
        size += 1;
        delete [] data;
        data = tmp;
      }

      void insert(int elem, int pos) {
        int *tmp = new int[size + 1];
        for(int i = 0, j = 0; i < size; i++, j++) {
          if( j == pos) {
              tmp[pos] = elem;
              i--;
          } else {
            tmp[j] = data[i];
          }        
        }
        size += 1;
        delete [] data;
        data = tmp;
      } 

      void remove(int pos) {
        int *tmp = new int[size - 1];
        for(int i = 0, j = 0; i < size; i++, j++) {
          if( j == pos)
          i++;
          tmp[j] = data[i];    
        }
        size -= 1;
        delete [] data;
        data = tmp;
      }

      ~DynamicIntArray() {
        delete[] data;
      }
};
