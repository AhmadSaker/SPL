#include "Action.h"
#include <string>
#include <vector>
#include "WareHouse.h"
#include "Volunteer.h"
using std::string;
using std::vector;
#include "Order.h"
using namespace std;

SimulateStep::SimulateStep(int numOfSteps) : BaseAction(),numOfSteps(numOfSteps)
{}

SimulateStep::~SimulateStep(){}

SimulateStep::SimulateStep(const SimulateStep& other):
BaseAction(),numOfSteps(other.getNumOfSteps())
{}

int SimulateStep:: getNumOfSteps() const
{
    return numOfSteps;
}

void SimulateStep::act(WareHouse &wareHouse)
{
    for (int i = 1; i <= numOfSteps; i++)
    {
        vector<Order*>& pendingOrders = wareHouse.getpendingOrders();
        for(std::vector<Order*>::size_type j = 0; j < pendingOrders.size(); j++)
        {
            if(pendingOrders[j]->getId() == -1)
            {
                continue;
            }
            else
            {
                for (Volunteer *volunteer : wareHouse.getvolunteers())
                {
                    if (volunteer->getId() == -1)
                    {
                        continue; // fake Volunteer
                    }
                    else if (volunteer->canTakeOrder(*pendingOrders[j]))
                    {
                        volunteer->acceptOrder(*pendingOrders[j]);
                        if (pendingOrders[j]->getStatus() == OrderStatus ::PENDING)
                        {
                            pendingOrders[j]->setStatus(OrderStatus::COLLECTING);
                            pendingOrders[j]->setCollectorId(volunteer->getId());
                        }
                        else
                        {
                            pendingOrders[j]->setStatus(OrderStatus::DELIVERING);
                            pendingOrders[j]->setDriverId(volunteer->getId());
                        }
                        // we must erase from pending and push to inProcess
                        wareHouse.pushOrder(pendingOrders[j], 2);
                        wareHouse.popOrder(pendingOrders[j], 1);
                        j--;
                        // we have found a vulonteer to take the order there is no need to continue searching
                        break;
                    }
                }
            }
        }
        for (Volunteer *volunteer : wareHouse.getvolunteers())
        {
            if (volunteer->getId() == -1)
                continue;
            else
            {
                if(volunteer->isBusy())
                {
                    volunteer->step();// performing a step for each volunteer
                }
            }
        }
        for (Volunteer *volunteer : wareHouse.getvolunteers())
        {
            if(!(volunteer->isBusy()))
            {
                if (volunteer->getId() == -1 || volunteer->getCompletedOrderId() == -1)
                {
                    continue; // fake Volunteer
                }
                else
                {
                    
                    Order &get_order = wareHouse.getOrder(volunteer->getActiveOrderId());
                    if ((get_order.getStatus() == OrderStatus::COLLECTING) && wareHouse.isOrderinProcessOrdersVector(get_order))
                    {
                        wareHouse.pushOrder(&get_order, 1); // we add the order that was collected to the pending orders
                        wareHouse.popOrder(&get_order, 2);  // removing the order from the in process orders
                    }
                    else if ((get_order.getStatus() == OrderStatus::DELIVERING)&& wareHouse.isOrderinProcessOrdersVector(get_order))
                    {
                        get_order.setStatus(OrderStatus::COMPLETED);
                        wareHouse.pushOrder(&get_order, 3); // we add the order that was delivered to the completed orders
                        wareHouse.popOrder(&get_order, 2);  // removing the order from the in process orders
                    }
                }
            }
        }
        // checking if there is a limited volunteer has reached his limit of orders
        for (Volunteer *volunteer : wareHouse.getvolunteers())
        {
            if (!(volunteer->hasOrdersLeft()) && !(volunteer->isBusy()))
            {
                Volunteer* tmp = volunteer;
                wareHouse.popVolunteer(volunteer);
                delete tmp;
            }
        }

    }
    complete();
    wareHouse.addAction(this->clone());
}

std::string SimulateStep::toString() const
{
    string answer;

    answer = "simulateStep " + std::to_string(numOfSteps) + " COMPLETED";

    return answer;
}

SimulateStep *SimulateStep::clone() const
{
    return new SimulateStep(*this);
}
