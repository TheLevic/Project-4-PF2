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
#define string Mystring

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
    
    cout << "---Testing [] ---\n";
    cout << "The fifth character in the string s1 is " << s1[4] << endl;
    
    cout << "---Testing append ---\n";
    //s3.append("CSCE2014", 4);
    //check_obj(s3, "s3");
    string something = "hey";
    string hello = "hello";
    something.append(hello, 1, 2);
    check_obj(something, "something");
    string something1 = "No";
    something1.append("yes", 2);
    check_obj(something1, "yes");

    cout << "---Testing Push_back ---" << endl;
    something = "Goodbye";
    something.push_back('!');
    check_obj(something, "something");

    cout << "---Testing Clear ---" << endl;
    s1.clear();
    check_obj(s1, "s1");
    
    cout << "---Testing Insert ---" << endl;
    s1 = "Hello";
    string insert = "Friend";
    s1.insert(4,insert);
    check_obj(s1, "s1");
    s1.insert(6, "Yo");
    check_obj(s1, "s1");
    s1.clear();

    cout << "---Testing Replace ---" << endl;
    s1 = "Stop ";
    string replace = "something";
    s1.replace(4,1,replace);
    check_obj(s1,"s1");
    s1.clear();
    s1 = "Yo Dude!";
    s1.replace(1, 3, "Sah Dude");
    check_obj(s1, "s1");

    cout << "--- Testing Find_first_of ---" << endl;
    s1.clear();
    s1 = "Hello Friend";
    string search = "l";
    int james = s1.find_first_of("l", 0, 3);
    cout << james << endl << endl;

    cout << "--- Testing find_last_not_of ---" << endl;
    s1.clear();
    s1 = "test string";
    james = s1.find_last_not_of("tes", 5);
    cout << james << endl;

    cout << "-- Final Testing --" << endl;
    s1.clear();
    s1 = "Test";
    s2.clear();
    s2 = "hello!";
    s3.clear();
    s3 = s1 + s2;
    cout << s3 << endl;
    bool t_or_f =  s1 == s2;
    cout << t_or_f << endl;
    s1 = s2;
    t_or_f = s1 == s2;
    cout << t_or_f << endl;
    cout << s1.empty();



    
    return 0;
}
