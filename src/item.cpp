#include <string>
#include <iostream>
#include "item.hpp"

Item::Item(int payer_count)
{
  name = "N/A";
  price = 0;

  shares = NULL;
  
  weights.resize(payer_count);

  for (int i = 0; i < payer_count; ++i) {
    std::cout << "i=" << i << std::endl;
    weights[i] = 0;
  }
}

void Item::Set_name(std::string new_name)
{
  name = new_name;
}

std::string Item::Get_name()
{
  return name;
}

void Item::Set_price(int new_price)
{
  price = new_price;
}

int Item::Get_price()
{
  return price;
}

void Item::Set_weight(int index, int weight)
{
  
  if (index < weights.size() && index >= 0) {
    weights[index] = weight;
  } else {
    std::cout << "item set weight index error" << std::endl;
    //tilt
  }
}

int Item::Get_weight(int index)
{
  return weights[index];
}

std::vector<int> *Item::Get_weights()
{
  return &weights;
}


std::vector<int_fract> *Item::Get_shares() 
{
  //weight * price / weighttotal = weighted price:
  //std::vector<int> shares(weights); //copy
  if (shares) {
    delete shares;
    shares = NULL;
  }
  
  shares = new std::vector<int_fract>;
  for (int i = 0; i < weights.size(); ++i) {
    shares->push_back(int_fract(weights[i]));
  }
  
  int weight_total = 0;
  for(int i = 0; i < shares->size(); ++i) {
    weight_total += weights[i];
    int_fract *if_p = &(*shares)[i];
    (*shares)[i] = (*if_p * price);
  }
  for (int i = 0; i < shares->size(); ++i) {
    int_fract *if_p = &(*shares)[i];
    (*shares)[i] = (*if_p / weight_total);
  }
  return shares;
}

void Item::resize_weights(int new_size)
{
  weights.resize(new_size);
}
