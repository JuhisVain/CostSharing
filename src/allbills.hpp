#ifndef ALLBILLS_H
#define ALLBILLS_H

#include <list>
#include <vector>
#include "payer.hpp"
#include "bill.hpp"

class All_bills
{
public:
  All_bills();
  
  void New_payer(Payer *new_payer);
  std::list<Payer*>::iterator Get_payer_iterator();
  std::vector<Payer*> Get_payers();
  
  void New_bill(Bill *new_bill);
  std::list<Bill*>::iterator Get_bill_iterator();
  std::vector<Bill*> Get_bills();

  std::vector<int> Calculate();

private:
  //These should prolly have been vectors
  std::list<Payer*> payers;
  std::list<Bill*> bills;

  int all_bills_total;

  void Resize_item_weights(int new_size);
  
};

#endif
