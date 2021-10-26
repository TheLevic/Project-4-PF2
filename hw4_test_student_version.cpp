/* 
 * File:   main.cpp
 * Author: wingning
 *
 * Created on October 1, 2010, 11:04 AM
 * Modified on January 18, 2016
 * MOdified October 2021
 * 
 * Please note: the definition of capacity in c++ string
 * and ours is different. Ours is always one more than that of c++ string
 * as ours includes the terminating null character and theirs is the number
 * of characters can be stored.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Mystring.h"

// comment out to use string class, now use Mystring class
//#define string Mystring

using namespace std;

/*
 * Check function from the previous lab.
 */
void check (const string s, const string name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}

/*
 * Check-obj function is similar to check, except we will check the object
 * instead of the copy of the object built by the copy constructor.
 */
void check_obj (const string& s, const string name)
{
    cout << "checking " << name << " the object" << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}



int main() 
{
    cout << "This is Lab 6\n";
    string s1("Hello, World!");
    string s1name ("s1");
    check (s1, s1name);
    check (s1, s1name);
    cout << "Lab 6 ends\n";
    
    cout << "\n--- Testing reserve ---\n"; 
    
    
    check_obj(s1, s1name);
    s1.reserve(15);
    check_obj (s1, s1name);
    
    cout << "---Testing assignment operator = ---\n";    
    s1 = "Hi!";
    check_obj(s1, s1name);
    
    string s2,s3("abcdefghijklmnopqrstuvwxyz01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    s2 = s1 = s3;
    check_obj(s1, s1name);
    check_obj(s2, "s2");
    check_obj(s3, "s3");
    string s4;
    check_obj(s4, "s4");
    s3 = s4;
    check_obj(s3, "s3");
    
    
    /*cout << "---Testing append ---\n";
    s3.append("CSCE2014", 4);
    check_obj(s3, "s3");*/
    
    
    
    
    return 0;
}
