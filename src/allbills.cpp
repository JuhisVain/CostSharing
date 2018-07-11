#include <iostream>
#include <iomanip>
#include "allbills.hpp"

All_bills::All_bills()
{
}

void All_bills::New_payer(Payer *new_payer)
{
  payers.push_back(new_payer);

  Resize_item_weights(Payer::Get_total_payers());
  
}

std::list<Payer*>::iterator All_bills::Get_payer_iterator()
{
  return payers.begin();
}

std::vector<Payer*> All_bills::Get_payers()
{
  std::vector<Payer*> payer_vector;
  std::list<Payer*>::iterator payer_iterator = Get_payer_iterator(); //?
  for (int i = 0; payer_iterator != payers.end(); ++i, ++payer_iterator) {
    payer_vector.push_back(*payer_iterator);
  }

  return payer_vector;
}


void All_bills::New_bill(Bill *new_bill)
{
  bills.push_back(new_bill);
}

std::list<Bill*>::iterator All_bills::Get_bill_iterator()
{
  return bills.begin();
}

std::vector<Bill*> All_bills::Get_bills()
{
  std::vector<Bill*> bill_vector;
  std::list<Bill*>::iterator bill_iterator = Get_bill_iterator();
  for (int i = 0; bill_iterator != bills.end(); ++i, ++bill_iterator) {
    bill_vector.push_back(*bill_iterator);
  }

  return bill_vector;
}

void All_bills::Calculate()
{

  //Let's make sure payers' moneydata is initialized to 0:
  for (std::list<Payer*>::iterator payer_iter = payers.begin();
       payer_iter != payers.end(); ++payer_iter) {

    if ( (*payer_iter)->Get_paid() ) std::cout << "DEBUG-total paid not 0" << std::endl;
    if ( (*payer_iter)->Get_topay() ) std::cout << "DEBUG-to pay not 0" << std::endl;

    (*payer_iter)->Set_paid(0);
    (*payer_iter)->Set_topay(0);

  }

  for (std::list<Bill*>::iterator bill_iter = bills.begin();
       bill_iter != bills.end(); ++bill_iter) {

    std::cout << std::endl << (*bill_iter)->Get_name() << ": "
	      << (*bill_iter)->Get_total_price() << " cents"
	      << std::endl << "Paid by "
	      << (*bill_iter)->Get_payer()->Get_name()
	      << std::endl;

     //Total cost of bill added to billpayer's total paid:
    (*bill_iter)->Update_payer_paid();
    
    std::vector<Item*> items = (*bill_iter)->Get_items();
    std::vector<Payer*> payers_v = Get_payers();

    std::cout << std::setw(12);
    std::cout  << "item\\payer" << std::setw(12) << " ";
    for (int i = 0; i < payers_v.size(); ++i) {
      std::cout << std::setw(12) <<  payers_v[i]->Get_name();
    }
    
    for (int i = 0; i < items.size(); ++i) {

      std::cout << std::endl;
      std::cout << std::setw(12) << items[i]->Get_name()
		<< std::setw(12) << items[i]->Get_price();
      
      std::vector<int> shares = items[i]->Get_shares();
      for (int pi = 0; pi < payers_v.size(); ++pi) {
	payers_v[pi]->Add_topay(shares[pi]);

	std::cout << std::setw(12) << shares[pi];
      }
    } 
  }

  std::cout << std::endl << std::setw(12) << " "
	    << std::setw(12) << "totalhere";
  for (std::list<Payer*>::iterator pit = payers.begin();
       pit != payers.end(); ++pit) {
    std::cout << std::setw(12) << (*pit)->Get_topay();
  }

  std::cout << std::endl;
  
}

void All_bills::Resize_item_weights(int new_size)
{

  for ( std::list<Bill*>::iterator bill_iter = Get_bill_iterator();
	bill_iter != bills.end(); ++bill_iter) {
    
    std::vector<Item*> item_vector = (*bill_iter)->Get_items();
    
    for (int i = 0; i < item_vector.size(); ++i) {
      item_vector[i]->resize_weights(new_size);
    }
  }
}