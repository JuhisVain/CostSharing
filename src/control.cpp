#include "control.hpp"

Control::Control()
{
}

Bill *Control::New_bill()
{
  Bill *newbill = allbills.New_bill();
  return newbill;
}

void Control::Rename_bill(Bill *bill, std::string name)
{
  bill->Set_name(name);
}

Payer *Control::New_payer(std::string name)
{
  Payer *new_payer = allbills.New_payer(name);
  return new_payer;
}

void Control::New_item(Bill *bill)
{
  bill->New_item();
}

void Control::Rename_item(Bill *bill, int index, std::string name)
{
  bill->Get_item(index)->Set_name(name);
}

void Control::Set_item_price(Bill *bill, int index, int cents)
{
  bill->Get_item(index)->Set_price(cents);
}

//returns new price in large units as string
std::string Control::Reprice_item(Bill *bill, int index, std::string price)
{  
  int big_money=0, small_money=0;
  int *money_type = &big_money;
  int *counter = NULL;
  bool sm_ten_zero = false;
  
  //If no [,.] in string assume large units(euro/dollar etc.)
  //let's just assume everything that is not a number is some
  //type of dot
  //Let's only take the first 2 valid integers

  std::string::iterator striter = price.begin();

  for (int i = 0; i < price.length(); ++i) {

    int charint = (int)(*striter);
    std::cout << "charint=" << charint << std::endl
	      << "Smallmoney: "<< small_money << std::endl;

    if (charint >= '0' && charint <= '9') {

      //if we're looking at the first number after decimal point:
      if (counter && money_type == &small_money && money_type != counter) {
	counter = money_type;
	if (charint == '0') {
	  sm_ten_zero = true;
	} else {
	  *counter = 10 * (charint-'0');
	}
	std::cout << "first decimal: " << charint-'0' << std::endl;
	++striter;
	continue;
      } else if (money_type == &small_money && (sm_ten_zero || small_money)) { //Second decimal
	std::cout << "final decimal: " << charint-'0' << std::endl;
	small_money += (charint-'0');
	break;
      }
      
      counter = money_type;
      *counter = *counter*10 + charint-'0'; //Will fail if tens of small money zero

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

  std::cout << std::endl << "OVER, small money:" << small_money
	    << std::endl << "boolean: " << sm_ten_zero << std::endl;

  if (small_money < 10 && !sm_ten_zero) { // 123.1 == 123.10
    small_money *= 10;
  } else { // 123.123 == 123.12
    while (small_money > 99) small_money /= 10;
  }
    
    
  small_money += big_money*100;
  std::cout << "money calced" << std::endl;
  bill->Get_item(index)->Set_price(small_money);

  price = std::to_string(small_money);

  if (small_money < 100 && small_money > 9) {
    price = "0," + price;
  } else if (small_money < 10) {
    price = "0,0" + price;
  } else {
    price.insert(price.length()-2,",");
    //if (sm_ten_zero) price.insert(price.length()-2,"0");
  }

  std::cout << "prelim string price mod:"<<price<< std::endl;
  /*
  if (sm_ten_zero) {
    price.insert(price.length()-1,"0");
  }
  */
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

std::string Control::Get_billpayer(Bill *bill)
{
  return bill->Get_payer()->Get_name();
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

void Control::Save(std::string savefilename)
{
  std::ofstream savefile;
  savefile.open(savefilename, std::ofstream::out);

  /* savefilename.txt {
   * savefilename\n
   * [payer count]\n
   * [payer 0 name]\t[payer 1 name]\t...
   * [bill 0 name]\t[item count in bill 0]\n
   * [bill 0 payername]\n
   * [item 0 name]\t[item 0 price]\n
   * [item 0 weight 0]\t[item 0 weight 1]\t...\n
   * ...
   * [item count in bill 0+1]\n
   * ...
   * ...
   * }
   */

  std::vector<Payer*> payers = allbills.Get_payers();

  savefile << savefilename << "\n"
	   << payers.size() << "\n";

  for (int i = 0; i < payers.size(); ++i) {
    savefile << payers[i]->Get_name() << "\t";
  }
  savefile << "\n";

  std::vector<Bill*> bills = allbills.Get_bills();
  
  for (int bi = 0; bi < bills.size(); ++bi) {
    std::vector<Item> *items = bills[bi]->Get_items();
    savefile << bills[bi]->Get_name() << "\t"
	     << items->size() << "\n";
    savefile << bills[bi]->Get_payer()->Get_name() << "\n";

    for (int it = 0; it < items->size(); ++it) {
      std::cout << "it: " << it << " itemsize: " << items->size() << std::endl;
      savefile << (*items)[it].Get_name() << "\t"
	       << (*items)[it].Get_price() << "\n";
      std::vector<int> *weights = (*items)[it].Get_weights();

      for (int we = 0; we < weights->size(); ++we) {
	std::cout << "we: " << we << " weights.size: " << weights->size()
		  << " value: " << (*weights)[we] << std::endl;
	savefile << (*weights)[we] << "\t";
      }
      savefile << "\n" << std::endl;
    }
    
  }
  
  savefile.close();
}

void Control::Load(std::string loadfilename)
{

  std::cout << "Do payers NOT exist when they should exist? "
	    << allbills.No_payers() << std::endl;
  std::cout << "control load address allbills before delete: " << &allbills
	    << std::endl;
  
  Delete_everything();

  std::cout << "Do payers NOT exist after they should have been deleted? "
	    << allbills.No_payers() << std::endl;
  std::cout << "control load address allbills after delete: " << &allbills
	    << std::endl;
  
  std::ifstream loadfile;
  loadfile.open(loadfilename, std::ifstream::in);

  std::string filepath;
  loadfile >> filepath;
  std::cout << "loading " << filepath << std::endl;

  int payer_count = 0;
  loadfile >> payer_count;
  std::cout << "payer count according to file: " << payer_count << ", names: ";

  for (int i = 0; i < payer_count; ++i) {
    std::string payer_name;
    loadfile >> payer_name;
    std::cout << payer_name << ", ";
    New_payer(payer_name);
  }

  while (!loadfile.eof()) {
    std::string billname;
    loadfile >> billname;
    if (loadfile.eof()) break;
    std::cout << "Bill name: " << billname << std::endl;
    Bill *loaded_bill = New_bill();
    Rename_bill(loaded_bill, billname);

    int item_count = 0;
    loadfile >> item_count;
    std::cout << "Item count: " << item_count << std::endl;

    std::string bill_payer_name;
    loadfile >> bill_payer_name;
    std::cout << "Bill's payer: " << bill_payer_name << std::endl;
    Set_billpayer(bill_payer_name, loaded_bill);
    std::cout << "billpayer SET!" << std::endl;

    for(int i = 0; i < item_count; ++i) {

      New_item(loaded_bill);
      std::string item_name;
      loadfile >> item_name;
      std::cout << "item name: " << item_name << std::endl;;
      Rename_item(loaded_bill, i, item_name);

      std::cout << "item renamed!" << std::endl;
      
      int item_price;
      loadfile >> item_price;
      std::cout << ", " << item_price << " cents" << std::endl;
      /*
      std::string modprice = std::to_string(item_price);
      modprice.insert(modprice.size()-2,".");
      */
      Set_item_price(loaded_bill,i,item_price);
      //Reprice_item(loaded_bill, i, modprice);

      for (int payer_i = 0; payer_i < payer_count; ++payer_i) {
	int payer_weight = 0;
	loadfile >> payer_weight;
	Reweight_item(loaded_bill, i, payer_i, std::to_string(payer_weight));
      }
      
    }

  }
  
  
}

std::vector<Payer*> Control::Get_payers()
{
  return allbills.Get_payers();
}
std::vector<Bill*> Control::Get_bills()
{
  return allbills.Get_bills();
}

void Control::Delete_everything()
{

  std::cout << "Control::Delete_everything()" << std::endl;
  allbills.Delete_data();
  
  All_bills new_allbills;

  std::cout << "Address of old allbills: " << &allbills
	    << "Address of new allbills: " << &new_allbills << std::endl;
  
  allbills = new_allbills;
}
