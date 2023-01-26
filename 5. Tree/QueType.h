// Header file for Queue ADT. 
#pragma once
#include <new>
#include <cstddef>
class FullQueue
{};  

class EmptyQueue
{};  
typedef int ItemType; 

struct NodeType;

class QueType
{
public: 
    QueType();
    // Class constructor.
    QueType(int max);
    // Parameterized class constructor.
    ~QueType();
    // Class destructor.
    QueType(const QueType& anotherQue);
    // Copy constructor
    void MakeEmpty();
    // Function: Initializes the queue to an empty state.
    bool IsEmpty() const;
    // Function: Determines whether the queue is empty.
    bool IsFull() const;
    // Function: Determines whether the queue is full.
    void Enqueue(ItemType newItem);
    // Function: Adds newItem to the rear of the queue.
    void Dequeue(ItemType& item);
    // Function: Removes front item from the queue and returns it in item.
private:

  NodeType* front;
  NodeType* rear;
};
