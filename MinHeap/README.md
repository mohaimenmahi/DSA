# Binary Heap Implementation

## Overview

This repository contains an implementation of a binary min heap data structure. In a min heap, the parent node is always smaller than or equal to its children, with the smallest element at the root.

## Structure

The heap is represented as a tree with the following values in the example:

```
        2
       /  \
      /    \
     4      3
    / \    / \
   9   7  10  5
  / \ /
15 20 13
```

## Algorithm Steps

### 1. Insertion

Insert a value to the next empty position, top to bottom, left to right.

### 2. Heapify Up

If the parent is higher than the element, we swap it with the parent until we:

- Reach the very top, or
- Find a parent with a lower value than this element

### 3. Removal (Extract Min)

When we remove the peak element (or root):

- Replace it with the very last element
- Reduce the heap size by 1
- Heapify down this element until:
  - It becomes lower than its parent, and
  - It becomes lower than its children

## Time Complexity

- Insertion: O(log n)
- Extract Min: O(log n)
- Peek (get minimum): O(1)
- Heapify: O(n)

## Applications

- Priority queues
- Heap sort algorithm
- Graph algorithms (Dijkstra's, Prim's)
- Median maintenance
- Merge K sorted arrays/lists

## Implementation

The heap can be efficiently implemented using an array, where for a node at index i:

- Parent is at index (i-1)/2
- Left child is at index 2\*i + 1
- Right child is at index 2\*i + 2
