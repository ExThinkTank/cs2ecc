#pragma once
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "QueueInterface.h"
#include "Stack.h"

//const int MAX = 30;
class ArrayQueue : public QueueInterface
{
private:
	/**
	*Array that holds queue elements has a fixed size of MAX.
	*/
   ItemType  queue [MAX]; 
   /**
   *Number of items in the queue (less than MAX )
      */
   int numItems;   
   /**
   *index of front of queue.
   */
   int front; 
   /**
   *index of rear of queue.
   */
   int rear;             
public:
  /**
  * Default constructor sets the numItems = 0, front = 0,
  *rear = -1.
  */
   ArrayQueue();
   void enqueue(ItemType item);
   ItemType dequeue( );
   bool isEmpty() const;
   bool isFull() const;
   size_t getSize() const;
  /**
  *Default destructor has no code in  it.
  */
	~ArrayQueue();
};
#endif
