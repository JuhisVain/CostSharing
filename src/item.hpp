#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include "int_fract.hpp"

class Item
{
public:
  explicit Item(int payer_count);
  void Set_name(std::string new_name);
  std::string Get_name();
  void Set_price(int new_price);
  
  int Get_price();
  void Set_weight(int index, int weight);
  int Get_weight(int index);
  std::vector<int> *Get_weights();
  std::vector<int_fract> *Get_shares();
  void resize_weights(int new_size);

private:
  std::string name;
  int price; //in cents
  std::vector<int> weights;

  std::vector<int_fract> *shares; //Used for deleting old data
  
};

#endif
