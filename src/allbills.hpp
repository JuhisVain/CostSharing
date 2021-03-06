#ifndef ALLBILLS_H
#define ALLBILLS_H

#include <list>
#include <vector>
#include "payer.hpp"
#include "bill.hpp"
#include "int_fract.hpp"

class All_bills
{
public:
  All_bills();
  ~All_bills();
  
  Payer *New_payer();
  Payer *New_payer(std::string name);
  std::list<Payer>::iterator Get_payer_iterator();
  std::vector<Payer*> Get_payers();
  bool No_payers();
  
  Bill *New_bill();
  //std::list<Bill>::iterator Get_bill_iterator();
  std::vector<Bill*> Get_bills();

  std::vector<int_fract> Calculate();

  void Delete_data();

private:
  //These should prolly have been vectors
  std::list<Payer> payers;
  std::list<Bill> bills;

  int all_bills_total;

  void Resize_item_weights(int new_size);
  
};

#endif
