#include "reservation.h"

	//////////RESERVATION CLASS FUNCTIONS
    Reservation:: Reservation()
    {
		//default constructor
		Stud_Ptr=NULL;
		Room_Ptr=NULL;   
    }
    Reservation::Reservation(Student* ptr, Room* Rptr, Date& D)
    {
		//parameterized constructor
        Stud_Ptr=ptr;
        Room_Ptr=Rptr;
        obj.setMonth(D.getMonth());
        obj.setDate(D.getYear(),D.getMonth(), D.getDay());
        obj.setYear(D.getYear());
        obj.setDuration(D.getDuration());
        obj.setHour(D.getHour());
    }
    Student* Reservation::getStud_Ptr()
    {
		//getter of Stud_Ptr which is private member of reservation class
        return Stud_Ptr;
    }
    Room* Reservation::getRoom_Ptr()
    {
		//getter of Room_Ptr which is private member of reservation class
        return Room_Ptr;
    }
    Date Reservation::getDate_obj()
    {
		//getter of date object which is private member of reservation class
        return obj;
    }
    bool Reservation::lessThan(Reservation& res)
    {
		//it will return the calling reservation object's lessthan()
		//if obj.lessThan(res.obj)gives true then Reservation gives true,if obj.lessThan(res.obj)gives false,Reservation give false
        return this->obj.lessThan(res.obj);
    }
    bool Reservation::overlaps(const string& R, Date& D)
	{
		//it checks if the Room_Ptr room name is equalto the parameter string R and if given date overalaps with date of(this)
        //then return true else false
		if( Room_Ptr->GetRoomName()  == R )
            if( obj.getDay() == D.getDay() )
                 if( obj.getHour()==D.getHour() )
                     if(  obj.getMonth()==D.getMonth() )
                         if(obj.getYear()==D.getYear())  
                                  return true;
        
            return false; 
    }
    void  Reservation::print()
    {
		//print all the credentials of reservation
        Stud_Ptr->Print();
        cout<<"Room Name: "<<Room_Ptr->GetRoomName()<<endl;
        cout<<"Capacity: "<<Room_Ptr->GetCapacity()<<endl;
        cout<<"Computers: "<<Room_Ptr->GetComputers()<<endl;
        cout<<"Has White Board: "<<Room_Ptr->HasWhiteBoard()<<endl;
        obj.print();
    }

    Reservation:: ~Reservation()
    {
        Stud_Ptr=NULL;
        Room_Ptr=NULL;
    }

