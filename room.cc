#include "room.h"

	 	//////////ROOM CLASS FUNCTIONS

   Room:: Room()//default constructor
    {   
        Capacity=3;
        Computers=1;
    }
    Room::Room(string R_Name,  int cap=3, int comp=1 , bool WB=true)//parameterized constructor with some default values
    {
        Room_name = R_Name;
        Capacity=cap;
        Computers=comp;
        WhiteBoard=WB;
    }
    Room::Room(Room& obj)//copy constructor
    {
        Room_name = obj.Room_name;
        Capacity= obj.Capacity;
        Computers= obj.Computers;
        WhiteBoard= obj.WhiteBoard;
    }
//setters for room class
	void Room:: SetWhiteBoard(bool temp){	WhiteBoard=temp;}
    void Room::SetComputers(int Comp){	 Computers =  Comp;}
    void Room:: SetRoomName(string R){    Room_name=R;}
//getters for room class
    int Room::GetCapacity(){    return Capacity;}
    void Room::SetCapacity(int C){    Capacity=C;}
    int Room::GetComputers(){    return Computers;}
	bool Room:: HasWhiteBoard(){    return WhiteBoard;}
    string Room:: GetRoomName(){    return Room_name;}

    bool Room::MeetsCriteria(int Cap, int Comp=0 , bool White_Bds=5)
    {
		//meet criteria checking that if capacity of this is greater than or equal to cap coming from parameter then return true
        //otherwise false
		if(Capacity>=Cap)
            return true;
        else 
            return false;
    }
    bool Room::Lessthan(Room& R)
    {
		//checks if ascii value of first alphabet of roomname of this is smaller than first alphabet of roomname of Room R comin from Parameter
        if( int(Room_name[0])  < int(R.Room_name[0]) )
             return true;
        else
             return false;
    }
