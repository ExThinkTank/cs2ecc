#include "Arrayqueue.h"
#include <iostream>
#include <cassert>
using namespace std;
//-----------------------------------------------------------
ArrayQueue::ArrayQueue( )
 {
         numItems = 0;
		 front = 0;
		 rear = -1;
  }
//--------------------------------------------------------------------
void ArrayQueue::enqueue(ItemType item)
  {
     if(isFull( ))
	 {
		 cerr<<"The queue is full. The item is not added.\n";
		 return;
	 }
    else
    {
		//Prove that line 23 does same thing that lines 24 to 31 do
		 rear = (rear + 1) % MAX;
		/*if (rear == MAX - 1)
		{
			rear = 0;
		}
		else
		{
			rear = rear + 1;
		}*/
         queue[rear] = item;
         numItems = numItems + 1;
     }
  }
//-------------------------------------------------
ItemType ArrayQueue::dequeue( ) 
{
       if(isEmpty ( ) )
           {
		cerr<<"\nThe queue is empty.\n";
		throw "Queue is empty";
           }
     else
     {
          ItemType toReturn = queue[front];
		  //Prove that line 47 does same thing that lines 48 to 55 do
		front = (front + 1) % MAX;
		 /* if (front == MAX -1)
		  {
			  front = 0;
		  }
		  else
		  {
			  front = front + 1;
		  }*/
          numItems --;
          return toReturn;
      }
}

//---------------------------------------------
bool ArrayQueue::isEmpty() const

  {
    return (numItems == 0);
  }
//----------------------------------------
bool ArrayQueue::isFull() const
  {
    return (numItems == MAX);
  }
//--------------------------------------------
ArrayQueue::~ArrayQueue()
{
}
//--------------------------------------------------------------------
size_t ArrayQueue::getSize() const
{
	return numItems;
}

//int main()
//{
//	//basic tests
//	ArrayQueue que;
//	//add some characters to queue
//	ItemType itm;
//	itm.Character = 'A';
//	que.enqueue(itm);
//	itm.Character = 'B';
//	que.enqueue(itm);
//	itm.Character = 'C';
//	que.enqueue(itm);
//	itm.Character = 'D';
//	que.enqueue(itm);
//	itm.Character = 'F';
//	que.enqueue(itm);
//	itm.Character = 'G';
//	que.enqueue(itm);
//
//	while (!que.isEmpty())
//	{
//		cout << que.dequeue().Character << endl;
//	}
//
//	return 0;
//
//}