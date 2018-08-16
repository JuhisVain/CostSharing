#include "int_fract.hpp"

int_fract::int_fract()
{
  wholes = 0;
  nominator = 0;
  denominator = 1;
}

int_fract::int_fract(const int& init)
{
  wholes = init;
  nominator = 0;
  denominator = 1;
}

int_fract int_fract::operator*(const int number)
{
  wholes *= number;
  nominator *= number;
  wholes += nominator/denominator; //todo: check what happens when <0
  nominator %= denominator;

  reduce();
  
  return return_copy();
}

int_fract int_fract::operator/(int number)
{
  if (number == 0) {
    std::cout << "Division by zero" << std::endl; //Weights total for item zero
    number = 1;
  }

  int remain = wholes % number;
  remain *= denominator;
  wholes /= number;
  int den_mem = denominator;
  denominator *= number;
  nominator *= number;
  number *= den_mem;

  nominator += remain;

  reduce();

  return return_copy();
}

int_fract int_fract::operator+(const int_fract& other)
{
  int_fract ret;
  ret.wholes = this->wholes + other.wholes;
  ret.nominator = this->nominator * other.denominator
    + this->denominator * other.nominator;
  ret.denominator = this->denominator * other.denominator;

  ret.wholes += ret.nominator / ret.denominator;
  ret.nominator = ret.nominator % ret.denominator;

  ret.reduce();
  return ret;
}

std::ostream &operator<<(std::ostream &output, const int_fract &infr)
{
  output << infr.wholes << " " << infr.nominator << "/" << infr.denominator;
  return output;
}

std::string int_fract::To_string()
{

  std::string text = std::to_string(wholes);

  int abs_wholes = std::abs(wholes);
  
  if (abs_wholes >= 100) { // Most likely
    text.insert(text.size()-2, ".");
  } else if (abs_wholes < 100 && abs_wholes >= 10) { //range 0.99 to 0.10
    if (wholes >= 0) {
      text.insert(0,"0."); // 98 -> 0.98
    } else {
      text.insert(1,"0."); // -98 -> -0.98
    }
  } else if (abs_wholes < 10) { //range 0.09 to 0.00
    if (wholes >= 0) {
      text.insert(0,"0.0"); // 7 -> 0.07
    } else {
      text.insert(1,"0.0"); // -7 -> -0.07
    }
  }

  //The fraction is always to be added into wholes
  if (nominator != 0) {
    text += " + [" + std::to_string(nominator) + "/"
      + std::to_string(denominator) + "]";
  }

  return text;
}

void int_fract::reduce()
{
  int div = nominator;
  int den = denominator;

  while (den != 0) {
    int temp = den;
    den = div % den;
    div = temp;
  }

  nominator /= div;
  denominator /= div;
}

int_fract int_fract::return_copy()
{
  int_fract ret;
  ret.wholes = this->wholes;
  ret.nominator = this->nominator;
  ret.denominator = this->denominator;
  return ret;
}
