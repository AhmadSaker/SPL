#include "Action.h"

BaseAction::BaseAction():errorMsg(""),status(){}

BaseAction::~BaseAction(){}

ActionStatus BaseAction :: getStatus() const
{
    return status;
}

void BaseAction::complete()
{
    enum ActionStatus completed = ActionStatus::COMPLETED;
    status = completed;
}

void BaseAction::error(string errorMsg)
{
    this->errorMsg= errorMsg;
    status = ActionStatus::ERROR;
}

string BaseAction::getErrorMsg() const
{
    string out = errorMsg;
    return out;
}
