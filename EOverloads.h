/*******************************************************
Filename: EOverloads.cpp
Author: Shovik Shyamsundar
Class: CSCI 1730
Project 2
******************************************************/
#ifndef EOVERLOADS_H
#define EOVERLOADS_H

#include "Employee.h"
#include <iostream>

using namespace std;

istream& operator>>(istream &, Employee &);
ostream& operator<<(ostream &, Employee &);

#endif
