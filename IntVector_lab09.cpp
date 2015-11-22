#include <iostream>
#include <cassert>
#include <cstring>
#include "IntVector_lab09.h"

using namespace std;

//EFFECTS: Creates an empty ArrayIntVector with the specified
//         initial data capacity.
ArrayIntVector::ArrayIntVector(int initCapacity)
 : dataCapacity(initCapacity), numElements(0) {
  data = new int[dataCapacity];
  check_invariants();
}

// Destructor
ArrayIntVector::~ArrayIntVector() {
  delete [] data;
}

//MODIFIES: this IntVector
//EFFECTS:  Adds value to the end of this IntVector.
void ArrayIntVector::push_back(int value) {

  int newSize = numElements + 1;
  if (!(0 <= newSize && newSize <= dataCapacity)) {
    grow();
  } 
  check_invariants();
  data[numElements++] = value;
  check_invariants();
}

//REQUIRES: this IntVector is not empty
//MODIFIES: this IntVector
//EFFECTS:  Removes the last element in this IntVector.
void ArrayIntVector::pop_back() {
  check_invariants();
  assert(!empty());

  --numElements;

  check_invariants();
}

//REQUIRES: 0 <= index < number of elements in this IntVector
//EFFECTS:  Returns the element at position index.
int ArrayIntVector::at(int index) const {
  check_invariants();
  assert(0 <= index && index <= size());

  return data[index];
}

//EFFECTS:  Returns the number of elements of this IntVector.
int ArrayIntVector::size() const {
  check_invariants();

  return numElements;
}

//EFFECTS:  Returns true if this IntVector is empty, false otherwise.
bool ArrayIntVector::empty() const {
  check_invariants();

  return numElements == 0;
}

//EFFECTS:  Prints to cout all elements in this IntVector
//          in the format (all on one line, followed by newline):
//          [ elem0, elem1, elem2, ... ]
void ArrayIntVector::print() const {
  cout << "[ ";
  const int *ptr = data;
  for(const int *end = data + (numElements-1); ptr < end; ++ptr){
    cout << *ptr << ", ";
  }
  if (numElements != 0){
    cout << *ptr << " ";
  }
  cout << "]" << endl;
}

// EFFECTS: Contains asserts that fail if the representation
//          invariants do not hold.
void ArrayIntVector::check_invariants() const {
  assert(data != 0);
  assert(0 <= numElements && numElements <= dataCapacity);
  assert(0 <= dataCapacity);
}


// EFFECTS: Doubles the storage capacity of this ArrayIntVector.
//          More precisely:
//            1. doubles dataCapacity
//            2. allocates a new dynamic array with the new dataCapacity
//            3. copies over the elements from the old data array
//            5. sets data to point to the new array
void ArrayIntVector::grow() { 
  int *v = new int[dataCapacity * 2];

  for(int i = 0; i < numElements- 1; ++i){
    v[i] = data[i];
  }

  delete [] data;
  data = v;
  dataCapacity *= 2;
  
  //check_invariants();
  cout << "grow() was called. Capacity is now " << dataCapacity << "." << endl;
}

