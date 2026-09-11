#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE


void ULListStr::push_back(const std::string& val){
  if (tail_ == NULL){
    Item* n = new Item();
    n->val[0] = val;
    n->first = 0;
    n->last = 1;
    head_ = n;
    tail_ = n;
  }
  else if (tail_->last <ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  else{
    Item* n = new Item();
    n->val[0] = val;
    n->first = 0;
    n->last = 1;
    n->prev = tail_;
    tail_->next = n;
    tail_ = n;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val){
  if (head_ == NULL){
    Item* n = new Item();
    n->val[ARRSIZE -1] = val;
    n->first = ARRSIZE -1;
    n->last = ARRSIZE;
    head_ = n;
    tail_ = n;
  }
  else if (head_->first > 0){
    head_->first--;
    head_->val[head_->first] = val;
  }
  else{
    Item* n = new Item();
    n->val[ARRSIZE -1] = val;
    n->first = ARRSIZE -1;
    n->last = ARRSIZE;
    n->next = head_;
    head_->prev = n;
    head_=n;

  }

  size_++;
  }


void ULListStr::pop_back(){
  if (tail_ == NULL) {
    return;
  }
  tail_->last--;
  size_--;

  if (tail_->first == tail_->last) {
    Item* temp = tail_;
    if(head_ == tail_) {
      head_ = NULL;
      tail_ = NULL;
    }
    else{
      tail_ = tail_->prev;
      tail_->next = NULL;
    }
    delete temp;
  }

}

void ULListStr::pop_front(){
  if (head_ == NULL){
    return;
  }
  else{
    head_->first++;
    size_--;

    if (head_->first == head_->last){
      Item* temp = head_;
      if (head_ == tail_){
        head_ = NULL;
        tail_ = NULL;
      }
      else {
        head_ = head_->next;
        head_->prev = NULL;
      }
      delete temp;
    }
  }


}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc >= size_) {
    return NULL;
  }

  Item* curr = head_;
  while (curr != NULL) {
    size_t count = curr->last - curr->first;
    if (loc < count) {
      return &(curr->val[curr->first + loc]);
    }
    loc -= count;
    curr = curr->next;
  }
  return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
