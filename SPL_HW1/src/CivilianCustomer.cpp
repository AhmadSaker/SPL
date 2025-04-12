#include "Customer.h"


CivilianCustomer::CivilianCustomer (int id, const string &name, int locationDistance, int maxOrders):
Customer(id,name,locationDistance,maxOrders){}


CivilianCustomer::CivilianCustomer (const CivilianCustomer& other):
Customer(other)
{}

CivilianCustomer::~CivilianCustomer(){}

CivilianCustomer* CivilianCustomer::clone() const
{
    CivilianCustomer* output = new CivilianCustomer(*this);
    return output;
}


