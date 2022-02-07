#ifndef room
#define room
#include<iostream>
#include <string>
using namespace std;

class Room{

private:
    string Room_name;
    int Capacity;
    int Computers;
    bool WhiteBoard;
public:
    Room();
    Room(string R_Name,  int cap, int comp , bool WB);
    Room(Room& obj);

    bool HasWhiteBoard();
    string GetRoomName();
    int GetCapacity();
    int GetComputers();

    void SetComputers(int Comp);
	void SetCapacity(int C);
	void SetWhiteBoard(bool temp);
	void SetRoomName(string R);

	bool MeetsCriteria(int Cap, int Comp , bool White_Bds);
    bool Lessthan(Room& R);
};
#endif
