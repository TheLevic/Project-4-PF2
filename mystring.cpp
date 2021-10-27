/*
 * File:   mystring.cpp
 * Author: Levi Crider
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

Mystring& Mystring::operator=(const Mystring& str){ //Setting one object equal to another (essentially copying)
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
    delete [] ptr_buffer; //Freeing space
    int count; //Length
    for (count = 0; ptr[count] != '\0'; count++);
    len = count;
    buf_size = count + 1; //Including null char
    ptr_buffer = new char [buf_size]; //With proper space allocation
    strcpy(ptr_buffer,ptr); //Copying string over
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
     len = len + str.len; //Setting the new len of the string
     buf_size = len + 1 ;
     char *tmp = new char [buf_size]; //Creating tmp to hold ptr_buffer and add the new str to the end of it
     strcpy(tmp, ptr_buffer);
     strcat(tmp, str.ptr_buffer);
     ptr_buffer = new char [buf_size];
     strcpy(ptr_buffer,tmp); //Putting concatenated version back into ptr_buffer
     return *this;
 }

 Mystring& Mystring::operator+=(const char * str){
     int count = 0; //My len of the str we're adding
     for (count = 0; str[count] != '\0'; count++){}
     len = len + count;
     buf_size = len + 1; //Length including null character
     char *tmp = new char [buf_size]; //Tmp to hold ptr_buffer
     strcpy(tmp, ptr_buffer);
     delete [] ptr_buffer;
     ptr_buffer = new char [buf_size]; //Adding space
     strcat(ptr_buffer,str); //Copying back to ptr_buffer
     return *this;
 }

    //=== Methods that modify the string

void Mystring::clear(){
    delete [] ptr_buffer; //Freeing ptr_buffers space
    len = 0; //Setting len = 0
    buf_size = 1; //Buf size = 1 b/c NULL
    ptr_buffer = new char [len + 1];
    ptr_buffer[0] = '\0';
}
void Mystring::push_back(char c){
    char *tmp = new char [len + 2];
    strcpy(tmp,ptr_buffer);
    delete [] ptr_buffer;
    len = len + 1; //Adding space for the new char
    buf_size = len + 1; //Adding space for the NULL character
    ptr_buffer = new char [buf_size];
    cout << len;
    tmp[len - 1] = c; //Adding the character to the end of the string
    strcpy(ptr_buffer,tmp);
}

Mystring& Mystring::append(const Mystring& str, size_type subpos, size_type sublen){
    //Need to append a substr of str from subpos to sublen
    size_type size = (sublen - subpos) + 1;
    char *tmp = new char [size + len + 1]; //tmp variable to hold ptr_buffer and strcat tmp2 to
    char *tmp2 = new char [size]; //tmp variable to hold the substring that I need to append
    strcpy(tmp,ptr_buffer);
    delete [] ptr_buffer;
    ptr_buffer = new char [len + size + 1];
    len = len + size;
    buf_size = len + 1; //Len of str + null char
    for (int i = subpos; i <= sublen; i++){ //Creating the substring tmp2 from str
        tmp2[i - subpos] = str[i]; 
    }
    strcat(tmp, tmp2);
    strcpy(ptr_buffer,tmp);
    return *this;
}

Mystring& Mystring::append(const char * str, size_type n){
    buf_size = buf_size + n; //Increasing the buf size
    char *tmp = new char [buf_size]; //Holding the ptr_buffer and what we're adding
    strcpy(tmp, ptr_buffer); //Copying ptr_buffer to tmp
    delete [] ptr_buffer; //Freeing ptr_buffer
    char *tmp2 = new char [n + 1]; //Array of char to hold the str being appended
    for (int i = 0; i < n; i ++){
        tmp2[i] = str[i]; //Going char by char
    }
    strcat(tmp, tmp2); //Adding tmp2 onto tmp
    ptr_buffer = new char [buf_size]; //Allocating ptr_buffer with the right amount of memory
    strcpy(ptr_buffer,tmp);
    delete [] tmp;
    len = buf_size - 1; 
    return *this;
}

//Inserts additional characters into the string right before the character indicated by pos (or p):

Mystring& Mystring::insert(size_type pos, const Mystring& str){
    char *tmp = new char [buf_size + str.len];
    strcpy(tmp,ptr_buffer);
    /*Insert str while keeping the ptr_buffer string in tact before and after 
    (Need to free the space in the middle for the inserted str)*/
    for (int i = buf_size + str.len - 1; i > pos; i--){
        tmp [i] = ptr_buffer[i-str.len]; //Moves the characters to the end that need to go after the inserted str
    }
    for(int i = pos; tmp[i] != ptr_buffer[buf_size - pos]; i++){ //Inserts the char in the free space
        tmp[i] = str[i - pos];
    }
    //Copy back to ptr_buffer
    delete [] ptr_buffer;
    ptr_buffer = new char [buf_size + str.len];
    strcpy(ptr_buffer,tmp);
    //Set proper buf_size and len
    buf_size = buf_size + str.len;
    len = buf_size - 1;
    return *this;
}

