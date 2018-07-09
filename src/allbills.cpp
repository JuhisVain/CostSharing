#include "allbills.hpp"

All_bills::All_bills()
{
}

void All_bills::New_payer(Payer *new_payer)
{
  payers.push_back(new_payer);
}

std::list<Payer*>::iterator All_bills::Get_payer_iterator()
{
  return payers.begin();
}

std::vector<Payer*> All_bills::Get_payers()
{
  std::vector<Payer*> payer_vector;
  std::list<Payer*>::iterator payer_iterator = Get_payer_iterator();
  for (int i = 0; payer_iterator != payers.end(); ++i, ++payer_iterator) {
    payer_vector.push_back(*payer_iterator);
  }

  return payer_vector;
}


void All_bills::New_bill(Bill *new_bill)
{
  bills.push_back(new_bill);
}

std::list<Bill*>::iterator All_bills::Get_bill_iterator()
{
  return bills.begin();
}

std::vector<Bill*> All_bills::Get_bills()
{
  std::vector<Bill*> bill_vector;
  std::list<Bill*>::iterator bill_iterator = Get_bill_iterator();
  for (int i = 0; bill_iterator != bills.end(); ++i, ++bill_iterator) {
    bill_vector.push_back(*bill_iterator);
  }

  return bill_vector;
}
