
typedef bool UnaryPredicate(int);

class IntVector {
  //OVERVIEW: A container that provides random access to
  //          any element by its index.  Indices start at 0.
  //          An IntVector can hold arbitrarily many elements.
  
public:

  // No constructors here!  This is an abstract base class.

  // We do need a virtual destructor to ensure that whenever
  // delete is used on a pointer to any kind of IntVector, the
  // appropriate polymorphic destructor is called.
  virtual ~IntVector() { };

  //MODIFIES: this IntVector
  //EFFECTS:  Adds value to the end of this IntVector.
  virtual void push_back(int value) = 0;
  
  //REQUIRES: this IntVector is not empty
  //MODIFIES: this IntVector
  //EFFECTS:  Removes the last element in this IntVector.
  virtual void pop_back() = 0;
  
  //REQUIRES: 0 <= index < number of elements in this IntVector
  //EFFECTS:  Returns the element at position index.
  virtual int at(int index) const = 0;
  
  //EFFECTS:  Returns the number of elements of this IntVector.
  virtual int size() const = 0;
  
  //EFFECTS:  Returns true if this IntVector is empty, false otherwise.
  virtual bool empty() const = 0;
  
  //EFFECTS:  Prints to cout all elements in this IntVector
  //          in the format (all on one line, followed by newline):
  //          [ elem0, elem1, elem2, ... ]
  virtual void print() const = 0;

};




class ArrayIntVector : public IntVector{
  //OVERVIEW: An array based implementation of the IntVector
  //          interface.
  
public:

  //EFFECTS: Creates an empty ArrayIntVector with the specified
  //         initial data capacity, or with the default.
  ArrayIntVector(int initCapacity);


  // Destructor
  virtual ~ArrayIntVector();

  // We will implement all the pure virtual functions from
  // IntVector.  See the declaration of IntVector for RMEs.
  virtual void push_back(int value);
  virtual void pop_back();
  virtual int at(int index) const;
  virtual int size() const;
  virtual bool empty() const;
  virtual void print() const;

private:

  // A pointer to the (dynamically allocated) array to hold
  // the N elements of this vector, stored in order in
  // the first N slots.  The array will be reallocated to
  // have twice as many elements if the number of elements
  // exceeds its current capacity.
  // INVARIANT: data != 0 (it is a valid pointer)
  int *data;

  // The number of elements the array (data) can currently hold.
  // INVARIANT: 0 <= dataCapacity
  int dataCapacity;

  // The default internal capacity of an array, used when none
  // is specified during construction.
  const static int DEFAULT_DATA_CAPACITY = 2;

  // The number of elements in the IntVector.
  // INVARIANT: 0 <= numElements <= dataCapacity
  int numElements;

  // EFFECTS: Contains asserts that fail if the representation
  //          invariants do not hold.
  void check_invariants() const;

  // EFFECTS: Doubles the storage capacity of this ArrayIntVector.
  //          More precisely:
  //            1. doubles dataCapacity
  //            2. allocates a new dynamic array with the new dataCapacity
  //            3. copies over the elements from the old data array
  //            5. sets data to point to the new array
  void grow();
};
