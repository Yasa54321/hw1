/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  if (in==nullptr) {
    odds=nullptr;
    evens = nullptr;
    return;
  }

//sets the current node
  Node* current = in;
  in = nullptr; //clears in pointer

//saves the next pointer
  Node* nextNode = current->next;
  current->next = nullptr;

//Recurses down the list attaching current node to either the odds or evens
  if ((current->value%2)!= 0){
    odds = current;
    split(nextNode, odds->next, evens);
  } 
  else{
    evens = current;
    split(nextNode, odds, evens->next);
  }
}

/* If you needed a helper function, write it here */
