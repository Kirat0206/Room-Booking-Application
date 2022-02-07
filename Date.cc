
#include "Date.h"
//CONSTRUCTORS
Date::Date(){
	setDate(1901,1,1);
}
Date::Date(int y, int m, int d){
	setDate(y,m,d);
}
  Date:: Date(int yr, int mon, int dy, int hr, int dur)
    {
        year=yr;
        hour=hr;
        duration=dur;
        day=dy;
        month= mon;
    }
//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}
void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}
void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}
void Date::setDate(int y, int m, int d){
	setMonth(m);
	setDay(d);
	setYear(y);
}
void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day);
}
void Date::setHour(int hr)
{
	this->hour=hr;
}
void Date:: setDuration(int D)
{
	this->duration=D;
}

//getters
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
const string& Date::getMonthName(){return months[month-1];}
int Date::getHour(){return hour;}
int Date::getDuration(){return duration;}


//further functions of date class
bool Date:: overlaps(Date obj)
{
	//this function will check whether the dates overlapps or not
	if(getDay()==obj.getDay())
			if(getMonth()==obj.getMonth())
			 	  if(getYear()==obj.getYear())
						if(getHour()  <  obj.getHour() + obj.getDuration() )
							return true;
							//this last if statement is to check whether the this-> date is independent of obj date duration

	return false;
}
bool Date::lessThan(Date& d)
{
	//if date of this is less than date of date passed in parameter then it returns true
	//else false
	if (year == d.year)
	{

			if (month == d.month)
			{
				if(day < d.day)
					{
						return hour<d.hour;
					}

				else
					{
						return day<d.day;
					}	
			}
			else
			{
				return month  < d.month;
			}
	}
	else
	{
		return year < d.year;
	}	
}
void Date::print(){
//simple print creds fucntion
	cout << getMonthName()<<" "<<getDay()<<", "<<getYear()<<endl;
	cout<<"Hour: "<<getHour()<<endl;
	cout<<"Duration: "<<getDuration()<<endl<<endl;
}
int Date::getMaxDay(){
	//returns MAXDAYS of the month(it may be 30,28,31.....default is 31)
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}


