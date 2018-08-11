#ifndef CONTROL_H
#define CONTROL_H

#include "allbills.hpp"
#include "bill.hpp"
#include "payer.hpp"
#include "item.hpp"

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include "int_fract.hpp"


class Control
{
public:
  Control();
  Bill *New_bill();
  void Rename_bill(Bill *bill, std::string name);
  void New_payer(std::string name);
  void New_item(Bill *bill);
  void Rename_item(Bill *bill, int index, std::string name);
  void Set_item_price(Bill *bill, int index, int cents);
  std::string Reprice_item(Bill *bill, int index, std::string price);
  std::string Reweight_item(Bill *bill, int item_index,
			    int weight_index, std::string weight);
  void Set_billpayer(std::string name, Bill *bill);
  std::vector<int_fract> Calculate();

  void Save(std::string savefilename);
  void Load(std::string loadfilename);

  std::vector<Payer*> Get_payers();
  std::vector<Bill*> Get_bills();

private:
  All_bills allbills;
  std::vector<int_fract> output;

  void Delete_everything();

};

#endif
