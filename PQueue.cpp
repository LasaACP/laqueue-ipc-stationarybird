/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
//  std::cout << "startpush" << std::endl;
  node *point = new node;
  point->data = item;
  point->priority = priority;
  node* start = front;
  if(front == NULL){
  //  std::cout << "null push" << std::endl;
    front=point;
    return;
  }
  if(front->priority > priority){
  //  std::cout << "less prio" << std::endl;
    point->link = front;
    front = point;
  }

  else{
    while(start->link != NULL && start->link->priority <= priority){
      start = start->link;
   //   std::cout << "more prio" << std::endl;
    }
    point->link = start->link;
    start->link = point;
    
  }

}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
  if(front!=NULL){
    return front->data;
  }
  return NULL;
  

	/* Your code here */
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
 // std::cout<<"startpop" << std::endl;
  if(front!=NULL){
    node* temp = front;
    front = front->link;
 //   std::cout << "delete david " << std::endl;
    //delete(temp);
  }

}

/*
 * Print Priority Queue
 */
void PQueue::display()
{
  
    node* temp = front;
    while(temp){
      std::cout<<temp->priority<<" "<<(char*)temp->data<<std::endl;
      temp = temp->link;
    }



  
	/* Your code here */
	
	/* Use the following out command for the data */


}
	