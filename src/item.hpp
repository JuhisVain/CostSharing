#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

class Item
{
public:
  Item(int payer_count);
  void Set_name(std::string new_name);
  std::string Get_name();
  void Set_price(int new_price);
  int Get_price();
  void Set_weight(int index, int weight);

private:
  std::string name;
  int price; //in cents
  std::vector<int> weights;
  
};

#endif
