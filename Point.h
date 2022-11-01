#include <iostream>

class Point {
  public:

    Point(int _x = 0, int _y = 0): x(_x), y(_y){}

    void set_X(int _x){
      x = _x;
    }

    int get_X() const {
      return x;
    }

    void set_Y(int _y){
      y = _y;
    }

    int get_Y() const {
      return y;
    }

    void print(){
      std::cout << "(" << x << ", " << y << std::endl;
    }

  private:
    int x, y;
};


class PointArray{

    private:

        int size;

        Point *data;

    public:

        PointArray(int size) {
          data = new Point[size];
          this->size = size;
        }

        PointArray(PointArray const &o){
          size = o.size;
          data = new Point[o.size];
          for (Point i = 0; i.get_X() < size; i.set_X(i.get_X()+1)){
             data[i.get_X()] = o.data[i.get_X()]; 
          }
        }

        int getAt (int index) const {
          if (index >= 0 && index < size)
            return (data[index]).get_X();
        }

        void setAt(int index, Point value) {
          int i = 0;
          if(index >= i && index < size)
            data[index] = value;
        }

        int get_size() const {
          return size;
        }

        void print() const {
          for(int i = 0; i < size; i++)
            std::cout << "(" << (data[i]).get_X() << " , " <<  (data[i]).get_Y() << ") ";
          std::cout << std::endl;
        }

        ~PointArray(){
          delete data;
        }

};

class DynamicPointArray {
        int size;
        Point *data;
    public:
      DynamicPointArray() {
        this->size = 0;
        data = new Point[0];
      }

      DynamicPointArray(const Point arr[], int size){
        this->size = size;
        data = new Point[size];
        for(int i = 0; i < size; i++)
          data[i] = arr[i];
      }

      DynamicPointArray(const DynamicPointArray &o) {
        this->size = o.size;
        this->data = new Point[o.size];
        for(int i = 0; i < size; i++)
          data[i] = o.data[i];
      }

      int getSize() const {
        return size;
      }

      void print() const {
        std::cout << "[ ";
        for(int i = 0; i < size; i++)
          std::cout << "(" << (data[i]).get_X() << " , " << (data[i]).get_Y() << ") ";
        std::cout << "]" << std::endl;
      }

      void push_back(Point elem) {
        Point *tmp = new Point[size + 1];
        for(int i = 0; i < size; i++)
          tmp[i] = data[i];
          tmp[size] = elem;
        size += 1;
        delete [] data;
        data = tmp;
      }

      void insert(Point elem, int pos) {
        Point *tmp = new Point[size + 1];
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
        Point *tmp = new Point[size - 1];
        for(int i = 0, j = 0; i < size; i++, j++) {
          if( j == pos)
          i++;
          tmp[j] = data[i];    
        }
        size -= 1;
        delete [] data;
        data = tmp;
      }

      ~DynamicPointArray() {
        delete[] data;
      }
};
