#include "Action.h"

AddCustomer::AddCustomer(const string& customerName, const string& customerType, int distance, int maxOrders):
BaseAction(),customerName(customerName),customerType(stringToCustomerType(customerType)),distance(distance),maxOrders(maxOrders)
{}

AddCustomer::AddCustomer(const AddCustomer& other):
BaseAction(),customerName(other.getCustomerName()),customerType(other.getCustomerType()),distance(other.getDistance()),maxOrders(other.getMaxOrders())
{
    if(other.getStatus() == ActionStatus::COMPLETED)
    {
        complete();
    }
}
AddCustomer::~AddCustomer(){}


string AddCustomer::getCustomerName() const
{
    return customerName;
}
CustomerType AddCustomer::getCustomerType() const
{
    return customerType;
}
int AddCustomer::getDistance() const
{
    return distance;
}
int AddCustomer::getMaxOrders() const
{
    return maxOrders;
}



CustomerType AddCustomer::stringToCustomerType(string customerType) const
{
    if (customerType == string("soldier"))
    {
        return CustomerType::Soldier;
    }
    else
    {
        return CustomerType::Civilian;
    }  
}
string AddCustomer::CustomerTypeToString() const
{
    if(customerType== CustomerType::Soldier)
    {
        return "soldier";
    }
    else
    {
        return "civilian";
    }
}

AddCustomer* AddCustomer::clone() const
{
    AddCustomer* output= new AddCustomer(*this);

    return output;
}

string AddCustomer::toString() const
{
    string output = "customer ";
    
    output+=customerName;
    
    output+=" ";
    
    output+=CustomerTypeToString();
    
    output+=" ";
    
    output+=to_string(distance);
    
    output+=" ";
    
    output+=to_string(maxOrders);

    output+=" COMPLETED";
    
    return output;
}

void AddCustomer::act(WareHouse &wareHouse)
{
    Customer* newCustomer;
    int customerID = wareHouse.makeCustomerId();
    complete();
    
    if(CustomerTypeToString()== "soldier")
    {
        newCustomer = new SoldierCustomer(customerID,customerName,distance,maxOrders);
    }
    else
    {
        newCustomer = new CivilianCustomer(customerID,customerName,distance,maxOrders);
    }

    AddCustomer* clone= this->clone();

    wareHouse.addCustomer(newCustomer);

    wareHouse.addAction(clone);

}