#include "Action.h"
#include <iostream>
using namespace std;

PrintActionsLog::PrintActionsLog():BaseAction()
{
    complete();
}
PrintActionsLog::~PrintActionsLog(){}

void PrintActionsLog::act(WareHouse &wareHouse)
{
    vector<BaseAction*> actions = wareHouse.getActions();
    for(BaseAction* action:actions)
    {
        cout<<action->toString()<<endl;
    }
    PrintActionsLog* tmp = this->clone();
    wareHouse.addAction(tmp);
}

PrintActionsLog* PrintActionsLog::clone() const
{
    return new PrintActionsLog();
}
string PrintActionsLog::toString() const
{
    string output = "log COMPLETED";
    return output;
}
