//
//  MaxHeap.h
//  22C_HW5
//

#ifndef Heap_h
#define Heap_h

#include <iostream>
using namespace std;

template < class ItemType>
class MaxHeap
{
private:
    static const int ROOT_INDEX = 0; // Helps with readability
    static const int DEFAULT_CAPACITY = 30; // Small capacity to test for a full heap
    ItemType* item; // Array of heap items
    int itemCount; // Current count of heap items
    int maxItems; // Maximum capacity of the heap
    int level;  //height of the tree
    
    // Returns the array index of the left child (if it exists).
    int getLeftChildIndex(const int nodeIndex) const;
    
    // Returns the array index of the right child (if it exists).
    int getRightChildIndex(int nodeIndex) const;
    
    // Returns the array index of the parent node.
    int getParentIndex(int nodeIndex) const;
    
public:
    MaxHeap(int size = 30);        // Constructor
    ItemType getItem(int index) {return item[index];}   //Return item
    bool insert(ItemType newData);
    ItemType remove();
    void ReheapDown(int root, int last);   // Reheap after removing item
    void ReheapUp(int newElement);     // Reheap after inserting item
    int getNumElements();                    // Return number of elements in the heap
    void printIndented(int index, int level);     // Print heap as indented tree
    void printAll();
}; // end MaxHeap


//////////////////////////// PRIVATE FUNCTIONS ////////////////////////////////////////////

template <class ItemType>
int MaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
    return (2 * nodeIndex) + 1;
} // end getLeftChildIndex

template <class ItemType>
int MaxHeap<ItemType>::getRightChildIndex( int nodeIndex) const
{
    return (2 * nodeIndex) + 2;
} // end getRightChildIndex

template <class ItemType>
int MaxHeap<ItemType>::getParentIndex(int nodeIndex) const
{
    return (nodeIndex - 1) / 2;
} // end getParentIndex

//////////////////////////// PUBLIC FUNCTIONS ////////////////////////////////////////////

//this function initialize heap array and numbers of items and heap array size
template < class ItemType>
MaxHeap<ItemType>::MaxHeap(const int size)
{
    // Allocate the array
    item = new ItemType[size];
    itemCount = 0;
    maxItems = size;
} // end constructor

//this function insert item to max heap
template < class ItemType>
bool MaxHeap<ItemType>::insert(ItemType newData)
{
    if (itemCount == maxItems)
        return false;
    item[itemCount] = newData;
    ReheapUp(itemCount);
    itemCount++;
    return true;
} // end insert

//this function remove and the root and rearrange the heap and then return the root
template < class ItemType>
ItemType MaxHeap<ItemType>::remove()
{
    ItemType temp = item[0];
    item[0] = item[itemCount];
    ReheapDown(0, itemCount);
    return temp;
} //end remove

//this function create a appropriate max heap
template <class ItemType>
void MaxHeap<ItemType>::ReheapUp(int newElement)
{
    if (newElement > 0)
    {
        int parent = getParentIndex(newElement);
        if (item[newElement] > item[parent])
        {
            ItemType temp = item[newElement];
            item[newElement] = item[parent];
            item[parent] = temp;
            ReheapUp(parent);
        }
    }
} // end ReheapUp

//this function rearrange the heap
template < class ItemType>
void MaxHeap<ItemType>::ReheapDown(int root, int last)
{
    int maxKey;
    int rightKey;
    int leftKey;
    ItemType temp;
    
    leftKey = getLeftChildIndex(root);
    rightKey = getRightChildIndex(root);
    
    if(leftKey <= last)
    {
        if(leftKey == last)
        {
            maxKey = leftKey;
        }
        else
        {
            if(item[leftKey] <= item[rightKey])
                maxKey = rightKey;
            else
                maxKey = leftKey;
        }
        if(item[root] < item[maxKey])
        {
            temp = item[root];
            item[root] = item[maxKey];
            item[maxKey] = temp;
            ReheapDown(maxKey, last);
        }
    }
}

//this function returns the number of item
template < class ItemType>
int MaxHeap<ItemType>::getNumElements()
{
    return itemCount;
}

// Print indented tree
template <class ItemType>
void MaxHeap<ItemType>::printIndented(int index, int level)
{
    if(itemCount != 0 && index < itemCount)
    {
        for (int i = 0; i < level; i++) cout << "\t";
        cout << level + 1 << ". ";
        cout << item[index] << endl;
        int newLevel = level + 1;
        int left = getLeftChildIndex(index);
        printIndented(left, newLevel);
        int right = getRightChildIndex(index);
        printIndented(right, newLevel);
    }
}
#endif /* Heap_h */

