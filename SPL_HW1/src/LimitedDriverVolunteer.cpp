#include "Volunteer.h"


LimitedDriverVolunteer::LimitedDriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep, int maxOrders)
:DriverVolunteer(id,name,maxDistance,distancePerStep), maxOrders(maxOrders),ordersLeft(maxOrders){}

LimitedDriverVolunteer::LimitedDriverVolunteer(const LimitedDriverVolunteer& other)
:DriverVolunteer(other.getId(),other.getName(),other.getMaxDistance(),other.getDistancePerStep()), maxOrders(other.getMaxOrders()),ordersLeft(other.getNumOrdersLeft())
{
    activeOrderId= other.activeOrderId;
    completedOrderId = other.completedOrderId;
}

LimitedDriverVolunteer::~LimitedDriverVolunteer(){}

LimitedDriverVolunteer *LimitedDriverVolunteer::clone() const
{
    return new LimitedDriverVolunteer(*this);
}

int LimitedDriverVolunteer::getMaxOrders() const
{
    return maxOrders;
}

int LimitedDriverVolunteer::getNumOrdersLeft() const
{
    return ordersLeft;
}

bool LimitedDriverVolunteer::hasOrdersLeft() const
{
    return (ordersLeft>0);
}

bool LimitedDriverVolunteer::canTakeOrder(const Order &order) const
{
    return !isBusy() && (order.getDistance() <= getMaxDistance()) && hasOrdersLeft() && (order.getStatus() == OrderStatus::COLLECTING);
}

void LimitedDriverVolunteer::acceptOrder(const Order &order)
{
    setDiistanceLeft(order.getDistance());
    activeOrderId=order.getId();
    ordersLeft--;
}

string LimitedDriverVolunteer::toString() const
{
    string result = "";
    if (!isBusy()){
     result = "VolunteerId: " + std::to_string(getId()) + "\n" + 
    "isBusy: " + std::to_string(isBusy()) + "\n" + "OrderID: None" + "\n" + "TimeLeft: None" + "OrdersLeft: "+ std::to_string(getNumOrdersLeft());
    }
    else {

     result = "VolunteerId: " + std::to_string(getId()) + "\n" + 
    "isBusy: " + std::to_string(isBusy()) + "\n" + "OrderID: "+ std::to_string(getActiveOrderId()) + "\n" + "TimeLeft: " + std::to_string(getDistanceLeft()) +"\n"+ "OrdersLeft: "+ std::to_string(getNumOrdersLeft());
    
    }
    return result;
}
