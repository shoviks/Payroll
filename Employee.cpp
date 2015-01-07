/*******************************************************
Filename: Employee.cpp
Author: Shovik Shyamsundar
Class: CSCI 1730
Project 2
******************************************************/
#include "Employee.h"
#include "EOverloads.h"
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

istream& operator>>(istream & is, Employee & worker)
{
  string temp;
  char nm[1024];
  vector<string> tokens;
  while (is >> temp)
    tokens.push_back(temp);
  
  worker.setWage(atof(tokens.back().c_str()));
  tokens.pop_back();
  worker.setHours(atof(tokens.back().c_str()));
  tokens.pop_back();
  strcpy(nm, tokens.front().c_str());
  worker.setName(nm);
  return is;
}
ostream& operator<<(ostream & os, Employee & worker)
{
  os << worker.getName() << " worked " <<  setprecision(2) << fixed << worker.getHours() << " hours at $" << setprecision(2) << fixed << worker.getWage() << " per hour";
  return os;
}
Employee::Employee()
{
}
Employee::Employee(char * n, double h, double w)
{
  strcpy(name, n);
  hours = h;
  wage = w;
}
const char * Employee::getName() const
{
  return name;
}
void Employee::setName(char n[])
{
  strcpy(name, n);
}
double Employee::getHours() const
{
  return hours;
}
void Employee::setHours(double h)
{
  hours = h;
}
double Employee::getWage() const
{
  return wage;
}
void Employee::setWage(double w)
{
  wage = w;
}
