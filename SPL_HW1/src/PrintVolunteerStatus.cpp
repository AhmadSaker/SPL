#include "Action.h"
#include "Volunteer.h"
#include <iostream>
using namespace std;

PrintVolunteerStatus::PrintVolunteerStatus(int id):BaseAction(),volunteerId(id){}
PrintVolunteerStatus::~PrintVolunteerStatus(){}
PrintVolunteerStatus::PrintVolunteerStatus(const PrintVolunteerStatus& other):BaseAction(),volunteerId(other.getVolunteerId())
{
    if(other.getStatus() == ActionStatus::COMPLETED)
    {
        complete();
    }
    else if(other.getStatus() == ActionStatus::ERROR)
    {
        error(other.getErrorMsg());
    }
}

int PrintVolunteerStatus::getVolunteerId() const
{
    return volunteerId;
}


void PrintVolunteerStatus::act(WareHouse &wareHouse)
{
    Volunteer& tmp = wareHouse.getVolunteer(volunteerId);
    if(tmp.getId() == -1)
    {
        error("Error: Volunteer doesn't exist");
        cout<<getErrorMsg()<<endl;
        
    }
    else
    {
        cout<<tmp.toString()<<endl;
        complete();
    }
    wareHouse.addAction(this->clone());

}
PrintVolunteerStatus* PrintVolunteerStatus::clone() const
{
    
    return new PrintVolunteerStatus(*this);
}
string PrintVolunteerStatus::toString() const
{
    string output = "volunteerStatus ";
    output+=to_string(volunteerId);
    if(getStatus()== ActionStatus:: ERROR)
    {
        output+=" ERROR";
    }
    else if(getStatus()== ActionStatus:: COMPLETED)
    {
        output+=" COMPLETED";
    }
    return output;
}