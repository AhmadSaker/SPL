#include "Action.h"
#include "Order.h"
#include <iostream>



AddOrder::AddOrder(int id):BaseAction(),customerId(id)
{}

AddOrder::AddOrder(const AddOrder& other):BaseAction(),customerId(other.getCustomerId())
{
    if(other.getStatus() == ActionStatus::ERROR)
    {
        error(other.getErrorMsg());
    }
    else if(other.getStatus() == ActionStatus::COMPLETED)
    {
        complete();
    }
}

AddOrder::~AddOrder(){}

int AddOrder::getCustomerId() const
{
    return customerId;
}


void AddOrder::act(WareHouse &wareHouse)
{
    Customer& current_customer = wareHouse.getCustomer(customerId);

    if((current_customer.canMakeOrder()) && (current_customer.getId() != -1))
    {
        int Order_Id = wareHouse.makeOrderId();
        Order* tmpOrder = new Order (Order_Id,current_customer.getId(),current_customer.getCustomerDistance());
        tmpOrder->setStatus(OrderStatus::PENDING);
        current_customer.addOrder(Order_Id);
        wareHouse.addOrder(tmpOrder);
        this->complete();
    }
    else
    {
        this->error("Error: Cannot place this order");
        cout << getErrorMsg() << endl;
    }
    wareHouse.addAction(this->clone());
}

string AddOrder::toString() const
{
    string output = "order ";
    output= output + to_string(getCustomerId());
   if(getStatus()== ActionStatus:: ERROR)
   {
        output= output + " ERROR";
   }
   else
   {
        output = output +" COMPLETED";
   }

   return output;
}

AddOrder* AddOrder::clone() const
{
    AddOrder* output = new AddOrder(*this);

    return output;
}
