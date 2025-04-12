#include "Volunteer.h"

CollectorVolunteer:: CollectorVolunteer(int id, const string &name, int coolDown):Volunteer(id,name),coolDown(coolDown),timeLeft(coolDown){}
CollectorVolunteer:: ~CollectorVolunteer(){}

CollectorVolunteer:: CollectorVolunteer(const CollectorVolunteer& other):
Volunteer(other.getId(),other.getName()),coolDown(other.coolDown),timeLeft(other.timeLeft)
{
    activeOrderId = other.activeOrderId;
    completedOrderId = other.completedOrderId;
}

CollectorVolunteer*  CollectorVolunteer:: clone() const
{
    CollectorVolunteer* output = new CollectorVolunteer(*this);
    return output;
}

int CollectorVolunteer::getCoolDown() const
{
    return coolDown;
}

int CollectorVolunteer::getTimeLeft() const
{
    return timeLeft;
}

bool CollectorVolunteer::decreaseCoolDown()
{
    timeLeft--;
    if(getTimeLeft()==0)
    {
        return true;
    }
    return false;
}

bool CollectorVolunteer::hasOrdersLeft() const
{
    return true;
}
bool CollectorVolunteer::canTakeOrder(const Order &order) const
{
    enum OrderStatus currentOrderStatus = order.getStatus(),pending = OrderStatus::PENDING;
    if(currentOrderStatus == pending && !isBusy())
    {
        return true;
    }

    return false;
}
// Prepare for new order(Reset activeOrderId,TimeLeft,DistanceLeft,OrdersLeft depends on the volunteer type)
void CollectorVolunteer::acceptOrder(const Order &order)
{
    activeOrderId = order.getId();
    set_timeLeft(getCoolDown());
}

void CollectorVolunteer::set_timeLeft(int coolDown)
{
    timeLeft=getCoolDown();
}

string CollectorVolunteer::toString() const
{
    string output("VolunteerID: "),enter("\n");
    output.append(std::to_string(getId()));
    output.append(enter);
    output.append("isBusy: ");
    if(isBusy())
    { 
        output.append("True");
        output.append(enter);
        output.append("OrderID: ");
        output.append(std::to_string(getActiveOrderId()));
        output.append(enter);
        output.append("TimeLeft: ");
        output.append(std::to_string(getTimeLeft()));

    }
    else
    {
        output.append("False");
        output.append(enter);
        output.append("OrderID: None");
        output.append(enter);
        output.append("TimeLeft: None");

    }
    output.append(enter);

    output.append("OrdersLeft: ");

    output.append("No Limit");

    return output;
}
//Simulate volunteer step,if the volunteer finished the order, transfer activeOrderId to completedOrderId
void CollectorVolunteer::step()
{
    if(decreaseCoolDown())
    {
        completedOrderId = getActiveOrderId();
    }
}