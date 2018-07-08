#ifndef ALLBILLS_H
#define ALLBILLS_H

#include <list>
#include "payer.hpp"
#include "bill.hpp"

struct All_bills
{
  std::list<Payer*> payers;
  std::list<Bill*> bills;
};

#endif
