#include "Volunteer.h"

DriverVolunteer :: DriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep) :
Volunteer(id,name), maxDistance(maxDistance) , distancePerStep(distancePerStep),distanceLeft(maxDistance)
{
}
DriverVolunteer :: DriverVolunteer(const DriverVolunteer& other) :
Volunteer(other.getId(),other.getName()), maxDistance(other.getMaxDistance()) , distancePerStep(other.distancePerStep),distanceLeft(other.getDistanceLeft())
{
    completedOrderId = other.getCompletedOrderId();
    activeOrderId = other.getActiveOrderId();
}

DriverVolunteer::~DriverVolunteer(){}


DriverVolunteer *DriverVolunteer::clone() const
{
    DriverVolunteer* output = new DriverVolunteer(*this);
    return output;
}

int DriverVolunteer::getDistanceLeft() const
{
    return distanceLeft;
}

int DriverVolunteer::getMaxDistance() const
{
    return maxDistance;
}

int DriverVolunteer::getDistancePerStep() const
{
    return distancePerStep;
}

bool DriverVolunteer::decreaseDistanceLeft()
{
    distanceLeft = distanceLeft - distancePerStep ;
    if(distanceLeft <= 0)
    {
        distanceLeft=0;
        return true;
    }
    else
    {
        return false;
    }
}

bool DriverVolunteer::hasOrdersLeft() const
{
    return true; 
}

bool DriverVolunteer::canTakeOrder(const Order &order) const
{
    return !isBusy() && (order.getDistance() <= this->maxDistance) && (order.getStatus() == OrderStatus::COLLECTING) ;
}

void DriverVolunteer::setDiistanceLeft(int newDist)
{
    distanceLeft = newDist;
}

void DriverVolunteer::acceptOrder(const Order &order)
{
    distanceLeft = order.getDistance();
    activeOrderId=order.getId();
}

void DriverVolunteer::step()
{
    if(decreaseDistanceLeft())
    {
       completedOrderId = activeOrderId; 
    }
}

string DriverVolunteer::toString() const
{   
    string result ="";
    if (!isBusy()){
    result = "VolunteerId: " + std::to_string(getId()) + "\n" + 
    "isBusy:" + " False" + "\n" + "OrderID: None" + "\n" + "TimeLeft: " + std::to_string(getDistanceLeft()) + "\n"+ "OrdersLeft: No Limit";
    }
    else {
        result = "VolunteerId: " + std::to_string(getId()) + "\n" + 
    "isBusy:" + " True" + "\n" + "OrderID: " + std::to_string(getActiveOrderId()) +"\n" + "TimeLeft: None"  + "\n" +"OrdersLeft: No Limit";
    }
    return result;
}