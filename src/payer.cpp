#include <string>
#include "payer.hpp"

Payer::Payer(std::string& new_name, int paid):
  name(new_name), total_paid(paid)
{
  to_pay = 0;
}

void Payer::Set_name(std::string& new_name)
{
  name = new_name;
}
std::string Payer::Get_name()
{
  return name;
}

void Payer::Set_paid(int paid)
{
  total_paid = paid;
}
int Payer::Get_paid()
{
  return total_paid;
}

void Payer::Set_topay(int new_topay)
{
  to_pay = new_topay;
}
int Payer::Get_topay()
{
  return to_pay;
}

int Payer::Add_topay(int addpay)
{
  to_pay += addpay;
  return to_pay;
}
