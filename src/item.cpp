#include <string>
#include <iostream>
#include "item.hpp"

Item::Item(int payer_count)
{

  std::cout << "Creating item with param:" << payer_count << std::endl;
  
  name = "N/A";
  price = 0;

  std::cout << "weights size is " << weights.size() << std::endl;
  
  weights.resize(payer_count);

  std::cout << "weights resized to " << weights.size() << std::endl;

  for (int i = 0; i < payer_count; ++i) {
    std::cout << "i=" << i << std::endl;
    weights[i] = 0;
  }
  std::cout << "DONE" << std::endl;
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
    //tilt
  }
}

std::vector<int> *Item::Get_weights()
{
  return &weights;
}

void Item::resize_weights(int new_size)
{
  weights.resize(new_size);
}
