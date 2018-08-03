#ifndef INT_FRACT_H
#define INT_FRACT_H

#include <iostream>
#include <cmath>

class int_fract
{
public:
  int_fract();
  explicit int_fract(const int& init);
  int_fract operator*(const int number);
  int_fract operator/(int number);
  int_fract operator+(const int_fract& other);

  friend std::ostream &operator<<(std::ostream &output, const int_fract &infr);
  std::string To_string();

private:
  int wholes;
  int nominator;
  int denominator;

  void reduce();
  int_fract return_copy();

};



#endif
