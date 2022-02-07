#include<iostream>
#include<string>
#include<cstring>
#include "a1-global.cc"
#include "Date.h"
#include "student.h"
#include "room.h"
#include "reservation.h"

using namespace std;

  Library::Library()//default constructor
	{
        SList=new Student* [100]; //intializing the student 2d pointer on heap  
        for(int i=0;i<100;i++)
            room_pointers[i]=nullptr;//initializing 1d pointer on heap

        reservedlist=new Reservation*[100];////intializing the Reservation 2d pointer on heap 
    }
	
	 Library::~Library()//delete 
    {
		//students deletion
        if(SList!=0)
        {
                for(int i=0;i<c1;i++)
                {
                        if(SList[i]!=0)
                        delete SList[i];
                }
                delete[] SList;
        
        }
		//rooms deletion
		for(int i=0;i<c2;i++)
        {
                if(room_pointers[i]!=0)
                delete room_pointers[i];
        }
		//reservations deletion
        if(reservedlist!=0)
        {
                for(int i=0;i<c3;i++)
                {
                        if(reservedlist[i]!=0)
                        delete reservedlist[i];
                }
                delete[] reservedlist;
        }

    }
	
	
    bool Library::addStudent(const string& nam,const string& num)//adds new student in the SList(students list)
    {
        if(c1>0)
        {
            SList[c1-1]=new Student(nam,num);
            c1--;
            return true; 
        }
        else
            return false;
    }
	
	   bool Library::addRoom(string nam,int cap=1,int com=0,bool white_board=0)//adds room in the room_pointers(rooms list)
	{
	if(c2>0)
	{
		room_pointers[c2-1]=new Room(nam,cap,com,white_board);
        c2--;
		return true;
	}
	else
		return false;
}


bool Library::isFree(const string& ro_om, Date& d)
{//this function checks whether the demanded room is free or not on given date
	for(int k=99; k>=c3 ;k--)//c3 is counter that how many reservations have done till now
	{
		if( reservedlist[k]->getRoom_Ptr()->GetRoomName() == ro_om   )
			{   
			if(d.overlaps(reservedlist[k]->getDate_obj()) ==   true)
                return false;
        }      
	}
	return true;
}


bool Library::makeReservation(const string& student_n, const string& room_nm, Date& d)
{
	//add one more member in the reservation list if it is ALLOWED
    Room* ptr1;
    Student* ptrStud;
	int temp=0;
	for(int i=99;i>=c1;i--)//c1 is the counter that how many students are added in the student list uptill now
	{
		if(	SList[i]->getname()==student_n)//if such student name exist in the SList(studentlist)
		{
            ptrStud=SList[i];
			for(int j=99;j>=c2;j--)//c2 is the counter that how many rooms are added in the room_pointers uptil now
            {
                if(room_pointers[j]->GetRoomName()==room_nm)//if such name exist in the room_pointers
                {
                    ptr1=room_pointers[j];
                    temp=1;
                }   
            }	
	   }
	}
        if (temp==0)
            return false;

        else			
		if ( isFree(room_nm, d)==true )//IF ROOM IS FREE THEN RESERVE 
		{    
            reservedlist[c3-1]= new Reservation( ptrStud  , ptr1  ,  d);
            c3--;    
            return true;
	    }
        else
            return false;
}
bool Library::GetStudent(const string& student_n , Student** ptr)
{
	//if name of any member of SList(basically Student** ptr) is equal to string student_n then true return
	//otherwise at the end return false
    for(int i=99; i>=0; i--)
	{
		if(	ptr[i]->getname()==student_n)
		{
           return true;
	   }
	}
    return false;
}
bool Library::GetRoom(const string& room_nm , Room** rm)
{
	//if room name of any member of room_pointers(basically Room** rm) is equal to string room_nm then true return
	//otherwise at the end return false
	for(int j=99;j>=0;j--)
    {
        if(rm[j]->GetRoomName()==room_nm)
        {
            return true;
        }
    }	
    return false;
}
void Library::printReservations()
{
	//print reserved list 
    for(int i=99; i>=c3 ;i--)//c3 is the how many reservations have done till now
    {   
        cout<<"Room named "<<reservedlist[i]->getRoom_Ptr()->GetRoomName();
        cout<<" reserved for "<<reservedlist[i]->getStud_Ptr()->getname();
        cout<<" at Date "<<reservedlist[i]->getDate_obj().getYear()<<" / "<<reservedlist[i]->getDate_obj().getMonth()<<" / "<<reservedlist[i]->getDate_obj().getDay();
        cout<<endl;
    }
}





















