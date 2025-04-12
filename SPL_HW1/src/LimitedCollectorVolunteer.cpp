#include "Volunteer.h"

LimitedCollectorVolunteer::LimitedCollectorVolunteer(int id, const string &name, int coolDown ,int maxOrders):
CollectorVolunteer(id,name,coolDown),maxOrders(maxOrders),ordersLeft(maxOrders){}

LimitedCollectorVolunteer::~LimitedCollectorVolunteer(){}

LimitedCollectorVolunteer::LimitedCollectorVolunteer(const LimitedCollectorVolunteer& other):
CollectorVolunteer(other.getId(),other.getName(),other.getCoolDown()),maxOrders(other.getMaxOrders()),ordersLeft(other.ordersLeft)
{
    completedOrderId = other.completedOrderId;
    activeOrderId = other.activeOrderId;
}

bool LimitedCollectorVolunteer::hasOrdersLeft() const
{
    if(getNumOrdersLeft()==0)
    {
        return false;
    }
    return true;
}
bool LimitedCollectorVolunteer::canTakeOrder(const Order &order) const 
{
    if(hasOrdersLeft() && !isBusy())
    {
        enum OrderStatus currentOrderStatus = order.getStatus(),pending = OrderStatus::PENDING;
        if(currentOrderStatus == pending)
        {
            return true;
        }
    }
    return false;
}

void LimitedCollectorVolunteer:: acceptOrder(const Order &order) 
{
    activeOrderId = order.getId();
    ordersLeft--;
    set_timeLeft(getCoolDown());
}

int LimitedCollectorVolunteer::getMaxOrders() const
{
    return maxOrders;
}

int LimitedCollectorVolunteer::getNumOrdersLeft() const
{
    return ordersLeft;
}

string LimitedCollectorVolunteer::toString() const
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

    output.append(std::to_string(getNumOrdersLeft()));

    return output;
}

LimitedCollectorVolunteer* LimitedCollectorVolunteer::clone() const 
{
    LimitedCollectorVolunteer* output= new LimitedCollectorVolunteer(*this);
    return output;
}
