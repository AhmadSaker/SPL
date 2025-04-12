#include "Action.h"
#include "Customer.h"
#include "Order.h"
#include <iostream>

PrintCustomerStatus::PrintCustomerStatus(int customerId) :BaseAction(), customerId(customerId)
{}
PrintCustomerStatus::~PrintCustomerStatus()
{}
PrintCustomerStatus::PrintCustomerStatus(const PrintCustomerStatus& other):
BaseAction(), customerId(other.getCustomerId())
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
int PrintCustomerStatus:: getCustomerId() const
{
    return customerId;
}

void PrintCustomerStatus::act(WareHouse &wareHouse)
{
    string toPrint;
    toPrint =toPrint + "CustomerID: ";
    Customer &customer = wareHouse.getCustomer(customerId);
    
        if (customer.getId() == customerId)
        {   

            toPrint = toPrint+ to_string(customerId) + "\n";

            for (int i : customer.getOrdersIds())
            {
            toPrint = toPrint + "OrderID: " + to_string(i) + "\n" + "OrderStatus: ";
            Order& order = wareHouse.getOrder(i);

            if (order.getStatus() == OrderStatus::PENDING)
            {
                toPrint = toPrint + "Pending";
            }
            else if (order.getStatus() == OrderStatus::COLLECTING)
            {
                toPrint = toPrint + "Collecting";
            }
            else if (order.getStatus() == OrderStatus::DELIVERING)
            {
                toPrint = toPrint + "Delivering";
            }
            else if (order.getStatus() == OrderStatus::COMPLETED)
            {
                toPrint = toPrint + "Completed";
            }
            toPrint = toPrint +"\n";
        }
        toPrint = toPrint  + "numOrdersLeft: " + to_string(customer.getMaxOrders() - customer.getNumOrders());
        cout << toPrint << endl;
     }
    else
    {
        error("Error: Customer doesn't exist");

        cout << getErrorMsg() << endl;
    }
    wareHouse.addAction(this->clone());
}

PrintCustomerStatus *PrintCustomerStatus::clone() const
{
    return new PrintCustomerStatus(*this);
}

string PrintCustomerStatus::toString() const
{
    string output = "custmerStatus " + to_string(customerId);
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
