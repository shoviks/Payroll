/*******************************************************
Filename: POverloads.cpp
Author: Shovik Shyamsundar
Class: CSCI 1730
Project 2
******************************************************/
#ifndef POVERLOADS_H
#define POVERLOADS_H

#include "Payrecord.h"
#include <iostream>

using namespace std;

istream& operator>>(istream &, Payrecord &);
ostream& operator<<(ostream &, Payrecord &);

#endif
