/*
 * File:   mystring.cpp
 * Author: wingning
 *
 * mystring class implementation:
 * methods whose implementations are provided:
 * default constructor
 * a constructor taking c-style string
 * the destructor
 * size, length, capacity, max_size
 * << operator for cout
 * c_str
 *
 * methods to be implemented:
 * a copy constructor
 * ...
 */

#include "Mystring.h"

// default constructor
Mystring::Mystring() 
{
    ptr_buffer  = new char[1];
    *ptr_buffer = '\0';
    buf_size    = 1;
    len         = 0;
}

// constructor from c-style string or "abc"
Mystring::Mystring(const char * s) 
{
    len        = strlen(s);
    buf_size   = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, s);

}

// copy constructor to be implemented
Mystring::Mystring(const Mystring& orig) 
{
    len = orig.length();
    ptr_buffer = new char[len + 1];
    buf_size = len + 1;
    for (int i = 0; i < buf_size; i ++){
        ptr_buffer[i] = orig.ptr_buffer[i];
    }
}

// one of the over loaded assignment operator if you have time
/*Mystring& Mystring::operator=(const Mystring& orig)
{

}*/

// some simple methods implemented for you
 Mystring::size_type Mystring::size() const 
 {
     return len;
 }
 
 Mystring::size_type Mystring::length() const
 {
     return len;
 }
 
 Mystring::size_type Mystring::capacity() const
 {
       return buf_size;
 }
 
 Mystring::size_type Mystring::max_size() const
 {
       return (int)pow(2,30) -4 ;
 }
 
// Destructor
Mystring::~Mystring() 
{
    delete [] ptr_buffer;
}

// Provided for the lab so we may cout mystring
ostream& operator<<(ostream& out, const Mystring& str) 
{
    out << str.c_str();
    return out;
}

// implemented for the lab to support the implementation of <<
const char * Mystring::c_str() const 
{
    return ptr_buffer;
}

//Change buffer size to n
void Mystring::reserve(Mystring::size_type n){
    if (n > buf_size - 1){
        char *tmp = new char[n + 1];//Need to move the pointer to point to a new location
        //Set the location size = n
        strcpy(tmp, ptr_buffer); //Copy the old string over to the new buffer
        delete [] ptr_buffer; //Delete the old memory location
        ptr_buffer = tmp;
        buf_size = n + 1; //We do need to set the new buffer size
    }
}

Mystring& Mystring::operator=(const Mystring& str){ //Setting one object equal to another
    if (this != &str){
        delete [] ptr_buffer; //Freeing ptr_buffer
        ptr_buffer = new char [str.len + 1];
        strcpy(ptr_buffer,str.ptr_buffer);
        len = str.len;
        buf_size = str.buf_size; 
    }
    return *this;
}
Mystring& Mystring::operator=(const char *ptr){ //Making an array of character = a string
    int count = 0;
    for (int count = 0; ptr[count] != '\0'; count++);
    len = count + 1;
    buf_size = 0;
    delete [] ptr_buffer;
    ptr_buffer = new char [len];
    strcpy(ptr_buffer,ptr);
    return *this;
}

//Array Notation
char Mystring::operator[](size_type pos) const{ //What is the difference between these two?
   return ptr_buffer[pos];
}

char& Mystring::operator[](size_type pos){
   return ptr_buffer[pos];
}

//Append
 Mystring& Mystring::operator+=(const Mystring& str){
     len = len + str.len + 1; //Setting the new len of the string
     buf_size = 0;
     strcat(ptr_buffer, str.ptr_buffer); //Adding the string on to the end
     return *this;
 }

 Mystring& Mystring::operator+=(const char * str){
     int count = 0;
     for (count = 0; str[count] != '\0'; count++){}
     len = len + count + 1;
     buf_size = 0;
     strcat(ptr_buffer,str);
     return *this;
 }

    //=== Methods that modify the string

void Mystring::clear(){
    delete [] ptr_buffer;
    len = 0;
    buf_size = 0;
}
void Mystring::push_back(char c){
    len = len + 1; 
    ptr_buffer[len] = c; //Adding the string to the end
    buf_size = 0;
}


