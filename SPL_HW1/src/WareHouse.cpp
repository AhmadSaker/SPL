#include "WareHouse.h"
using namespace std;


WareHouse ::WareHouse(const string &configFilePath)
:isOpen(false), actionsLog(), volunteers() , pendingOrders(), inProcessOrders(), completedOrders(), customers(), customerCounter(0), volunteerCounter(0), orderCounter(0)
{
    addCollector(-1,"",0);
    
    addOrder(new Order(-1,-1,0));

    addCustomer(new CivilianCustomer(-1,"",0,0));

    vector<vector<string>> initialState = readConfigFile(configFilePath);


    for(vector<string> line :initialState )
    {
        
        if(line[0] == "customer")
        {
            if(line[2] == "soldier")
            {
                addSoldier(makeCustomerId(),line[1],stoi(line[3]),stoi(line[4]));
            }
            else if (line[2] == "civilian")
            {
                addCivilian(makeCustomerId(),line[1],stoi(line[3]),stoi(line[4]));
            }
            
        }
        else if (line[0] == "volunteer")
        {
            if(line[2] == "collector")
            {
                addCollector(makeVolunteerId(),line[1],stoi(line[3]));
            }
            else if(line[2] == "limited_collector")
            {
                addLimited_collector(makeVolunteerId(),line[1],stoi(line[3]),stoi(line[4]));
            }
            else if(line[2] == "driver")
            {
                addDriver(makeVolunteerId(),line[1],stoi(line[3]),stoi(line[4]));
            }
            else if(line[2] == "limited_driver")
            {
                addLimited_driver(makeVolunteerId(),line[1],stoi(line[3]),stoi(line[4]),stoi(line[5]));
            }
        }
    }
}

//Delete all the vector of pointer in this class
void WareHouse:: deleteAll()
{
    for(Order* order:pendingOrders)
    {
        delete order;
        order=nullptr;
    }

    pendingOrders.clear();

    for(Order* order:inProcessOrders)
    {
        delete order;
        order=nullptr;
    }

    inProcessOrders.clear();

    for(Order* order:completedOrders)
    {
        delete order;
        order=nullptr;
    }

    completedOrders.clear();

    for(Volunteer* volunteer:volunteers)
    {
        delete volunteer;
        volunteer=nullptr;
    }

    volunteers.clear();

    for(Customer* customer:customers)
    {
        delete customer;
        customer=nullptr;
    }

    customers.clear();

    for(BaseAction* action:actionsLog)
    {
        delete action;
        action=nullptr;
    }

    actionsLog.clear();
}

const vector<BaseAction*>& WareHouse::getActions() const
{
    return actionsLog;
}

vector<Volunteer*>& WareHouse::getvolunteers()
{
    return volunteers;
}

vector<Order*>& WareHouse::getpendingOrders()
{
    return pendingOrders;
}

vector<Order*>& WareHouse::getinProcessOrders()
{
    return inProcessOrders;
}

vector<Order*>& WareHouse::getcompletedOrders()
{
    return completedOrders;
}

vector<Customer*>& WareHouse::getcustomers()
{
    return customers;
}

int WareHouse::makeVolunteerId()
{
    int output = volunteerCounter;
    volunteerCounter++;
    return output;
}

int WareHouse::makeCustomerId()
{
    int output = customerCounter;
    customerCounter++;
    return output;
}

int WareHouse::makeOrderId()
{
    int output = orderCounter;
    orderCounter++;
    return output;
}

void WareHouse::close()
{
    isOpen = false;
}

void WareHouse::open()
{
    isOpen = true;
}

void WareHouse::addCustomer(Customer* customer)
{
    customers.push_back(customer);
}

void WareHouse::addOrder(Order* order)
{
    pendingOrders.push_back(order);
}

void WareHouse::addAction(BaseAction* action)
{
    actionsLog.push_back(action);
}

Customer& WareHouse::getCustomer(int customerId) const
{
    for(Customer* customer:customers)
    {
        if(customer->getId() == customerId)
        {
            return *customer;
        }
    }


    return this->getCustomer(-1); 
}

Volunteer& WareHouse::getVolunteer(int volunteerId) const
{
    for(Volunteer* volunteer:volunteers)
    {
        if(volunteer->getId() == volunteerId)
        {
            return *volunteer;
        }
    }
    return getVolunteer(-1); 
}

Order& WareHouse::getOrder(int orderId) const
{
    for(Order* order:pendingOrders)
    {
        if(order->getId() == orderId)
        {
            return *order;
        }
    }
    
    for(Order* order:inProcessOrders)
    {
        if(order->getId() == orderId)
        {
            return *order;
        }
    }

    for(Order* order:completedOrders)
    {
        if(order->getId() == orderId)
        {
            return *order;
        }
    }
    
    return getOrder(-1);

}

void WareHouse::addSoldier(int id, const string &name, int locationDistance, int maxOrders)
{
    addCustomer(new SoldierCustomer(id,name,locationDistance,maxOrders));
}

void WareHouse::addCivilian(int id, const string &name, int locationDistance, int maxOrders)
{
    addCustomer(new CivilianCustomer(id,name,locationDistance,maxOrders));
}

void WareHouse::addCollector(int id, const string &name, int coolDown)
{
    volunteers.push_back(new CollectorVolunteer(id,name,coolDown));
}

void WareHouse::addLimited_collector(int id, const string &name, int coolDown ,int maxOrders)
{
    volunteers.push_back(new LimitedCollectorVolunteer(id,name,coolDown,maxOrders));
}

void WareHouse::addDriver(int id, const string &name, int maxDistance, int distancePerStep)
{
    volunteers.push_back(new DriverVolunteer(id,name,maxDistance,distancePerStep));
}

void WareHouse::addLimited_driver(int id, const string &name, int maxDistance, int distancePerStep,int maxOrders)
{
    volunteers.push_back(new LimitedDriverVolunteer(id,name,maxDistance,distancePerStep,maxOrders));
}

void WareHouse::start()
{
    open();

    cout << "Warehouse is open!"<<endl;

    while(isOpen)
    {
        string input;

        getline(cin, input);
        
        istringstream iss(input);

        vector<string> comand;

        string comandSlice;

        string step = "step", order = "order", customer = "customer", orderStatus = "orderStatus", customerStatus = "customerStatus";

        while (iss >> comandSlice) 
        {
            comand.push_back(comandSlice);
        }

        string first= comand[0];

         

        if(first == step)
        {
            SimulateStep simulate(stoi(comand[1]));
            simulate.act(*this);
        }

        else if(first == order)
        {
            AddOrder order(stoi(comand[1]));
            order.act(*this);
        }

        else if(first == customer)
        {
            AddCustomer newCustomer(comand[1],comand[2],stoi(comand[3]),stoi(comand[4]));
            newCustomer.act(*this);
        }

        else if(first == orderStatus)
        {
            PrintOrderStatus status(stoi(comand[1]));
            status.act(*this);
        }

        else if(first == customerStatus)
        {
            PrintCustomerStatus status(stoi(comand[1]));
            status.act(*this);
        }

        else if(first == "volunteerStatus")
        {
            PrintVolunteerStatus status(stoi(comand[1]));
            status.act(*this);
        }

        else if(first == "log")
        {
            PrintActionsLog log;
            log.act(*this);
        }

        else if(first == "close")
        {
            Close close;
            close.act(*this);
        }

        else if(first == "backup")
        {
            BackupWareHouse backup;
            backup.act(*this);
        }

        else if(first == "restore")
        {
            RestoreWareHouse restore;
            restore.act(*this);
        }
        else
        {
            cout << "ERROR: ILLEGAL COMAND TRY AGAIN!" << endl;
        }
    }
}

WareHouse :: ~WareHouse()
{
    deleteAll();

}
WareHouse:: WareHouse(const WareHouse &other):
isOpen(other.isOpen),actionsLog(), volunteers() , pendingOrders(), inProcessOrders(), completedOrders(), customers(),customerCounter(other.customerCounter), volunteerCounter(other.volunteerCounter), orderCounter(other.orderCounter)
{

    for(BaseAction* action:other.actionsLog){
        actionsLog.push_back(action->clone());
    }
    for(Volunteer* v:other.volunteers)
    {
        volunteers.push_back(v->clone());
    }
    for(Customer* customer:other.customers)
    {
        customers.push_back(customer->clone());
    }
    for(Order* order:other.pendingOrders)
    {
        Order* toPush = new Order(*order);
        pendingOrders.push_back(toPush);
    }
    for(Order* order:other.inProcessOrders)
    {
        Order* toPush = new Order(*order);
        inProcessOrders.push_back(toPush);
    }
    for(Order* order:other.completedOrders)
    {
        Order* toPush = new Order(*order);
        completedOrders.push_back(toPush);
    }

}
WareHouse& WareHouse:: operator= (const WareHouse &other)
{
    if(&other != this){
        this->deleteAll();

        for(BaseAction* action:other.actionsLog)
        {
            actionsLog.push_back(action->clone());
        }
        for(Volunteer* v:other.volunteers)
        {
            volunteers.push_back(v->clone());
        }
        for(Customer* customer:other.customers)
        {
            customers.push_back(customer->clone());
        }
        for(Order* order:other.pendingOrders)
        {
            Order* toPush = new Order(*order);
            pendingOrders.push_back(toPush);
        }
        for(Order* order:other.inProcessOrders)
        {
            Order* toPush = new Order(*order);
            inProcessOrders.push_back(toPush);
        }
        for(Order* order:other.completedOrders)
        {
            Order* toPush = new Order(*order);
            completedOrders.push_back(toPush);
        }
        customerCounter = other.customerCounter;
        volunteerCounter = other.volunteerCounter;
        orderCounter = other.orderCounter;
    }

    return *this;
}
WareHouse ::WareHouse( WareHouse &&other):
isOpen(other.isOpen),actionsLog(other.actionsLog), volunteers(other.volunteers) , pendingOrders(other.pendingOrders), inProcessOrders(other.inProcessOrders), completedOrders(other.completedOrders), customers(other.customers),customerCounter(other.customerCounter), volunteerCounter(other.volunteerCounter), orderCounter(other.orderCounter)
{
    other.actionsLog.clear();
    other.volunteers.clear();
    other.pendingOrders.clear();
    other.inProcessOrders.clear();
    other.completedOrders.clear();
    other.customers.clear();
}
WareHouse& WareHouse :: operator= ( WareHouse &&other)
{
    if(&other != this){
        this->deleteAll();

        actionsLog = other.actionsLog;
        volunteers = other.volunteers;
        pendingOrders = other.pendingOrders;
        inProcessOrders = other.inProcessOrders;
        completedOrders = other.completedOrders;
        customers = other.customers;
        customerCounter = other.customerCounter;
        volunteerCounter = other.volunteerCounter;
        orderCounter = other.orderCounter;

        other.actionsLog.clear();
        other.volunteers.clear();
        other.pendingOrders.clear();
        other.inProcessOrders.clear();
        other.completedOrders.clear();
        other.customers.clear();
    }
    return *this;
}

void WareHouse::pushOrder(Order *order, int vec)
{
    if (vec == 1)
    {
        pendingOrders.push_back(order);
    }
    else if (vec == 2)
    {
        inProcessOrders.push_back(order);
    }
    else if (vec == 3)
    {
        completedOrders.push_back(order);
    }
}

void WareHouse::popOrder(Order *objectToremove, int vec)
{
    if (vec == 1)
    {
        pendingOrders.erase(std::remove(pendingOrders.begin(), pendingOrders.end(), objectToremove), pendingOrders.end());
    }
    else if (vec == 2)
    {
        inProcessOrders.erase(std::remove(inProcessOrders.begin(), inProcessOrders.end(), objectToremove), inProcessOrders.end());
    }
}

void WareHouse::popVolunteer(Volunteer *objectToremove)
{
    volunteers.erase(std::remove(volunteers.begin(), volunteers.end(), objectToremove), volunteers.end());
}
bool WareHouse::isOrderinProcessOrdersVector(Order& order) const
{
    return find(inProcessOrders.begin(), inProcessOrders.end(), &order) != inProcessOrders.end();

}


