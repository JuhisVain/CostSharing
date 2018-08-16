#include <iostream>
#include <iomanip>
#include "allbills.hpp"

All_bills::All_bills()
{
  std::cout << "All_bills session START" << std::endl;
}

All_bills::~All_bills()
{
  //Should be obsolete. Not that these ever did anything.
  while (!payers.empty()) {
    payers.pop_back();
  }
  
}

Payer *All_bills::New_payer()
{
  payers.push_back(Payer());
  Resize_item_weights(Payer::Get_total_payers());
  return &(payers.back());
}

Payer *All_bills::New_payer(std::string name)
{
  payers.push_back(Payer(name, 0));
  Resize_item_weights(Payer::Get_total_payers());
  return &(payers.back());
}


std::list<Payer>::iterator All_bills::Get_payer_iterator()
{
  for (std::list<Payer>::iterator pit = payers.begin();
       pit != payers.end(); ++pit) {
  }
  return payers.begin();
}

std::vector<Payer*> All_bills::Get_payers()
{
  std::vector<Payer*> payer_vector;
  std::list<Payer>::iterator payer_iterator = Get_payer_iterator(); //?
  for (int i = 0; payer_iterator != payers.end(); ++i, ++payer_iterator) {
    payer_vector.push_back(&*payer_iterator);
  }

  return payer_vector;
}

bool All_bills::No_payers()
{
  return payers.empty();
}

Bill *All_bills::New_bill()
{
  Bill bill = Bill("Bill", NULL);
  bills.push_back(bill);
  return &(bills.back());
}

std::vector<Bill*> All_bills::Get_bills()
{
  std::vector<Bill*> bill_vector;
  std::list<Bill>::iterator bill_iterator = bills.begin();
  for (; bill_iterator != bills.end(); ++bill_iterator) {
    bill_vector.push_back(&*bill_iterator);
  }

  return bill_vector;
}

std::vector<int_fract> All_bills::Calculate()
{

  //Let's make sure payers' moneydata is initialized to 0:
  for (std::list<Payer>::iterator payer_iter = Get_payer_iterator();
       payer_iter != payers.end(); ++payer_iter) {
    payer_iter->Set_paid(0);
    payer_iter->Set_topay(int_fract(0));
  }

  all_bills_total = 0; // Reset total cost of everything

  for (std::list<Bill>::iterator bill_iter = bills.begin();
       bill_iter != bills.end(); ++bill_iter) {

    bill_iter->Reset_owed(); //In case we're recalculating

    std::cout << std::endl << bill_iter->Get_name() << ": "
	      << bill_iter->Get_total_price() << " cents"
	      << std::endl << "Paid by " << std::endl
	      << bill_iter->Get_payer()->Get_name()
	      << std::endl;

    all_bills_total += bill_iter->Get_total_price();

     //Total cost of bill added to billpayer's total paid:
    bill_iter->Update_payer_paid();

    std::vector<Item> *items = bill_iter->Get_items();
    std::vector<Payer*> payers_v = Get_payers();

    std::cout << std::setw(12);
    std::cout  << "item\\payer" << std::setw(12) << " ";
    for (int i = 0; i < payers_v.size(); ++i) {
      std::cout << std::setw(12) <<  payers_v[i]->Get_name();
    }
    
    for (int i = 0; i < items->size(); ++i) {

      std::cout << std::endl;
      std::cout << std::setw(12) << (*items)[i].Get_name()
		<< std::setw(12) << (*items)[i].Get_price();
      
      std::vector<int_fract> *shares = (*items)[i].Get_shares();
      for (int pi = 0; pi < payers_v.size(); ++pi) {
	
	bill_iter->Add_to_owed(payers_v[pi], (*shares)[pi]);

	std::cout << std::setw(12) << (*shares)[pi];
      }
    } 
  }

  std::cout << std::endl << std::setw(12) << " "
	    << std::setw(12) << all_bills_total;

  std::vector<int_fract> to_pays;
  to_pays.push_back(int_fract(all_bills_total));
  
  for (std::list<Payer>::iterator pit = payers.begin();
       pit != payers.end(); ++pit) {
    std::cout << std::setw(12) << pit->Get_topay();
    to_pays.push_back(pit->Get_topay());
  }

  std::cout << std::endl;
  return to_pays;
  
}

void All_bills::Resize_item_weights(int new_size)
{  
  for ( std::list<Bill>::iterator bill_iter = bills.begin();
	bill_iter != bills.end(); ++bill_iter) {

    std::vector<Item> *item_vector = bill_iter->Get_items();
    
    for (int i = 0; i < item_vector->size(); ++i) {
      std::cout << i;
      (*item_vector)[i].resize_weights(new_size);
    }
  }

  std::cout << std::endl;
}

//Should have apparently created everythin on stack. update: everything on stack
void All_bills::Delete_data()
{
  //Will not work on pointers
  payers.clear();
  bills.clear();
}
