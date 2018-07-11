#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

class Item
{
public:
  explicit Item(int payer_count);
  void Set_name(std::string new_name);
  std::string Get_name();
  void Set_price(int new_price);
  int Get_price();
  void Set_weight(int index, int weight);
  std::vector<int> *Get_weights();
  std::vector<int> Get_shares();
  void resize_weights(int new_size);

private:
  std::string name;
  int price; //in cents
  std::vector<int> weights;
  
};

#endif
