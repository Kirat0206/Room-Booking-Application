#include<iostream>
#include<string>
#include<cstring>
#include "a1-global.cc"
#include "Date.h"
#include "Date.cc"
#include "student.h"
#include "student.cc"
#include "room.h"
#include "room.cc"
#include "reservation.h"
#include "reservation.cc"

using namespace std;

//global variable as discussed in  document
const int Max_Duration = 3;


int main()
{
	//necessary declarations
	Date d1;
	d1.setDuration(2);
	Date d2;
	d2.setDuration(3);

	// Test for testdate() function
	//it should overlapp because d1 and d2 has same year month and day due to default constructor
	bool overlapp=true;
	testDate(d1,d2,overlapp);

	//Test for populate() function
	Library obj;
	populate(obj);
	testReservations(obj);

	system("pause");
    return 0;
}
