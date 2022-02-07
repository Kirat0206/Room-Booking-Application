#include "student.h"

//////////STUDENT CLASS FUNCTIONS
    Student::Student()
    {//default constructor
        name="someone";
        number="0";
	}
    Student:: Student(const string& str1 , const string& str2 )//parameterized constructor
    {
        name  = str1;
        number= str2;
    }   

    Student:: Student(Student& obj)
    {   //copy_constructor
        this->name = obj.name;
        this->number= obj.number;
    }
    void Student::  Print()    //print function
    {
        cout<<"Name: "<<name;
        cout<<endl<<"Number: "<<number<<endl;
    }
   bool Student:: Lessthan(Student& s)    //this will return the less based on lexographical manner
    {   
        int This_Student =  stoi(this->number);
        int Other_Student = stoi(s.number);
        
        if(This_Student  < Other_Student )
             return true;
        else
             return false;
    }
    string Student:: getname()    //getter for student name
    {
        return name;
    }
