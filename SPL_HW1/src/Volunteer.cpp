
#include "Volunteer.h"
 
Volunteer::Volunteer(int id, const string &name): completedOrderId(NO_ORDER) , activeOrderId(NO_ORDER),id(id), name(name)
{}
Volunteer::~Volunteer()
{}

int Volunteer::getId() const
{
    return id;
}
const string& Volunteer::getName() const
{
    return name;
}
int Volunteer:: getActiveOrderId() const
{
    return activeOrderId;
}
int Volunteer::getCompletedOrderId() const
{
    return completedOrderId;
}
bool Volunteer::isBusy() const
{
    if(getActiveOrderId() != getCompletedOrderId())
        return true;
    return false;
}

