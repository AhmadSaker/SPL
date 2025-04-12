#include "Action.h"
extern WareHouse* backup;

BackupWareHouse::BackupWareHouse():BaseAction()
{
}

BackupWareHouse::BackupWareHouse(const BackupWareHouse& other):BaseAction()
{
    if(other.getStatus()==ActionStatus::COMPLETED)
    {
        this->complete();
    }
}

BackupWareHouse* BackupWareHouse::clone() const
{
    return new BackupWareHouse(*this);
}

BackupWareHouse::~BackupWareHouse(){}

string BackupWareHouse::toString() const
{
    string output = "backup COMPELETED";
    return output;
}

void BackupWareHouse::act(WareHouse &wareHouse)
{
    if(backup!=nullptr){
    	delete backup;
    	backup = nullptr;
    }
    complete();
    backup = new WareHouse(wareHouse);
    wareHouse.addAction(this->clone());
}
