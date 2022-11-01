#include <iostream>
#include "Point.h"
#include "DynamicIntArrayActualizado.h"

using namespace std;

int main(){
  PointArray a(2);
  Point z1(1,2);
  Point z2(3,4);
  Point z3(5,6);
  Point zp(7,8);
  Point arr[3] {z1,z2,z3};
  DynamicPointArray z(arr, 3);
  Point x(1,2);
  Point x2(3,7);
  int p1[6] = {1,2,3,4,5,6};
  DynamicIntArray p(p1, 6);
  p.remove(3);
  z.push_back(zp);
  a.setAt(0,x);
  a.setAt(1,x2);
  a.print();
  p.print();
  z.print();
  return 0;
}