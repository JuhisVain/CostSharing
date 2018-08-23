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

    if (charint >= '0' && charint <= '9') {

      //if we're looking at the first number after decimal point:
      if (counter && money_type == &small_money && money_type != counter) {
	counter = money_type;
	if (charint == '0') {
	  sm_ten_zero = true;
	} else {
	  *counter = 10 * (charint-'0');
	}
	++striter;
	continue;
      } else if (money_type == &small_money && (sm_ten_zero || small_money)) { //Second decimal
	small_money += (charint-'0');
	break;
      }
      counter = money_type;
      *counter = *counter*10 + charint-'0'; //Will fail if tens of small money zero; fixed with above if + bool
	
    } else if (counter == &big_money){
      money_type = &small_money;
    } else if (counter == &small_money) {
      break;
    }
    ++striter;
  }

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
  }
    
  return price;
}

std::string Control::Reweight_item(Bill *bill, int item_index,
			  int weight_index, std::string weight)
{
  int int_weight;
  try {
    int_weight = std::stoi(weight);
  } catch (std::invalid_argument const &inva) {
    int_weight = 1;
  }
  
  bill->Get_item(item_index)->Set_weight(weight_index, int_weight);
  
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
  output.clear();

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
    savefile << Sanitize(payers[i]->Get_name()) << "\t";
  }
  savefile << "\n";

  std::vector<Bill*> bills = allbills.Get_bills();
  
  for (int bi = 0; bi < bills.size(); ++bi) {
    std::vector<Item> *items = bills[bi]->Get_items();
    savefile << Sanitize(bills[bi]->Get_name()) << "\t"
	     << items->size() << "\n";
    savefile << Sanitize(bills[bi]->Get_payer()->Get_name()) << "\n";

    for (int it = 0; it < items->size(); ++it) {
      savefile << Sanitize((*items)[it].Get_name()) << "\t"
	       << (*items)[it].Get_price() << "\n";
      std::vector<int> *weights = (*items)[it].Get_weights();

      for (int we = 0; we < weights->size(); ++we) {
	savefile << (*weights)[we] << "\t";
      }
      savefile << "\n" << std::endl;
    }
    
  }
  
  savefile.close();
}

void Control::Load(std::string loadfilename)
{
  
  Delete_everything();
  
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
    New_payer(Soil(payer_name));
  }

  while (!loadfile.eof()) {
    std::string billname;
    loadfile >> billname;
    if (loadfile.eof()) break;
    std::cout << "Bill name: " << billname << std::endl;
    Bill *loaded_bill = New_bill();
    Rename_bill(loaded_bill, Soil(billname));

    int item_count = 0;
    loadfile >> item_count;
    std::cout << "Item count: " << item_count << std::endl;

    std::string bill_payer_name;
    loadfile >> bill_payer_name;
    std::cout << "Bill's payer: " << bill_payer_name << std::endl;
    Set_billpayer(Soil(bill_payer_name), loaded_bill);
    std::cout << "billpayer SET!" << std::endl;

    for(int i = 0; i < item_count; ++i) {

      New_item(loaded_bill);
      std::string item_name;
      loadfile >> item_name;
      std::cout << "item name: " << item_name << std::endl;;
      Rename_item(loaded_bill, i, Soil(item_name));
      
      int item_price;
      loadfile >> item_price;
      std::cout << ", " << item_price << " cents" << std::endl;

      Set_item_price(loaded_bill,i,item_price);

      for (int payer_i = 0; payer_i < payer_count; ++payer_i) {
	int payer_weight = 0;
	loadfile >> payer_weight;
	Reweight_item(loaded_bill, i, payer_i, std::to_string(payer_weight));
      }
    }
  }
}

//Transform everything unacceptable to '_'
std::string Control::Sanitize(std::string dirty)
{
  for (int i = 0; dirty[i] != 0; ++i) {
    if (dirty[i] < 33) {
      dirty[i] = '_';
    }
  }
  return dirty; //It's squeaky clean!
}

//All '_' to ' '
std::string Control::Soil(std::string clean)
{
  for (int i = 0; clean[i] != 0; ++i) {
    if (clean[i] == '_') {
      clean[i] = ' ';
    }
  }
  return clean;
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
  allbills.Delete_data();
  All_bills new_allbills;
  allbills = new_allbills;
}
