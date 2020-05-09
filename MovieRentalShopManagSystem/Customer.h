#pragma once

#include <iostream>
#include <vector>

#include "Rental.h"

class Customer
{
public:
	Customer(const std::string & name);
	~Customer();

	std::string getName();
	void addRental(const Rental & arg);
	std::string statement();
private:
	std::string m_strName;
	std::vector<Rental> m_rentals;
};

