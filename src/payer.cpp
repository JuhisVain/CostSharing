#include <string>
#include <iostream>
#include "payer.hpp"

int Payer::total_payers = 0;

Payer::Payer()
{
  id = total_payers++;
  std::cout << "PAYER() Total payers is now " << total_payers << std::endl;
  name = "temp";
  total_paid = 0;
  to_pay = 0;
}

Payer::Payer(std::string& new_name, int paid):
  name(new_name), total_paid(paid)
{
  id = total_payers++;
  std::cout << "PAYER(NAME PAID)Total payers is now " << total_payers << std::endl;
  to_pay = 0;
}

Payer::~Payer()
{
  total_payers--;
  
  std::cout << "DESTROY Total payers is now " << total_payers << std::endl;
  std::cout << "Destroying " << name << std::endl;
}

Payer::Payer(const Payer& tocopy):
  name(tocopy.name), id(tocopy.id),
  total_paid(tocopy.total_paid), to_pay(tocopy.to_pay)
{
  std::cout << "COPY Total payers is now " << total_payers << std::endl;
  total_payers++;
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

void Payer::Add_paid(int add)
{
  total_paid += add;
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

int Payer::Get_total_payers()
{
  return total_payers;
}

int Payer::Get_id()
{
  return id;
}

void Payer::Set_owed_to(int cents)
{
  Set_topay(-cents);
  //owed_to = cents;
}
void Payer::Add_to_owed_to(int cents)
{
  Add_topay(-cents);
  //owed_to += cents;
}
int Payer::Get_owed_to()
{
  return -Get_topay();
  //return owed_to;
}

void Payer::Balance_accounts()
{
  
}
