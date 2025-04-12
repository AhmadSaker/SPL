#include "Action.h"
#include <iostream>

PrintOrderStatus::PrintOrderStatus(int id) :BaseAction(),orderId(id)
{
}
PrintOrderStatus::~PrintOrderStatus(){}

PrintOrderStatus::PrintOrderStatus(const PrintOrderStatus&other):BaseAction(),orderId(other.getOrderId())
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

int PrintOrderStatus:: getOrderId() const
{
    return orderId;
}

void PrintOrderStatus::act(WareHouse &wareHouse)
{
    Order& order = wareHouse.getOrder(orderId);
    if(order.getId() != -1)
    {
        cout << order.toString()<<endl;
    }
    else
    {
        error("Error: Order doesn't exist");
        cout << getErrorMsg()<<endl;
    }
    wareHouse.addAction(this->clone());
}

PrintOrderStatus *PrintOrderStatus::clone() const
{
    return new PrintOrderStatus(*this);
}

string PrintOrderStatus::toString() const
{
    string output = "orderStatus " + std::to_string(orderId);

    if(getStatus() == ActionStatus::COMPLETED)
    {
        output +=" COMPLETED";
    }
    else
    {
        output+= " ERROR";
    }
    return output;
}
