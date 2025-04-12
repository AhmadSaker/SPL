#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "readConfigFile.h"
#include "Order.h"
#include "Customer.h"
#include "Volunteer.h"
#include "Action.h"



class BaseAction;
class Volunteer;

// Warehouse responsible for Volunteers, Customers Actions, and Orders.


class WareHouse {

    public:
        WareHouse(const string &configFilePath);
        //rule of five
        ~WareHouse();
        WareHouse(const WareHouse &other);
        WareHouse& operator= (const WareHouse &other);
        WareHouse( WareHouse &&other);
        WareHouse& operator= ( WareHouse &&other);

        void start();
        void addOrder(Order* order);
        void addAction(BaseAction* action);
        Customer &getCustomer(int customerId) const;
        Volunteer &getVolunteer(int volunteerId) const;
        Order &getOrder(int orderId) const;
        const vector<BaseAction*> &getActions() const;
        void close();
        void open();
        void addCustomer(Customer* customer);
        vector<Volunteer*>& getvolunteers();
        vector<Order*>& getpendingOrders();
        vector<Order*>& getinProcessOrders();
        vector<Order*>& getcompletedOrders();
        vector<Customer*>& getcustomers();
        void deleteAll();
        int makeVolunteerId();
        int makeCustomerId();
        int makeOrderId();
        void pushOrder(Order *order, int vec);
        void popOrder(Order *objectToremove, int vec);
        void popVolunteer(Volunteer *objectToremove);
        bool isOrderinProcessOrdersVector(Order& order) const;
    


    private:
        bool isOpen;
        vector<BaseAction*> actionsLog;
        vector<Volunteer*> volunteers;
        vector<Order*> pendingOrders;
        vector<Order*> inProcessOrders;
        vector<Order*> completedOrders;
        vector<Customer*> customers;
        int customerCounter; //For assigning unique customer IDs
        int volunteerCounter; //For assigning unique volunteer IDs
        int orderCounter;//For assigning unique order IDs

        void addSoldier(int id, const string &name, int locationDistance, int maxOrders);
        void addCivilian(int id, const string &name, int locationDistance, int maxOrders);
        void addCollector(int id, const string &name, int coolDown);
        void addLimited_collector(int id, const string &name, int coolDown ,int maxOrders);
        void addDriver(int id, const string &name, int maxDistance, int distancePerStep);
        void addLimited_driver(int id, const string &name, int maxDistance, int distancePerStep,int maxOrders);
};