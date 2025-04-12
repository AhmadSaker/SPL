#pragma once
#include <string>
#include <vector>
#include "WareHouse.h"
using std::string;
using std::vector;

enum class ActionStatus{
    COMPLETED, ERROR
};

enum class CustomerType{
    Soldier, Civilian
};

class WareHouse;

class BaseAction{
    public:
        BaseAction();
        virtual ~BaseAction();
        ActionStatus getStatus() const;
        virtual void act(WareHouse& wareHouse)=0;
        virtual string toString() const=0;
        virtual BaseAction* clone() const=0;

    protected:
        void complete();
        void error(string errorMsg);
        string getErrorMsg() const;

    private:
        string errorMsg;
        ActionStatus status;
};

class SimulateStep : public BaseAction {

    public:
        SimulateStep(int numOfSteps);
        ~SimulateStep();
        SimulateStep(const SimulateStep& other);
        int getNumOfSteps() const;
        void act(WareHouse &wareHouse) override;
        std::string toString() const override;
        SimulateStep *clone() const override;

    private:
        const int numOfSteps;
};

class AddOrder : public BaseAction {
    public:
        AddOrder(int id);
        AddOrder(const AddOrder& other);
        ~AddOrder();
        void act(WareHouse &wareHouse) override;
        string toString() const override;
        AddOrder *clone() const override;
        int getCustomerId() const;
    private:
        const int customerId;
};


class AddCustomer : public BaseAction {
    public:
        AddCustomer(const string& customerName, const string& customerType, int distance, int maxOrders);
        AddCustomer(const AddCustomer& other);
        ~AddCustomer();
        int getCustomerId() const;
        void act(WareHouse &wareHouse) override;
        AddCustomer *clone() const override;
        string toString() const override;
        string getCustomerName() const;
        CustomerType getCustomerType() const;
        int getDistance() const;
        int getMaxOrders() const;
    private:
        CustomerType stringToCustomerType(string customerType) const;
        string CustomerTypeToString() const;
        const string customerName;
        const CustomerType customerType;
        const int distance;
        const int maxOrders;
};



class PrintOrderStatus : public BaseAction {
    public:
        PrintOrderStatus(int id);
        ~PrintOrderStatus();
        PrintOrderStatus(const PrintOrderStatus&other);
        int getOrderId() const;
        void act(WareHouse &wareHouse) override;
        PrintOrderStatus *clone() const override;
        string toString() const override;
    private:
        const int orderId;
};

class PrintCustomerStatus: public BaseAction {
    public:
        PrintCustomerStatus(int customerId);
        ~PrintCustomerStatus();
        PrintCustomerStatus(const PrintCustomerStatus& other);
        void act(WareHouse &wareHouse) override;
        PrintCustomerStatus *clone() const override;
        string toString() const override;
        int getCustomerId() const;
    private:
        const int customerId;
};


class PrintVolunteerStatus : public BaseAction {
    public:
        PrintVolunteerStatus(int id);
        ~PrintVolunteerStatus();
        PrintVolunteerStatus(const PrintVolunteerStatus& other);
        int getVolunteerId() const;
        void act(WareHouse &wareHouse) override;
        PrintVolunteerStatus *clone() const override;
        string toString() const override;
    private:
        const int volunteerId;
};


class PrintActionsLog : public BaseAction {
    public:
        PrintActionsLog();
        ~PrintActionsLog();
        void act(WareHouse &wareHouse) override;
        PrintActionsLog *clone() const override;
        string toString() const override;
    private:
};

class Close : public BaseAction {
    public:
        Close();
        ~Close();
        void act(WareHouse &wareHouse) override;
        Close *clone() const override;
        string toString() const override;
    private:
};

class BackupWareHouse : public BaseAction {
    public:
        BackupWareHouse();
        ~BackupWareHouse();
        BackupWareHouse(const BackupWareHouse& other);
        void act(WareHouse &wareHouse) override;
        BackupWareHouse *clone() const override;
        string toString() const override;
    private:
};


class RestoreWareHouse : public BaseAction {
    public:
        RestoreWareHouse();
        RestoreWareHouse(const RestoreWareHouse& other);
        ~RestoreWareHouse();
        void act(WareHouse &wareHouse) override;
        RestoreWareHouse *clone() const override;
        string toString() const override;
    private:
};