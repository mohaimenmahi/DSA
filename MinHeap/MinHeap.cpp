class MinHeap {
  private:
    int capacity = 10;
    int size = 0;

    int itmes[capacity]; // this is gonna be an array of fixed length, we will increase the size of the array when we need to;

    int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
    int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
    int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

    bool hasLeftChild(int index) { return getLeftChildIndex(index) < size; }
    bool hasRightChild(int index) { return getRightChildIndex(index) < size; }
    bool hasParent(int index) { return getParentIndex(index) >= 0; }

    int leftChild(int index) { return itmes[getLeftChildIndex(index)]; }
    int rightChild(int index) { return itmes[getRightChildIndex(index)]; }
    int parent(int index) { return itmes[getParentIndex(index)]; }

    void swap(int indexOne, int indexTwo) {
      int temp = itmes[indexOne];
      itmes[indexOne] = itmes[indexTwo];
      itmes[indexTwo] = temp;
    }

    void ensureExtraCapacity() {
      if (size == capacity) {
        // create a new array with double the capacity of the current one.
        // this uses dynamic memory allocation with new 
        int* newItems = new int[capacity * 2];  

        // copy all the existing elements from the old array to the new one
        for (int i = 0; i < size; i++) {
          newItems[i] = itmes[i];
        }
        // deallocate the memory of the old array to prevent memory leaks
        // this uses dynamic memory deallocation with delete
        delete[] itmes;

        // point the itmes pointer to the new array
        itmes = newItems;
        capacity *= 2;
      }
    }

  public:
    // show the minimum element in the heap
    int top() {
      if (size == 0) {
        throw std::out_of_range("Heap is empty");
      }
      return itmes[0]; // this will be the minimum element and the root of the heap
    }

    // this actually extacts the minimum element from the heap and removes it from the array
    int pop() {
      if (size == 0) {
        throw std::out_of_range("Heap is empty");
      }

      int item = items[0];

      // replace the root with the last element in the heap
      itmes[0] = itmes[size - 1];

      size--;

      // heapify down the root element to maintain the heap property
      heapifyDown();
      return item;
    }

    void add(int item) {
      ensureExtraCapacity(); // check if we need to increase the size of the array

      itmes[size] = item; // add the new item to the end of the heap
      size++; // increase the size of the heap

      heapifyUp(); // heapify up the new item to maintain the heap property
    }

    void heapifyUp() {
      int index = size - 1; // start from the last element

      // it will go up until the parent is smaller than the current element
      while(hasParent(index) && parent(index) > items[index]) {
        swap(getParentIndex(index), index); // swap the current element with its parent
        index = getParentIndex(index); // moved up to the place of the parent
        // see: https://www.youtube.com/watch?v=t0Cq6tVNRBA&t=440s 
      }
    }

    void heapifyDown() {
      int index = 0;  // start from the root element
      
      // check for left child exists, if there is no left child, there will be no right child as well
      while(hasLeftChild(index)) { 
        int smallerChildIndex = getLeftChildIndex(index); // assume the left child is the smaller one

        // if the right child is smaller, update the index
        if(hasRightChild(index) && rightChild(index) < leftChild(index)) {
          smallerChildIndex = getRightChildIndex(index); 
        }

        // if the current element is smaller than the smaller child, we are done
        if (items[index] < items[smallerChildIndex]) {
          break; // the heap property is statisfied
        } else {
          // swap the current element with the smaller child
          swap(index, smallerChildIndex); // swap the current element with the smaller child
          index = smallerChildIndex; // move down to the smaller child 
        }
      } 
    }
};