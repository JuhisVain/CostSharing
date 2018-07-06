#include <string>
#include "payer.hpp"
#include "bill.hpp"

Bill::Bill(std::string new_name, Payer payer):
  name(new_name), bill_payer(payer)
{
}

std::string Bill::Get_name()
{
  return name;
}

Payer Bill::Get_payer()
{
  return bill_payer;
}
