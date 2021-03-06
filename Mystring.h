/*
 * File:   Mystring.h
 * Author: wingning
 *
 * Mystring class that mimics the C++ string class in the standard library
 * 2021
 */

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

class Mystring 
{
public:
    // types with scope in this class
    typedef unsigned int size_type;
    typedef char* iterator;
    typedef const char* const_iterator;
    static const long int npos = 1073741824;

    // Default constructor, code given to you in lab6 Mystring.cpp
    Mystring();
    
    // Other constructors, code given to you in lab6 Mystring.cpp
    Mystring(const char *);
    
    // Copy constructor, done in lab6
    Mystring(const Mystring& orig);

    // Destructor, code given to you in lab6 Mystring.cpp
    ~Mystring();

    // Iterators We will not implement them for hw4
    iterator begin();
    iterator end();

    //=== Memory Related ===

    // Change buffer size to n
    void reserve(size_type n);

    size_type size() const; // code given to you in lab6 Mystring.cpp
    size_type length() const; //code given to you in lab6 Mystring.cpp
    size_type capacity() const; //code given to you in lab6 Mystring.cpp
    size_type max_size() const; //code given to you in lab6 Mystring.cpp
    bool empty() const;

    //=== Overloading operators ===

    // Assignment operator
    // the next two lines are commented out, so to use default. Uncomment to implement both later
    Mystring& operator=(const Mystring&); //Done
    Mystring& operator=(const char *); //Done

    // Array notation
    char operator[](size_type pos) const;  // minor difference we use char and not const char&
    char& operator[](size_type pos); //Done?

    // Append
    Mystring& operator+=(const Mystring& str); //Done
    Mystring& operator+=(const char * str); //Done

    //=== Methods that modify the string

    void clear(); //Done
    void push_back(char c); //Done

    // substring (2)
    Mystring& append(const Mystring& str, size_type subpos, size_type sublen); //Done
    // buffer (4)
    Mystring& append(const char * str, size_type n); //Done

    // string (1)
    Mystring& insert(size_type pos, const Mystring& str);//Done
    // c-string (3)
    Mystring& insert(size_type pos, const char * str); //Done

    // string (1)
    Mystring& replace(size_type start, size_type span, const Mystring& str); //Done
    // c-string (3)
    Mystring& replace(size_type start, size_type span, const char * str); //Done

    //=== Conversion to c-string

    const char * c_str() const; // code given to you in lab6 Mystring.cpp

    //=== functionalities similar to homework 1, quizzes, exams
    
    // buffer (3) version of the overloaded method
    size_type find_first_of (const char* s, size_type pos, size_type n) const; //Done

    // c-string (2)
    size_type find_last_not_of (const char* s, size_type pos = npos) const; //Done


private:
    
    // pointer to the memory location where string is stored as a c-style
    // string
    char * ptr_buffer;
    
    // the size of the memory in terms of bytes or characters
    size_type buf_size;
    
    // number of characters currently in the memory not including the
    // terminating null character
    size_type len;
};

//=== Overloading global operators for Mystring

// Overload operator == for Mystring
bool operator==(const Mystring&, const Mystring&); //Done
bool operator==(const char *, const Mystring&); //Done
bool operator==(const Mystring&, const char *); //Done

// Overload operator != for Mystring
bool operator!=(const Mystring&, const Mystring&); //Done
bool operator!=(const char *, const Mystring&); //Done
bool operator!=(const Mystring&, const char *); //Done

// Overload operator + for string as concatenation
Mystring operator+(const Mystring&, const Mystring&); //Done

// Output
ostream& operator<<(ostream& out, const Mystring& str); // code given to you in lab6 Mystring.cpp

// typedef Mystring::iterator iterator;

#endif /* MYSTRING_H */

