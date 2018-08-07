#include "control.hpp"

Control::Control()
{
  std::cout << "Control CONSTRUCTOR at address: " << (Control *)this << std::endl;
}

Bill *Control::New_bill()
{
  std::cout << "Control::New_bill()" << std::endl;

  Bill *newbill = new Bill("Bill", NULL);
  allbills.New_bill(newbill);
  return allbills.Get_bills().back();
}

void Control::Rename_bill(Bill *bill, std::string name)
{
  std::cout << "Control::Rename_bill(x,"<< name <<")"
	    << "old was: " << bill->Get_name() << std::endl;
  bill->Set_name(name);
}

void Control::New_payer(std::string name)
{
  std::cout << "Control::New_payer(" << name << ")" << std::endl;
  
  Payer *new_payer = new Payer();
  new_payer->Set_name(name);
  allbills.New_payer(new_payer);
}

void Control::New_item(Bill *bill)
{
  std::cout << "Control::New_item()" << std::endl;
  
  bill->New_item();
}

void Control::Rename_item(Bill *bill, int index, std::string name)
{
  std::cout << "Rename item, row:" << index
	    << " Old name:" << bill->Get_item(index)->Get_name()
	    << " new name:" << name << std::endl;

  bill->Get_item(index)->Set_name(name);
}

//return new price in large units as string
std::string Control::Reprice_item(Bill *bill, int index, std::string price)
{
  std::cout << "Reprice item, row:" << index
	    << " Old price:" << bill->Get_item(index)->Get_price()
	    << " new price:" << price << std::endl;
  
  int big_money=0, small_money=0;
  int *money_type = &big_money;
  int *counter = NULL;
  
  //If no [,.] in string assume large units(euro/dollar etc.)
  //let's just assume everything that is not a number is some
  //type of dot
  //Let's only take the first 2 valid integers

  std::string::iterator striter = price.begin();

  for (int i = 0; i < price.length(); ++i) {

    int charint = (int)(*striter);
    std::cout << "charint=" << charint << std::endl;

    if (charint >= '0' && charint <= '9') {

      counter = money_type;
      *counter = *counter*10 + charint-'0';

      std::cout << "*c:" << *counter << ",";
	
    } else if (counter == &big_money){
      money_type = &small_money;

      std::cout << std::endl << "CHANGE" << std::endl;
	
    } else if (counter == &small_money) {

      std::cout << "BIG and SMALL calced" << std::endl;
	
      break;
    }
    ++striter;
      
  }

  std::cout << std::endl << "OVER" << std::endl;

  if (small_money < 10) { // 123.1 == 123.10
    small_money *= 10;
  } else { // 123.123 == 123.12
    while (small_money > 99) small_money /= 10;
  }
    
    
  small_money += big_money*100;
  std::cout << "money calced" << std::endl;
  bill->Get_item(index)->Set_price(small_money);

  std::cout << "model price set" << std::endl;

  price = std::to_string(small_money);

  std::cout << "string price set:"<<price<< std::endl;

  if (small_money == 0) {
    price += ",00";
  } else if (small_money < 100) {
    price = "0," +price;
  } else {
    price.insert(price.length()-2,",");
  }

  std::cout << "string price mod:"<<price<< std::endl;
    
  return price;
}

std::string Control::Reweight_item(Bill *bill, int item_index,
			  int weight_index, std::string weight)
{

  std::cout << "Reweight_item called with ii:" << item_index
	    << " wi:" << weight_index << " & " << weight << std::endl;

  int int_weight;
  try {
    int_weight = std::stoi(weight);
  } catch (std::invalid_argument const &inva) {
    int_weight = 1;
  }

  std::cout << "int weight:" << int_weight << std::endl;
  std::cout << "debug:" << std::endl;
  std::cout << "Bill name: " << bill->Get_name() << std::endl;
  std::cout << "item name: " << bill->Get_item(item_index)->Get_name() <<std::endl;
  
  bill->Get_item(item_index)->Set_weight(weight_index, int_weight);

  std::cout << "weight set" << std::endl;

  std::cout << "New weight for " << bill->Get_item(item_index)->Get_name() << std::endl;
  std::cout    << " = " << bill->Get_item(item_index)->Get_weight(weight_index) << std::endl;
  
  return (std::to_string(bill->Get_item(item_index)->Get_weight(weight_index)));
}

void Control::Set_billpayer(std::string name, Bill *bill)
{
  std::vector<Payer*> payers = allbills.Get_payers();

  for (int i = 0; i < payers.size(); ++i) {
    if (payers[i]->Get_name() == name) {
      bill->Set_payer(payers[i]);
      return;
    }
  }

  std::cout << "No " << name << " for "
	    << bill->Get_name() << " found in payers"
	    << std::endl;
  
}

std::vector<int_fract> Control::Calculate()
{
  std::cout << "control clears vector" << std::endl;
  
  output.clear();
  std::cout << "cleared" << std::endl;

  if (allbills.No_payers()) {
    std::cout << "No payers found!" << std::endl;
    return output;
  }

  output = allbills.Calculate();
  return output;
}

void Control::Save()
{
  std::ofstream savefile;
  savefile.open("");
}
