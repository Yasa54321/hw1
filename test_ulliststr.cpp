#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

  // Test 1: Empty list
  std::cout << "Test 1: Empty list" << std::endl;
  std::cout << "Size: " << list.size() << std::endl;
  std::cout << "Empty: " << list.empty() << std::endl;

  // Test 2: push_back
  std::cout << "\nTest 2: push_back" << std::endl;

  list.push_back("A");
  list.push_back("B");
  list.push_back("C");

  std::cout << "Size: " << list.size() << std::endl;
  std::cout << "Front: " << list.front() << std::endl;
  std::cout << "Back: " << list.back() << std::endl;

  std::cout << "Values: ";
  for (size_t i = 0; i < list.size(); ++i) {
      std::cout << list.get(i) << " ";
  }
  std::cout << std::endl;

  // Test 3: push_front
  std::cout << "\nTest 3: push_front" << std::endl;

  list.push_front("X");
  list.push_front("Y");

  std::cout << "Size: " << list.size() << std::endl;
  std::cout << "Front: " << list.front() << std::endl;
  std::cout << "Back: " << list.back() << std::endl;

  std::cout << "Values: ";
  for (size_t i = 0; i < list.size(); ++i) {
      std::cout << list.get(i) << " ";
  }
  std::cout << std::endl;

  // Test 4: pop_front
  std::cout << "\nTest 4: pop_front" << std::endl;

  list.pop_front();

  std::cout << "Size: " << list.size() << std::endl;
  std::cout << "Front: " << list.front() << std::endl;

  std::cout << "Values: ";
  for (size_t i = 0; i < list.size(); ++i) {
      std::cout << list.get(i) << " ";
  }
  std::cout << std::endl;

  // Test 5: pop_back
  std::cout << "\nTest 5: pop_back" << std::endl;

  list.pop_back();

  std::cout << "Size: " << list.size() << std::endl;
  std::cout << "Back: " << list.back() << std::endl;

  std::cout << "Values: ";
  for (size_t i = 0; i < list.size(); ++i) {
      std::cout << list.get(i) << " ";
  }
  std::cout << std::endl;

  // Test 6: More than one Item
  // ARRSIZE is 10, so adding 15 values forces the list
  // to use more than one Item.
  std::cout << "\nTest 6: Multiple Items" << std::endl;

  list.clear();

  for (int i = 0; i < 15; ++i) {
      list.push_back(std::to_string(i));
  }

  std::cout << "Size: " << list.size() << std::endl;

  std::cout << "Values: ";
  for (size_t i = 0; i < list.size(); ++i) {
      std::cout << list.get(i) << " ";
  }
  std::cout << std::endl;

  // Test 7: Remove everything
  std::cout << "\nTest 7: Remove everything" << std::endl;

  while (!list.empty()) {
      list.pop_back();
  }

  std::cout << "Size: " << list.size() << std::endl;
  std::cout << "Empty: " << list.empty() << std::endl;

  // Test 8: Pop from an empty list
  std::cout << "\nTest 8: Pop from an empty list" << std::endl;

  list.pop_front();
  list.pop_back();

  std::cout << "Size after popping empty list: "
            << list.size() << std::endl;

  std::cout << "\nFinished tests!" << std::endl;

  return 0;
}
