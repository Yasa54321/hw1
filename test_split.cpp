/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>


// Helper to create a linked list from an array of integers
Node* createList(const int arr[], int size) {
    if (size == 0){
      return nullptr;
    }
    Node* head = new Node{arr[0], nullptr};
    Node* current_node = head;
    for (int i = 1; i < size; ++i){
        current_node->next = new Node{arr[i], nullptr};
        current_node = current_node->next;
    }
    return head;
}

// Helper to print a linked list
void printList(Node* head) {
  while (head!=nullptr) {
    std::cout << head->value << " -> ";
    head = head->next;
  }
  std::cout << "nullptr\n";
}

//to avoid memory leaks 
void deleteList(Node* head) {
  while (head != nullptr){//goes until the whole list is traversed
    Node* temp = head;
    head = head->next;
    delete temp; 
  }
}


int main(int argc, char* argv[])
{
//mixed even and odd values case
  std::cout << "--- Test 1: Mixed List (1, 2, 3, 4, 5) ---\n";
  int values1[] = {1, 2, 3, 4, 5};
  Node* in1 = createList(values1, 5);
  Node* odds1 = nullptr;
  Node* evens1 = nullptr;

  split(in1, odds1, evens1);

  std::cout << "in is nullptr: " << (in1 == nullptr ? "PASSED" : "FAILED") << "\n";
  std::cout << "Odds:  "; printList(odds1);
  std::cout << "Evens: "; printList(evens1);

  deleteList(odds1);
  deleteList(evens1);

  //tests all odd values
  std::cout << "\n--- Test 2: All Odds (1, 3, 5, 7) ---\n";
  int values2[] = {1, 3, 5, 7};
  Node* in2 = createList(values2, 4);
  Node* odds2 = nullptr;
  Node* evens2 = nullptr;

  split(in2, odds2, evens2);

  std::cout << "in is nullptr: " << (in2 == nullptr ? "PASSED" : "FAILED") << "\n";
  std::cout << "Odds:  "; printList(odds2);
  std::cout << "Evens: "; printList(evens2);

  deleteList(odds2);
  deleteList(evens2);

  //empty list test case
  std::cout << "\n--- Test 3: Empty List ---\n";
  Node* in3 = nullptr;
  Node* odds3 = nullptr;
  Node* evens3 = nullptr;

  split(in3, odds3, evens3);

if (in3 == nullptr)
 {
    std::cout <<"in is a nullptr: passed\n";
  } 
  else {
    std::cout << "in is a nullptr: failed\n";
  }
  if (odds3 == nullptr) {
    std::cout << "odds is a nullptr: passed\n";
  } 
  else{
    std::cout <<"odds is a nullptr: failed\n";
  }
  if (evens3 == nullptr) {
    std::cout << "evens is a nullptr: passed\n";
  } 
  else {
    std::cout <<"evens is a nullptr: failed\n";
  }

  return 0;
}
