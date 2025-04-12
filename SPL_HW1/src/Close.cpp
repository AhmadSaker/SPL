#include "Action.h"
#include <iostream>

Close::Close():BaseAction()
{
    complete();
}
Close::~Close(){}

void Close::act(WareHouse &wareHouse)
{
    for (const Order *order : wareHouse.getpendingOrders())
    {
        if(order->getId() != -1)
        {

            string printOrder = "OrderID:" + std::to_string(order->getId()) + " , CustomerID:" + std::to_string(order->getCustomerId()) + " , OrderStatus:";

            if (order->getStatus() == OrderStatus::PENDING)
            {
                printOrder = printOrder + "PENDING";
            }
            else
            {
                printOrder = printOrder + "COLLECTING";
            }
                
            std::cout << printOrder << std::endl;
        }
    }

    for (const Order *order : wareHouse.getinProcessOrders())
    {
        
        if(order->getId() != -1)
        {
            string printOrder = "OrderID:" + std::to_string(order->getId()) + " , CustomerID:" + std::to_string(order->getCustomerId()) + " , OrderStatus:";
            if (order->getStatus() == OrderStatus::DELIVERING)
            {
                printOrder = printOrder + "DELIVERING";
            }
            else
            {
                printOrder = printOrder + "COLLECTING";
            }
            
            std::cout << printOrder << std::endl;
        }
    }

    for (const Order *order : wareHouse.getcompletedOrders())
    {   
        if(order->getId() != -1)
        {
            string printOrder = "OrderID:" + std::to_string(order->getId()) + " , CustomerID:" + std::to_string(order->getCustomerId()) + " , OrderStatus:COMPLETED";
            std::cout << printOrder << std::endl;
        }
        
    }
    wareHouse.deleteAll();
    wareHouse.close();
}

Close *Close::clone() const
{
    return new Close();
}

string Close::toString() const
{
    return "close COMPLETED";
}
