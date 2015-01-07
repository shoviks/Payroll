/*******************************************************
Filename: Payrecord.cpp
Author: Shovik Shyamsundar
Class: CSCI 1730
Project 2
******************************************************/
#include "Payrecord.h"
#include "POverloads.h"
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;
istream& operator>>(istream & is, Payrecord & record)
{
  string temp;
  vector<string> tokens;
  while (is >> temp)
    tokens.push_back(temp);
  
  record.setNet(atof(tokens.back().c_str()));
  tokens.pop_back();
  record.setTax(atof(tokens.back().c_str()));
  tokens.pop_back();
  record.setGross(atof(tokens.back().c_str()));
  return is;

}
ostream& operator<<(ostream & os, Payrecord & record)
{
  os.width(2);
  os <<  "Gross:     $\t" <<  record.getGross() << "\nTaxes:     $\t" << record.getTax() << right << "\nNet:       $\t" << record.getNet();
  return os;
}
Payrecord::Payrecord()
{
}
Payrecord::Payrecord(double g, double t, double n)
{
  gross = g;
  tax = t;
  net = n;
}
void Payrecord::setGross(double g)
{
  gross = g;
}
void Payrecord::setTax(double t)
{
  tax = t;
}
void Payrecord::setNet(double n)
{
  net = n;
}
double Payrecord::getGross() const
{
  return gross;
}
double Payrecord::getTax() const
{
  return tax;
}
double Payrecord::getNet() const
{
  return net;
}
