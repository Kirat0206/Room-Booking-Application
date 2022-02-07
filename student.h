#ifndef STUDENT
#define STUDENT
#include<iostream>
#include <string>
using namespace std;

class Student{
private:
    string name;
    string number;

public:

    Student();
    Student(const string& str1 , const string& str2 );
    Student(Student& obj);
    void Print();
    bool Lessthan(Student& s);
    string getname();

};
#endif
