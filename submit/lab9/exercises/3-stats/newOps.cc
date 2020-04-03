#include "ops.hh"

class newOps : public Ops{
public:
  int compareCounter = 0;
  int swapCounter = 0;
  int compare(int a, int b) {
    compareCounter++;
    return this->Ops::compare(a,b);
  }

  void swap(int a[], int i, int j){
    swapCounter++;
    this->Ops::swap(a, i, j);
  }
};
