#include "Action.h"
#include <iostream>
using namespace std;
extern WareHouse* backup;

RestoreWareHouse::RestoreWareHouse():BaseAction()
{}
RestoreWareHouse::RestoreWareHouse(const RestoreWareHouse& other):BaseAction()
{
    if(other.getStatus() == ActionStatus::ERROR)
    {
        this->error(other.getErrorMsg());
    }
    else if(other.getStatus() == ActionStatus::COMPLETED)
    {
        this->complete();
    }
}

RestoreWareHouse::~RestoreWareHouse(){}

RestoreWareHouse* RestoreWareHouse::clone() const
{
    RestoreWareHouse* output = new RestoreWareHouse(*this);
    return output; 
}
string RestoreWareHouse::toString() const
{
    if(getStatus() == ActionStatus::ERROR)
    {
        return string("restore ERROR");
    }
    else
    {
        return string("restore COMPLETED");
    }
}
void RestoreWareHouse::act(WareHouse &wareHouse)
{
    if(backup==nullptr)
    {
        error("Error: No backup available");
        cout<< getErrorMsg() <<endl;
    }
    else
    {
        complete();
        wareHouse = *backup;
    }
    wareHouse.addAction(this->clone());
}