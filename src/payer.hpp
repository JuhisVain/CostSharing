#ifndef PAYER_H
#define PAYER_H

#include <string>

class Payer
{
public:
  Payer();
  Payer(std::string& new_name, int paid);
  ~Payer();
  Payer(const Payer& tocopy);
  void Set_name(std::string& name);
  std::string Get_name();
  void Set_paid(int paid);
  void Add_paid(int add);
  int Get_paid();
  void Set_topay(int new_topay);
  int Get_topay();
  int Add_topay(int addpay);
  void Set_owed_to(int cents);
  void Add_to_owed_to(int cents);
  int Get_owed_to();

  void Balance_accounts();

  static int Get_total_payers();

  int Get_id();
  
private:
  std::string name;
  int id;
  static int total_payers;
  int total_paid; //Cents
  int to_pay;
  // int owed_to; //This is actually just a negative to_pay
  
};

#endif
