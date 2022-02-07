#ifndef RES
#define RES
#include<iostream>
#include <string>
#include "student.h"
#include "room.h"
#include "Date.h"
using namespace std;

class Reservation{
private:
    Student* Stud_Ptr;
    Room* Room_Ptr;
    Date obj;

public:

    Reservation();
    ~Reservation();

    Reservation(Student* ptr, Room* Rptr, Date& D);
   
    Student* getStud_Ptr();

    Room* getRoom_Ptr();

    Date getDate_obj();

    bool lessThan(Reservation& res);

    bool overlaps(const string& R, Date& D);

    void print();
    
};
#endif 
