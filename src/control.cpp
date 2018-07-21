#include "control.hpp"

void Control::New_bill()
{
  allbills.New_bill(new Bill("Bill", NULL));
}

