
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {
		
	public:
		//constructor
		Date();
		Date(int year, int month, int day);
		Date(int yr, int mon, int dy, int hr, int dur);
		
				
		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int y, int m, int d);
		void setDate(Date&);
		void setHour(int);
		void setDuration(int);
		
		//getters
		int getDay();
		int getMonth();
		int getYear();
		int getHour();
		int getDuration();
		const string& getMonthName();
		
		
		//other
		bool lessThan(Date& d);
		bool overlaps(Date);
		void print();
	
	private:
		//functions
		int getMaxDay();
	
	
		//variables
		int day;
		int month;
		int year;
		int hour;
		int duration;
		
		//string array
		const string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		const string smonths[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};
	
};
#endif

