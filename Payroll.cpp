/*******************************************************
Filename: Payroll.cpp
Author: Shovik Shyamsundar
Class: CSCI 1730
Project 2
******************************************************/
#include "Payroll.h"
#include <string.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <iostream>
#include "EOverloads.h"
#include "POverloads.h"
#include "Employee.h"
#include "Payrecord.h"


using namespace std;


Payroll::Payroll()
{
}
Payroll::Payroll(const Payroll & payroll)
{
  num_employees = payroll.num_employees;
  for (int i = 0; i < num_employees; i++)
    {
      employees[i] = payroll.employees[i];
    }
  for (int j = 0; j < num_employees; j++)
    {
      payrecords[j] = payroll.payrecords[j];
    }
}
void Payroll::readBatch()
{
  string fileName;
  string line;
  string workerInfo;				
  int firstLine;
  cout << "Enter in a batch file name: ";
  cin >> fileName;
  char seedfile[fileName.length()+1];
  strcpy(seedfile, fileName.c_str());
  ifstream infile(seedfile);
    
  num_employees = 0;
  stringstream ss;
  getline(infile, line);
  firstLine = atoi(line.c_str());
  
//Reads in each employee and creates a corresponding Employee and Payrecord object
  while(!infile.eof())
    {
      getline(infile, line);  
      ss << line;
      ss >> employees[num_employees];
      ss.clear();
      ss << getGross(employees[num_employees]) << " " << getTax(employees[num_employees]) << " " << getNet(employees[num_employees]);
      ss >> payrecords[num_employees];
      ss.clear();
      num_employees++;//increments number of employees for each Employee and Payrecord object created
    }
  if (firstLine != num_employees)
    {
      cout << endl;
      cout << "Warning: Number specified in first line of file does not match total number of employees listed in file." << endl;
    }
}
void Payroll::generateChecks()
{
  ofstream outputFile;
  string fileName;
  cout << "Enter a name for the output file (include filename extension \"txt\"): ";
  cin >> fileName;
  outputFile.open(fileName.c_str());

  outputFile << " Generating Checks" << endl << endl << endl << endl;
  for (int i = 0; i < num_employees; i++)
    {
      outputFile << employees[i] << endl << payrecords[i] << endl << endl;
    }
  outputFile.close();
}
void Payroll::generateReports()
{
  ofstream outputFile;
  string fileName;
  cout << "Enter a name for the output file (include filename extension \"txt\"): ";
  cin >> fileName;
  outputFile.open(fileName.c_str());
  
  
  outputFile << " Reports\n\n";
  Employee high = findHigh();
  outputFile << "Highest Earning Employee:\n";
  outputFile << high << endl << endl;
  Employee low = findLow();
  outputFile << "Lowest Earning Employee:" << endl;
  outputFile << low << endl << endl;
  outputFile << "Totals:" << endl;
  outputFile << "Total Gross Pay $ " << setprecision(2) << fixed << findTotalGross() << endl;
  outputFile << "Total Tax       $ " << setprecision(2) << fixed << findTotalTax() << endl;
  outputFile << "Total Net Pay   $ " << setprecision(2) << fixed << findTotalNet() << endl;
  outputFile << endl;
  outputFile << "Averages:" << endl;
  outputFile << "Average Gross Pay $ " << setprecision(2) << fixed << findAvgGross() << endl;
  outputFile << "Average Tax       $ " << setprecision(2) << fixed << findAvgTax() << endl;
  outputFile << "Average Net Pay   $ " << setprecision(2) << fixed << findAvgNet() << endl;

  outputFile.close();
}
double Payroll::getTax(const Employee & worker)
{
  return 0.15 * worker.getWage() * worker.getHours();
}
double Payroll::getNet(const Employee & worker)
{
  return 0.85 * worker.getWage() * worker.getHours();
}
double Payroll::getGross(const Employee & worker)
{
  return worker.getWage() * worker.getHours();
}
const Employee & Payroll::findHigh() const
{
  double high = 0;
  for (int i = 0; i < num_employees; i++)
    {
      if (high < getGross(employees[i]))
	high = getGross(employees[i]);
    }
  for (int j = 0; j < num_employees; j++)
    {
      if (high == getGross(employees[j]))
	{
	  return employees[j];
	}
    }
}
const Employee & Payroll::findLow() const
{
  double low = getGross(employees[0]);
  for (int i = 0; i < num_employees; i++)
    {
      if (low > getGross(employees[i]))
        low = getGross(employees[i]);
    }
  for (int j = 0; j < num_employees; j++)
    {
      if (low == getGross(employees[j]))
	{
	  return employees[j];
	}
    }
}
const double Payroll::findTotalGross() const
{
  double totalGross = 0;
  for (int i = 0; i < num_employees; i++)
    {
      totalGross += getGross(employees[i]);
    }
  return totalGross;
}
const double Payroll::findTotalTax() const
{
  double totalTax = 0;
  for (int i = 0; i < num_employees; i++)
    {
      totalTax += getTax(employees[i]);
    }
  return totalTax;
}
const double Payroll::findTotalNet() const
{
  double totalNet = 0;
  for (int i = 0; i < num_employees; i++)
    {
      totalNet += getNet(employees[i]);
    }
  return totalNet;
}
const double Payroll::findAvgGross() const
{
  return findTotalGross()/num_employees;
}
const double Payroll::findAvgTax() const
{
  return findTotalTax()/num_employees;
}
const double Payroll::findAvgNet() const
{
  return findTotalNet()/num_employees;
}
