#pragma once
#ifndef PALINDROME_H
#define PALINDROME_H
#include "Stack.h"
#include "ArrayQueue.h"
#include <cmath>

class Palindrome {
  private: 
    Stack firstHalf;
    ArrayQueue secondHalf;
    string input; //do we need this?
    int length;

  public: 
    Palindrome(string in = "");
    void stkInit();
    void qInit();
    bool oddLength();
};

#endif
