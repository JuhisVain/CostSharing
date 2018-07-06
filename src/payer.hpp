#ifndef PAYER_H
#define PAYER_H

#include <string>

class Payer
{
public:
  Payer();
  Payer(std::string& new_name, int paid);
  ~Payer();
  void Set_name(std::string& name);
  std::string Get_name();
  void Set_paid(int paid);
  int Get_paid();
  void Set_topay(int new_topay);
  int Get_topay();
  int Add_topay(int addpay);

  int Get_id();
  
private:
  std::string name;
  int id;
  static int total_payers;
  int total_paid; //Cents
  int to_pay;
  
};

#endif
