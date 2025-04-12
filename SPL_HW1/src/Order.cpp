#include "Order.h"

Order::Order(int id, int customerId, int distance) :toDeliver(false), id(id), customerId(customerId), distance(distance),status(OrderStatus::PENDING),collectorId(NO_VOLUNTEER),driverId(NO_VOLUNTEER)
{}
Order::Order(Order& other):
toDeliver(other.toDeliver),id(other.getId()),customerId(other.getCustomerId()),distance(other.getDistance()),status(other.getStatus()),collectorId(other.getCollectorId()),driverId(other.getDriverId())
{}

Order::~Order(){}

int Order::getId() const
{
    return id;
}

int Order::getDistance() const
{
    return distance;
}

int Order::getCustomerId() const
{
    return customerId;
}

void Order::setStatus(OrderStatus status)
{
    this->status = status;
}

void Order::setCollectorId(int collectorId)
{
    this->collectorId = collectorId;
}

void Order::setDriverId(int driverId)
{
    this->driverId = driverId;
}

void Order::setDeliverStatus(bool status)
{
    toDeliver = status;
}

bool Order::getDeliverstatus()
{
    return toDeliver;
}

int Order::getCollectorId() const
{
    return collectorId;
}

int Order::getDriverId() const
{
    return driverId;
}

OrderStatus Order::getStatus() const
{
    return status;
}

const string Order::toString() const
{
    string result = "OrderId: " + std::to_string(id) + "\n" + "OrderStatus: ";
    if (status == OrderStatus ::PENDING)
    {
        // CHECKING WHAT IS THE STATUS OF THE ORDER

        result = result + "Pending" +"\n"+ "CustomerId: " + std::to_string(customerId) + "\n" + "Collector: None" + "\n" + "Driver: None";
    }
    else if (status == OrderStatus::COLLECTING)
    {
        result = result + "Collecting"+"\n" + "CustomerId: " + std::to_string(customerId) + "\n" + "Collector: " + std::to_string(collectorId) + "\n" + "Driver: None";
    }

    else if (status == OrderStatus::DELIVERING)
    {
        result = result + "Delivering"+"\n" + "CustomerId: " + std::to_string(customerId) + "\n" + "Collector: " + std::to_string(collectorId) + "\n" +
                 "Driver: " + std::to_string(driverId);
    }

    else if (status == OrderStatus::COMPLETED)
    {
        result = result + "Completed"+"\n" + "CustomerId: " + std::to_string(customerId) + "\n" + "Collector: " + std::to_string(collectorId) + "\n" +
                 "Driver: " + std::to_string(driverId);
    }

    return result;
}
