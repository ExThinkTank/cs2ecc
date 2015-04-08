#pragma once
#ifndef TOKENIZER_PARSER_H
#define TOKENIZER_PARSER_H

#include <string>
#include <cstring>    // for strchr
#include <list>
#include <map>
#include <iostream>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdlib>

using namespace std;

namespace MySpace
{
    bool isws(char c, char const * const wstr = " \t\n");
}

class TokenizerParser
{
protected:
    /**
    *Function is protected. So it is not to be called by the client.
    */
    static void stringtok(list<string> &l, string const &s, char const * const ws = " \t\n");
public:
    /**
    *The function takes a string expression as an argument and returns
    *an array of tokens after stripping the white spaces from it.
    *Whitespaces may be tabs, newlines and blank characters.
    *For example if a string such as "Hello World I am here + you are there" is
    *sent to the function to be tokenized, then it will return by reference
    *an array with following strings in them:<BR>
    *Hello<BR>
    *World<BR>
    *I<BR>
    *am<BR>
    *here<BR>
    *+<BR>
    *you<BR>
    *are<BR>
    *there<BR>
    *The description of various parameters is as follows:<BR>
    *@param Str_Arr is the array of strings that contains the tokens extracted
    *from the string expression exp.
    *@param exp is the string to be tokenized. It may contain words or
    *alphanumeric characters and mathematical or logical operators.
    *@param MAX is the physical length of the array. <B>It is client's respnsibilty
    *to ascertain that number of tokens in the expression exp are smaller than
    *the physical length of the array Str_Arr. If physical length MAX is
    *smaller than the number of tokens to be extracted from the expression exp, then
    *token loss will take place.</B>
    *@param count is the number of tokens extracted from the string exp. The
    *maximum value of count is MAX. count is also the logical length of array
    * Str_Arr.
    */
    static void getStringArray(string Str_Arr[], const string& exp, size_t MAX, size_t &count);
    /**
    *The function parses the string form of a double type number passed to it
    *and returns its double value.
    *<B>It is client's responsibility to make sure that string passed to
    *the function contains a valid double data type. Invalid data type will
    *give unpredictable results</B>.
    *@param val is the string to be parsed into a double value.
    *@return the double value of string val.
    */
    static double parseDouble(string &val);
    /**
    *The function parses the string form of a integer type number passed to it
    *and returns its int value.
    *<B>It is client's responsibility to make sure that string passed to
    *the function contains a valid int data type. Invalid data type will
    *give unpredictable results</B>.
    *@param val is the string to be parsed into a int value.
    *@return the int value of string val.
    */
    static int parseInt(string &val);
    /**
    *The function parses the string form of a long type number passed to it
    *and returns its long value.
    *<B>It is client's responsibility to make sure that string passed to
    *the function contains a valid long data type. Invalid data type will
    *give unpredictable results</B>.
    *@param val is the string to be parsed into a long value.
    *@return the long value of string val.
    */
    static long parseLong(string &val);
};

#endif
