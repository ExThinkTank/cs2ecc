#include "palindrome.h"

Palindrome::Palindrome(string in) : input(in) {
  length = input.length();
  stkInit();
  qInit();
}

void Palindrome::stkInit() {
  ItemType toPush;
  char c;
  for(int i = 0; i < input.length(); i++) {
    c = input[i];
    if(isalpha(c)) {
      tolower(c);
      toPush.Character = c;
      firstHalf.push(toPush);
    }
  }
}

void Palindrome::qInit() {
  ItemType toEnQ;
}

bool Palindrome::oddLength() {
  if((input.length() % 2) != 0) {
    return true;
  }
  return false;
}
