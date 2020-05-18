#include "pch.h"
#include "Customer.h"
#include "Movie.h"

Customer::Customer(const std::string & name)
{
	m_strName = name;
}


Customer::~Customer()
{
}

std::string Customer::getName()
{
	return m_strName;
}

void Customer::addRental(const Rental & arg)
{
	m_rentals.push_back(arg);
}

std::string Customer::statement()
{
	double totalAmount = 0;
	int frequentRenterPoints = 0;
	std::string result = "Rental record for " + getName() + "\n";
	for (auto & aRental : m_rentals)
	{
		//�������
		double thisAmount = 0;
		thisAmount = aRental.getCharge();
		//�������
		frequentRenterPoints += aRental.getFrequentRenterPoints();
		
		result += "\t" + aRental.getMovie().getTitle() + "\t" + convertToString(thisAmount) + "\n";
		totalAmount += thisAmount;
	}
	result += "Amount owed is " + convertToString(totalAmount) + "\n";
	result += "You earned " + convertToString(frequentRenterPoints) + " freuent renter points";
	
	return result;
}



