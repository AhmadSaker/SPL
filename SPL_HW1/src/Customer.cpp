#include "Customer.h"

Customer::Customer(int id, const string &name, int locationDistance, int maxOrders)
: id(id), name(name), locationDistance(locationDistance), maxOrders(maxOrders),ordersId()
{}

Customer::Customer(const Customer& other):
id(other.getId()), name(other.getName()), locationDistance(other.getLocationDistance()), maxOrders(other.getMaxOrders()),ordersId(other.getOrdersIds())
{}

Customer::~Customer(){}

int Customer::getLocationDistance() const
{
    return locationDistance;
}

const string &Customer::getName() const
{
    return name;
}

int Customer::getId() const
{
    return id;
}

int Customer::getCustomerDistance() const
{
    return locationDistance;
}

int Customer::getMaxOrders() const
{
    return maxOrders;
}

int Customer::getNumOrders() const
{
    int numberOfElements = static_cast<int>(ordersId.size());

    return numberOfElements;
}

bool Customer::canMakeOrder() const
{
    int numberOfElements = static_cast<int>(ordersId.size());
    return (numberOfElements < maxOrders); // the number of orders is less than max orders
}

const vector<int> &Customer::getOrdersIds() const
{
    return ordersId;
}

int Customer::addOrder(int orderId)
{
    if (canMakeOrder())
    {
        ordersId.push_back(orderId);
        return orderId;
    }
    else
    {
        return -1;
    }
}